//
// Created by mechuon1 on 3/28/23.
//

#include "Cache.h"

using namespace std;

map<int,Color> Cache::colorsMap;
map<int,shared_ptr<Item>> Cache::itemsMap;
map<int, Action> Cache::actions;
// world values
int Cache::world_height, Cache::default_world_width;

// Day phase colors
int Cache::day_background_color, Cache::night_background_color;

// defined material colors
int Cache::bedrock_color,Cache::air_color,Cache::lava_color;

// player values
int  Cache::max_health, Cache::player_damage, Cache::player_color_id, Cache::jump_height, Cache::fall_damage_height;

// world generator values
double Cache::min_air_alt,Cache::min_mid_alt, Cache::min_bottom_alt;
vector<int> Cache::mid_items_vec, Cache::bottom_items_vec;

// mobs map
map<int, shared_ptr<Entity>> Cache::mobsMap;


bool Cache::itemIdValid(int id) {
    if(id < 0){ return false;}
    auto target = itemsMap.find(id);
    return target == itemsMap.end();
}

bool Cache::entityIdValid(int id) {
    if(id < 0){ return false;}
    auto target = mobsMap.find(id);
    return  target == mobsMap.end();
}

bool Cache::parseSignValid(char sign) {
    if(sign == PLAYER_CHAR){return false;}

    // check items parse signs
    for(auto &i : itemsMap){
        if(i.second->print() == sign){ return false;}
    }

    // check entities parse signs
    for(auto &e : mobsMap){
        if(e.second->getPrintChar() == sign){ return false;}
    }
    return true;
}

template<typename Loader, typename... Args>
bool Cache::initData(const std::string& path, Args&&... args) {
    std::string content;
    if (!FileReader::readFile(path, content)) { return false; }
    return Loader::load(std::forward<Args>(args)..., content);
}


bool Cache::initColors() {
    return initData<ColorLoader>(string(CONFIG_DIR)+COLORS_PATH);
}

bool Cache::initItems() {
    return initData<BlocksLoader>(string(CONFIG_DIR)+BLOCKS_PATH) &&
           initData<ToolsLoader>(string(CONFIG_DIR)+TOOLS_PATH) &&
           initData<FoodLoader>(string(CONFIG_DIR)+FOOD_PATH);
}

bool Cache::initActions() {
    return initData<ActionsLoader>(string(CONFIG_DIR)+CONTROLS_PATH);
}

bool Cache::initWorldConfig() {
    return initData<WorldConfigLoader>(string(CONFIG_DIR)+WORLD_PATH);
}

bool Cache::initPlayerValues() {
    return initData<PlayerValsLoader>(string(CONFIG_DIR)+PLAYER_PATH);
}

bool Cache::initWorldGenerator() {
    return initData<WorldGeneratorLoader>(string(CONFIG_DIR)+MAP_GENERATOR_PATH);
}

bool Cache::initMobs() {
    return initData<MobsLoader>(string(CONFIG_DIR)+MOBS_PATH);
}

bool Cache::itemsRequirmentsValid() {

    // loop all items
    for(auto &i : itemsMap){

        // check drops
        for(auto &d : i.second->getDrops()){
            if(itemsMap.find(d) == itemsMap.end()){ return false;} // item not found
        }

        // check crafting requirments
        for(auto &c : i.second->getCraftingRequirments()){
            if(itemsMap.find(c.first) == itemsMap.end()){ return false;} // item not found
        }
    }
    return true;
}



void Cache::clear() {
    itemsMap.clear();
    mobsMap.clear();
}

Cache::~Cache() = default;






