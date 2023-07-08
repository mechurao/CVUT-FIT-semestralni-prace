//
// Created by mechuon1 on 5/17/23.
//

#include "FoodLoader.h"

using namespace std;

bool FoodLoader::load(std::string &in) {

    auto foods = StringSplitter::splitString(in,PRIMARY_DELIMETER);
    for(auto &food : foods){
        auto content = StringSplitter::splitString(food,SECONDARY_DELIMETER);
        if(content.size() != 7){  return false;} // invalid params count

        // id
        auto id = NumberParser::parseInt(content[0]);
        // name
        string  name = content[1];

        // print char
        char printChar = content[3][0];
        if(!Cache::parseSignValid(printChar)){return false;} // already used print char

        // restore HP
        auto hp = NumberParser::parseInt(content[2]);

        if(!id.has_value() || !hp.has_value()){ return false;} // NaN

        if(!Cache::itemIdValid(id.value())){ return false;} // already used item id

        // color
        auto colorKey = NumberParser::parseInt(content[4]);
        if(!colorKey.has_value()){ return false;} // invalid value
        auto itemColor = Cache::colorsMap.find(colorKey.value());
        if(itemColor == Cache::colorsMap.end()){ return false;} // color not found

        // getSpawnProbability
        auto prob = NumberParser::parseDouble(content[5]);
        if(!prob.has_value()){ return false;} // invalid value

        // crafting
        auto craftData = StringSplitter::splitString(content[6],THERNARY_DELIMETER);
        vector<int> req;
        for(auto &c : craftData){
            auto r = NumberParser::parseInt(c);
            if(!r.has_value()){ return false;} // not valid value
            req.push_back(r.value());
        }


        // new food
        auto newFood = make_shared<Food>(id.value(),name,printChar,hp.value(),colorKey.value(), prob.value(),req);
        Cache::itemsMap.insert({id.value(),newFood});
    }
    return true;
}
