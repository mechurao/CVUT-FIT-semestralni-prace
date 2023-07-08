//
// Created by mechuon1 on 4/29/23.
//

#include "Entity.h"

#include "../World.h"

using namespace std;

Entity::Entity(int id, const string &name, char printChar,int health, int color, double probability) {
    this->id = id;
    this->printChar = printChar;
    this->name = name;
    this->health = health;
    this->colorID = color;
    this->drops = {};
    this->spawnProbability = probability;
}


Entity::Entity(int id,const string& name, char printChar ,int health, int color,const vector<int>&drops, double probability) {
    this->id = id;
    this->name = name;
    this->printChar = printChar;
    this->health = health;
    this->colorID = color;
    this->drops = drops;
    this->spawnProbability = probability;
}

Entity::Entity(const Entity &src) {
    this->id = src.id;
    this->name = src.name;
    this->printChar = src.printChar;
    this->health = src.health;
    this->colorID = src.colorID;
    this->drops = src.drops;
    this->spawnProbability = src.spawnProbability;
}


void Entity::spawn(World *homeWorld, map<int, shared_ptr<Chunk>>::iterator &pos, int yCoord){
    this->world = homeWorld;
    this->currentChunk = pos;
    this->y = yCoord;

    if (this->currentChunk->second->content[y]->getSpawnedEntity() != nullptr) { return; }

    this->currentChunk->second->content[y]->visit(this);
    this->world->freeFall(this);
    this->jumpTimer = make_shared<Timer>(chrono::milliseconds(JUMP_DURATION_MS), [this] { freeFall(); });
};



void Entity::moveUp() {
    this->world->moveUp(this);
}

void Entity::moveRight() {
    this->world->moveRight(this);

}

void Entity::moveRandom() {
    vector<MoveDirection> options = {MoveDirection::left,MoveDirection::right,MoveDirection::up};
    auto index = RandomGenerator::getFromInterval(0,(int)options.size()-1);


    switch (options[index]) {
        case MoveDirection::up:
            this->moveUp();
            return;

        case MoveDirection::right:
            this->moveRight();
            return;
        case MoveDirection::left:
            this->moveLeft();
            return;
        default:
            return;
    }
}


void Entity::moveLeft(){
    this->world->moveLeft(this);

}

void Entity::freeFall() {
   this->world->freeFall(this);
}

int Entity::getID() const {
    return this->id;
}

int Entity::color() const {
    return this->colorID;
}

double Entity::getSpawnProbability() const {
    return this->spawnProbability;
}

char Entity::getPrintChar() const {
    return this->printChar;
}

bool Entity::isActive(DayPhase phase) {
    return true;
}



void Entity::hurt(int damage) {
    this->health -= damage;
}


bool Entity::isDead() const {
    return this->health <=0;
}


void Entity::restoreHP(int hp) {
    this->health+=hp;
    if(this->health > Cache::max_health){
        this->health = Cache::max_health;
    }
}


string Entity::toString() {
    string content;
    content+= to_string(this->currentChunk->first);
    content+=THERNARY_DELIMETER;
    content+= this->printChar;
    return content;
}


Entity::~Entity() {
    if (jumpTimer) {
        jumpTimer->terminate();
    }

}








