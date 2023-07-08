//
// Created by mechuon1 on 5/16/23.
//

#include "PlayerValsLoader.h"

using namespace std;

map<string, bool> PlayerValsLoader::getCheckMap() {
    map<string,bool> controlMap = {
            make_pair(PLAYER_MAX_HEALTH_KEY,false),
            make_pair(PLAYER_DAMAGE_KEY,false),
            make_pair(PLAYER_JUMP_HEIGHT_KEY,false),
            make_pair(PLAYER_FALL_DAMAGE_HEIGHT_KEY,false),
            make_pair(PLAYER_COLOR_ID_KEY,false)
    };
    return controlMap;
}

bool PlayerValsLoader::load(string &in) {

    auto checkMap = getCheckMap();

    auto tokens = StringSplitter::splitString(in,PRIMARY_DELIMETER);
    for(auto &t : tokens){
        auto content = StringSplitter::splitString(t,SECONDARY_DELIMETER);
        if(content.size() != 2){ return false;} // invalid params count

        auto value = NumberParser::parseInt(content[1]);
        if(!value.has_value()){ return false;} // value is not a number

        if(content[0] == PLAYER_MAX_HEALTH_KEY){
            Cache::max_health = value.value();
        }else if(content[0] == PLAYER_DAMAGE_KEY) {
            Cache::player_damage = value.value();
        }else if(content[0] == PLAYER_JUMP_HEIGHT_KEY) {
            Cache::jump_height = value.value();
        }else if(content[0] == PLAYER_FALL_DAMAGE_HEIGHT_KEY){
            Cache::fall_damage_height = value.value();
        }else if(content[0] == PLAYER_COLOR_ID_KEY){
            if(value.has_value() <= 0){return false;} // invalid color number
            auto colCheck = Cache::colorsMap.find(value.value());
            if(colCheck == Cache::colorsMap.end()){ return false;} // color not found
            Cache::player_color_id = value.value();
        }else{
            return false;
        } // invalid parameter
        checkMap[content[0]] = true; // mark found key
    }

    // final check
    for(const auto &c : checkMap){
        if(!c.second){ return false;}
    }
    return true;


}
