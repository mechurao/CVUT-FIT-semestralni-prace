//
// Created by mechuon1 on 5/16/23.
//

#include "WorldConfigLoader.h"

using namespace std;

std::map<std::string, bool> WorldConfigLoader::getCheckMap() {
    map<string,bool> controlMap = {
            make_pair(WORLD_HEIGHT_KEY,false),
            make_pair(WORLD_WIDTH_KEY,false),
            make_pair(BEDROCK_COLOR_ID_KEY,false),
            make_pair(AIR_COLOR_ID_KEY,false),
            make_pair(LAVA_COLOR_ID_KEY, false),
            make_pair(DAY_BACKGROUND_COLOR_ID,false),
            make_pair(NIGHT_BACKGROUND_COLOR_ID, false)
    };
    return controlMap;
}


bool WorldConfigLoader::load(std::string &in) {

    auto checkMap = getCheckMap();

    auto tokens = StringSplitter::splitString(in,PRIMARY_DELIMETER);
    for(auto &t : tokens){
        auto tmp = StringSplitter::splitString(t,SECONDARY_DELIMETER);
        if(tmp.size() != 2){ return false;} // invalid parameters count
        auto num = NumberParser::parseInt(tmp[1]);
        if(!num.has_value()){ return false;} // invalid number
        if(tmp[0] == WORLD_HEIGHT_KEY){
            Cache::world_height = num.value();
            if(Cache::world_height < MIN_WORLD_HEIGHT){ return false;} // too small world
        }else if(tmp[0] == WORLD_WIDTH_KEY){
            Cache::default_world_width = num.value();
            if(Cache::default_world_width < MIN_WORLD_WIDTH){return false;} // Too small world
        } else if(tmp[0] == BEDROCK_COLOR_ID_KEY){
            auto check = Cache::colorsMap.find(num.value());
            if(check == Cache::colorsMap.end()){ return false;} // color not found
            Cache::bedrock_color = num.value();
        }else if(tmp[0] == AIR_COLOR_ID_KEY){
            auto check = Cache::colorsMap.find(num.value());
            if(check == Cache::colorsMap.end()){ return false;} // color not found
            Cache::air_color = num.value();
        }else if(tmp[0] == LAVA_COLOR_ID_KEY){
            auto check = Cache::colorsMap.find(num.value());
            if(check == Cache::colorsMap.end()){ return false;} // color not found
            Cache::lava_color = num.value();
        }else if(tmp[0] == DAY_BACKGROUND_COLOR_ID){
            auto check = Cache::colorsMap.find(num.value());
            if(check == Cache::colorsMap.end()){ return false;} // color not found
            Cache::day_background_color = num.value();
        }else if(tmp[0] == NIGHT_BACKGROUND_COLOR_ID){
            auto check = Cache::colorsMap.find(num.value());
            if(check == Cache::colorsMap.end()){ return false;} // color not found
            Cache::night_background_color = num.value();
        }else{
            return false; // uknown key
        }
        checkMap[tmp[0]] = true; // mark key as found
    }

    // final check
    for(const auto &c : checkMap){
        if(!c.second){ return false;}
    }

    return true;
}


