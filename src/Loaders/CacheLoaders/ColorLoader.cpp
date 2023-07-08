//
// Created by mechuon1 on 5/16/23.
//

#include "ColorLoader.h"

using namespace std;

bool ColorLoader::load(string &in) {
    auto colors = StringSplitter::splitString(in,PRIMARY_DELIMETER);
    for(auto & color : colors){
        auto content = StringSplitter::splitString(color,SECONDARY_DELIMETER);
        if(content.size() != 5){ return false;} // some parameter is missing

        // id
        auto id = NumberParser::parseInt(content[0]);
        if(!id.has_value()){ return false;} // NaN value
        if(id.value() <=0){ return false;} // invalid color value

        // name
        string name = content[1];

        // values
        auto r = NumberParser::parseInt(content[2]);
        auto g = NumberParser::parseInt(content[3]);
        auto b = NumberParser::parseInt(content[4]);

        if(!r.has_value() || !g.has_value() || !b.has_value()){ return false;} // NaN

        // rgb values check
        if (r.value() > RGB_VALUE_MAX || r.value() < RGB_VALUE_MIN){ return false;}
        if (g.value() > RGB_VALUE_MAX || g.value() < RGB_VALUE_MIN){ return false;}
        if( b.value() > RGB_VALUE_MAX || b.value() < RGB_VALUE_MIN){ return false;}

        // insert new color to map
        Color newColor = Color(id.value(),name,r.value(),g.value(),b.value());

        Cache::colorsMap.insert({id.value(),newColor});
    }
    return true;
}
