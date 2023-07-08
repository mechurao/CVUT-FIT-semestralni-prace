//
// Created by Ondřej Měchura on 23.03.2023.
//

#include "World.h"

using namespace std;

World::World() {
    this->initWorld();
}

World::World(bool & res, string& worldSrc, string & mobsSrc){
    bool worldRes = WorldLoader::loadWorld(*this, worldSrc);
    bool mobsRes = WorldLoader::loadMobs(*this, mobsSrc);
    res = (worldRes && mobsRes);
}


void World::initWorld() {

    // generate world
    int width = Cache::default_world_width;
    int half = width / 2;
    int leftFalf = half * (-1);
    for (int i = leftFalf; i <= half; i++) {
        this->chunks.insert({i, WorldGenerator::getChunk()});
    }


    int surfaceBlocks = Cache::default_world_width;
    int mobsCount = surfaceBlocks / 10;

    // spawn mobs
    for (int i = 0; i < mobsCount; i++) {
        int pos = RandomGenerator::getFromInterval(leftFalf, half);
        auto entity = RandomGenerator::pickEntity()->Clone();
        this->spawnEntity(pos,entity);
    }
}



void World::spawnEntity(int x,const shared_ptr<Entity>& entity) {
    auto chunk = this->chunks.find(x);
    if(chunk == this->chunks.end()){ return;}
    entity->spawn(this,chunk,0);
    this->entities.push_back(entity);
}




Player* World::spawnPlayer() {
    int x = RandomGenerator::getFromInterval(this->chunks.begin()->first, prev(this->chunks.end())->first);
    auto it = this->chunks.find(x);
    this->player = new Player();
    this->player->spawn(this, it,0);
    this->initiated = true;
    return this->player;
}

Player* World::spawnPlayer(int x, int y) {
    auto target = this->chunks.find(x);
    if(target == this->chunks.end()){ return nullptr;} // target not found
    if(((int)target->second->content.size() <= y)){ return nullptr;}
    this->player = new Player();
    this->player->spawn(this, target,y);
    this->initiated = true;
    return this->player;
}

void World::switchDayPhase() {
    if(this->phase == DayPhase::day){
        this->phase = DayPhase::night;
        return;
    }
    this->phase = DayPhase::day;
}

DayPhase World::getPhase() const {
    return this->phase;
}



int World::freeFall( Entity* entity) const {
    if(entity->currentChunk->second->content[entity->y+1]->isCrossable()){
        for(int  i = entity->y; i < (int)entity->currentChunk->second->content.size();i++){
            if(!entity->currentChunk->second->content[i+1]->isCrossable()){

                entity->currentChunk->second->content[entity->y]->leave();
                int fallHeight = i - entity->y;
                entity->y = i;

                entity->currentChunk->second->content[entity->y]->visit(entity);

                if(this->initiated){
                    if(fallHeight > Cache::fall_damage_height){
                        int damage = fallHeight - Cache::fall_damage_height;
                        entity->hurt(damage);
                        if (entity->isDead()) {
                            entity->death = make_shared<FallDeath>();
                        }
                    }
                }
                return  fallHeight;
            }
        }
    }

    return 0;
}




void World::moveRight(Entity* entity) {
    if(!entity->isActive(this->phase)){ return;}

    if(next(entity->currentChunk) == this->chunks.end()){return;}
    if(next(entity->currentChunk)->second->content[entity->y]->isCrossable()){
        entity->currentChunk->second->content[entity->y]->leave();
        entity->currentChunk++;
        entity->currentChunk->second->content[entity->y]->visit(entity);

        if(entity->jumpTimer->running()){ return;}
        this->freeFall(entity);
    }
}

void World::moveLeft(Entity* entity) {
    if(!entity->isActive(this->phase)){ return;}
    if(entity->currentChunk == this->chunks.begin()){ return;}
    if(prev(entity->currentChunk)->second->content[entity->y]->isCrossable()){
        entity->currentChunk->second->content[entity->y]->leave();
        entity->currentChunk--;
        entity->currentChunk->second->content[entity->y]->visit(entity);
        if(entity->jumpTimer->running()){ return;}
        this->freeFall(entity);
    }
}




