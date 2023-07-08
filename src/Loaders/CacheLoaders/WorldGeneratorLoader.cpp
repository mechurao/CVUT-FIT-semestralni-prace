//
// Created by mechuon1 on 5/16/23.
//

#include "WorldGeneratorLoader.h"

using namespace std;

std::map<std::string, bool> WorldGeneratorLoader::getCheckMap() {
    map<string,bool> controlMap = {
            make_pair(MIN_AIR_ALT_KEY,false),
            make_pair(MIN_MID_ALT_KEY,false),
            make_pair(MIN_BOTTOM_ALT_KEY,false),
            make_pair(MID_BLOCKS_KEY,false),
            make_pair(BOTTOM_BLOCKS_KEY,false)
    };
    return controlMap;
}

bool WorldGeneratorLoader::load(string &in) {
    auto controlMap = getCheckMap();



    auto values = StringSplitter::splitString(in,PRIMARY_DELIMETER);
    for(auto &val : values){
        auto data = StringSplitter::splitString(val,SECONDARY_DELIMETER);
        if(data.size() != 2){ return false;}
        string key = data[0];

        if(key == MIN_AIR_ALT_KEY){
            auto num = NumberParser::parseDouble(data[1]);
            if(!num.has_value()){ return false;} // invalid value
            Cache::min_air_alt = num.value();

        }else if(key == MIN_MID_ALT_KEY){
            auto num = NumberParser::parseDouble(data[1]);
            if(!num.has_value()){ return false;} // ivalid value
            Cache::min_mid_alt = num.value();

        }else if(key == MIN_BOTTOM_ALT_KEY){
            auto num = NumberParser::parseDouble(data[1]);
            if(!num.has_value()){ return false;} // ivalid value
            Cache::min_bottom_alt = num.value();

        }else if(key == MID_BLOCKS_KEY){
            auto blocks = StringSplitter::splitString(data[1],THERNARY_DELIMETER);
            if(blocks.empty()){ return false;} // at least one required block
            for(auto &id : blocks){
                auto num = NumberParser::parseInt(id);
                if(!num.has_value()){ return false;} // invalid value

                auto check = Cache::itemsMap.find(num.value());
                if(check == Cache::itemsMap.end()){ return false;} // item not found
                Cache::mid_items_vec.push_back(num.value());
            }
        }else if(key == BOTTOM_BLOCKS_KEY){
            auto blocks = StringSplitter::splitString(data[1],THERNARY_DELIMETER);
            if(blocks.empty()){ return false;} // at least one required block
            for(auto &id : blocks){
                auto num = NumberParser::parseInt(id);
                if(!num.has_value()){ return false;} // invalid value

                auto check = Cache::itemsMap.find(num.value());
                if(check == Cache::itemsMap.end()){ return false;} // item not found
                Cache::bottom_items_vec.push_back(num.value());
            }
        }else{ return false;} // unknown key found

        controlMap[key] = true; // mark found key
    }

    // final check
    for(const auto &c : controlMap){
        if(!c.second){ return false;}
    }

    return true;

}
