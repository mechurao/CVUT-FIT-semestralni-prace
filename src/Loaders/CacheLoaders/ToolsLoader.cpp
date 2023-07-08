//
// Created by mechuon1 on 5/17/23.
//

#include "ToolsLoader.h"

using namespace std;

bool ToolsLoader::load(std::string &in) {
    auto tools = StringSplitter::splitString(in,PRIMARY_DELIMETER);
    for(auto &tool : tools){
        auto content = StringSplitter::splitString(tool,SECONDARY_DELIMETER);
        if(content.size() != 8){ return false;} // params count control
        // id
        auto id = NumberParser::parseInt(content[0]);
        if(!id.has_value()){ return false;}
        if(!Cache::itemIdValid(id.value())){ return false;} // already used item id
        // name
        auto name = content[1];

        // print char
        char printChar = content[4][0];
        if(!Cache::parseSignValid(printChar)){ return false;} // already used parsed char

        // durability
        auto durability = NumberParser::parseInt(content[2]);
        auto damage = NumberParser::parseInt(content[3]);
        if(!durability.has_value() || !damage.has_value()){ return false;} // params valid control

        // color
        auto colorKey = NumberParser::parseInt(content[5]) ;
        if(!colorKey.has_value()){ return false;} // invalid value
        auto itemColor = Cache::colorsMap.find(colorKey.value());
        if(itemColor == Cache::colorsMap.end()){return false;}

        // getSpawnProbability
        auto prob = NumberParser::parseDouble(content[6]);
        if(!prob.has_value()){ return false;} // invalid number

        // crafting

        auto craftData = StringSplitter::splitString(content[7],THERNARY_DELIMETER);
        vector<int> req;
        for(auto &c : craftData){
            auto r = NumberParser::parseInt(c);
            if(!r.has_value()){return false;} // not valid number
            req.push_back(r.value());
        }


        // add new tool to items map
        auto  newTool = make_shared<Tool>(id.value(),name,printChar,durability.value(),damage.value(),colorKey.value(), prob.value(),req);
        Cache::itemsMap.insert({id.value(),newTool});
    }
    return true;
}