void World::moveUp(Entity* entity) {
    if(entity == nullptr || entity->jumpTimer == nullptr ||
       entity->currentChunk->second == nullptr ) {
        return;  // One of the pointers is null, so we cannot proceed
    }
    if(!entity->isActive(this->phase)){ return;}

    if(entity->jumpTimer->running()){ return;}

    // get jump height
    int maxJumpHeight = (entity->y - Cache::jump_height >= 0) ? Cache::jump_height : entity->y;
    int finalJumpHeight = maxJumpHeight;

    // get distance to nearest no crossable block
    for(int i = entity->y - 1; i >= (entity->y - maxJumpHeight); i--){
        if(i < 0 || i >= (int)entity->currentChunk->second->content.size()) {
            break;  // Index is out of range
        }
        if(!entity->currentChunk->second->content[i]->isCrossable()){
            finalJumpHeight = entity->y - i - 1;
            break;
        }
    }

    // find target y coordinate
    int jumpY = entity->y - finalJumpHeight;

    if(entity->y >= 0 && entity->y < (int)entity->currentChunk->second->content.size()) {
        entity->currentChunk->second->content[entity->y]->leave();
    }

    entity->y = jumpY;

    if(entity->y >= 0 && entity->y < (int)entity->currentChunk->second->content.size()) {
        entity->currentChunk->second->content[entity->y]->visit(entity);
    }

    entity->jumpTimer->start();
}




void World::build(int itemID, MoveDirection direction) {
    auto targetOpt = getTarget(this->player, direction);

    if (!targetOpt.has_value()) { return;  }
        std::shared_ptr<Item>& target = targetOpt.value().get();
        target.reset();
        target = Cache::itemsMap[itemID]->Clone();
}

void World::destroy(MoveDirection direction) {
    auto targetOpt = getTarget(this->player, direction);

    if (!targetOpt.has_value()) { return;}
        std::shared_ptr<Item>& target = targetOpt.value().get();
        target = make_shared<Air>();

        // update affected chunk
    switch (direction) {
        case MoveDirection::right:{
            if(next(this->player->currentChunk) == this->chunks.end()){ return;}
            this->updateChunkContent(next(this->player->currentChunk)->second);
            return;
        }

        case MoveDirection::left:{
            if(this->player->currentChunk == this->chunks.begin()){ return;}
            this->updateChunkContent(prev(this->player->currentChunk)->second);
            return;
        }

        default:{
            this->updateChunkContent(this->player->currentChunk->second);
            return;
        }
    }
}


optional<reference_wrapper<shared_ptr<Item>>> World::getTarget( Player*& player, MoveDirection direction) const {

    if (direction == MoveDirection::left) {
        if (player->currentChunk == this->chunks.begin()) {
            return nullopt;
        }
    }

    if (direction == MoveDirection::right) {
        if (next(player->currentChunk) == this->chunks.end()) {
            return nullopt;
        }
    }

    switch (direction) {
        case MoveDirection::up: {
            return player->currentChunk->second->content[player->y - 1];
        }
        case MoveDirection::down: {
            return player->currentChunk->second->content[player->y + 1];
        }
        case MoveDirection::right: {
            return next(player->currentChunk)->second->content[player->y];
        }
        case MoveDirection::left: {
            return prev(player->currentChunk)->second->content[player->y];
        }
    }
    return nullopt;
}

void World::updateChunkContent(shared_ptr<Chunk> &target) const {

    for(auto &i : target->content){
        if(i->getSpawnedEntity() != nullptr){
            if(!i->getSpawnedEntity()->jumpTimer->running()){
                freeFall(i->getSpawnedEntity());
            }
        }
    }
}



string World::toString() {
    string result;
    for(auto &p : this->chunks){
        result+= to_string(p.first);
        result+=THERNARY_DELIMETER;
        result+=p.second->toString();
        result+=SECONDARY_DELIMETER;
    }
    return result;
}

vector<std::shared_ptr<Entity>> World::getEntities()  {
    vector<shared_ptr<Entity>> aliveMobs;
    for(const auto &m : this->entities){
        if(!m->isDead()){aliveMobs.push_back(m);}
    }
    return aliveMobs;
}



string World::entitiesToString() {
   string content;
   for(auto &e : this->entities){
       content+=e->toString();
       content+=SECONDARY_DELIMETER;
   }
    return content;
}


World::~World() {
    // delete entities

    this->entities.clear();

    this->chunks.clear();

    // delete player
    delete this->player;
}













