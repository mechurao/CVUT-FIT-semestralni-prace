//
// Created by mechuon1 on 5/16/23.
//

#include "MobsLoader.h"

using namespace std;

bool MobsLoader::load(string &in) {
    auto values = StringSplitter::splitString(in,PRIMARY_DELIMETER);
    for(auto & val : values){
        auto data = StringSplitter::splitString(val,SECONDARY_DELIMETER);
        if(data.size() != 9){ return false;} // Invalid parameters count

        // id
        auto id = NumberParser::parseInt(data[0]);
        if(!id.has_value()){ return false;} // Not number id
        if(!Cache::entityIdValid(id.value())){ return false;} // invalid mob id

        // name
        auto name = data[1];

        // hp
        auto hp = NumberParser::parseInt(data[2]);
        if(!hp.has_value()){ return false;} // Not number hp
        if(hp.has_value() <= 0){ return false;} // hp has to be a positive number

        // char
        if(data[3].size() > 1){ return false;}
        char printChar = data[3][0];
        if(!Cache::parseSignValid(printChar)){ return false;} // already used print char

        // drops
        vector<int> drops;
        for(auto &drop : StringSplitter::splitString(data[4],THERNARY_DELIMETER)){
            auto dropID = NumberParser::parseInt(drop);
            if(!dropID.has_value()){ return false;} // Not number id
            // check
            auto check = Cache::itemsMap.find(dropID.value());
            if(check == Cache::itemsMap.end()){ return false;} // item does not exist
            drops.push_back(dropID.value());
        }

        // color
        auto colorID = NumberParser::parseInt(data[5]);
        if(!colorID.has_value()){ return false;} // Not number id

        // check
        auto colCheck = Cache::colorsMap.find(colorID.value());
        if(colCheck == Cache::colorsMap.end()){ return false;} // Color not found

        // getSpawnProbability
        auto prob = NumberParser::parseDouble(data[6]);
        if(!prob.has_value()){ return false;} // not a number
        if(prob.value() < 0){ return false;} // has to be positive

        // day activity
        auto day = NumberParser::parseInt(data[7]);
        if(!day.has_value()){return false;} // Invalid number conversion
        if(day.value() != 0 && day.value() != 1){ return false;} // Not convertible to bool

        // night activity
        auto night = NumberParser::parseInt(data[8]);
        if(!night.has_value()){return false;} // Invalid number conversion
        if(night.value() != 0 && night.value() != 1){ return false;} // Not convertible to bool


        auto mob = make_shared<Mob>(id.value(),name,printChar,hp.value(),colorID.value(),drops,prob.value(),day.value(),night.value());
        Cache::mobsMap.insert({id.value(),mob});
    }
    return true;
}
