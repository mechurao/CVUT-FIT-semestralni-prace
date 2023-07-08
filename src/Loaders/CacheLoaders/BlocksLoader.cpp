//
// Created by mechuon1 on 5/16/23.
//

#include "BlocksLoader.h"

using namespace std;

bool BlocksLoader::load(std::string &in) {

    // init default blocks
    Cache::itemsMap.insert({AIR_ID, make_shared<Air>()});
    Cache::itemsMap.insert({LAVA_ID, make_shared<Lava>()});


    auto blocks = StringSplitter::splitString(in,PRIMARY_DELIMETER);

    for(auto & block : blocks){

        auto content = StringSplitter::splitString(block,SECONDARY_DELIMETER);
        if(content.size() != 7){ return false;} // params count control

        // identifier
        auto id = NumberParser::parseInt(content[0]);
        if(!id.has_value()){return false;}
        if(!Cache::itemIdValid(id.value())){ return false;} // already used id

        // block name
        auto name = content[1];

        // printChar
        char printChar = content[3][0];
        if(!Cache::parseSignValid(printChar)){ return false;} // print char already used

        // drops
        vector<int> drops;

        auto dropsData = StringSplitter::splitString(content[2],THERNARY_DELIMETER);

        for(auto & drop : dropsData){
            auto item = NumberParser::parseInt(drop);
            if(!item.has_value()){ return false;}
            drops.push_back(item.value());
        }

        // color
        auto colorKey = NumberParser::parseInt(content[4]);
        if(!colorKey.has_value()){ return false;} // no number value

        auto itemColor = Cache::colorsMap.find(colorKey.value());
        if (itemColor == Cache::colorsMap.end()){return false;}// color is not defined

        // getSpawnProbability
        auto prob = NumberParser::parseDouble(content[5]);
        if(!prob.has_value()){ return false;} // invalid value

        // crafting requirments
        auto craftingData = StringSplitter::splitString(content[6],THERNARY_DELIMETER);

        vector<int> craftVec;
        for(auto &c : craftingData){

            auto r = NumberParser::parseInt(c);
            if(!r.has_value()){ return false;} // no valid number
            craftVec.push_back(r.value());
        }

        // add new block to items map
        auto  newBlock = make_shared<Block>(id.value(),name,printChar,drops,colorKey.value(), prob.value(),craftVec);
        Cache::itemsMap.insert({id.value(),newBlock});
    }
    return true;
}
