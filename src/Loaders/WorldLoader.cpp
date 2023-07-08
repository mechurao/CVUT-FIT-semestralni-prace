//
// Created by Ondřej Měchura on 16.05.2023.
//

#include "WorldLoader.h"
#include "WorldLoader.h"
#include "../Utils/StringSplitter.h"
#include "../Utils/NumberParser.h"

using namespace std;

bool WorldLoader::loadWorld(World& world, std::string& worldData) {

    // temp items char map
    auto tempMap = createTempItemsCharMap();
    // parse chunks
    auto chunksData = StringSplitter::splitString(worldData,SECONDARY_DELIMETER);
    if(chunksData.size() < MIN_WORLD_WIDTH ){return false;}

    optional<size_t> heightCheck = nullopt; // height check

    for(auto &c : chunksData){
        auto chunk = make_shared<Chunk>();
        chunk->content.push_back(make_shared<Bedrock>()); // set top border

        auto params = StringSplitter::splitString(c,THERNARY_DELIMETER);
        if(params.size() != 2){ return false;}

        // Chunk x coordinate
        auto xCoord = NumberParser::parseInt(params[0]);
        if(!xCoord.has_value()){ return false;} // no valid number
        if(world.chunks.find(xCoord.value()) != world.chunks.end()){return false;} // X coordinate already added

        if(params[1].size() < MIN_WORLD_HEIGHT){ return false;} // Too small world

        // items
        for(auto &i : params[1]){
            if(heightCheck != nullopt){
                if(heightCheck.value() != params[1].size()){return false;} // Invalid chunk height
            }else{
                heightCheck = params[1].size();
            }

            auto target = tempMap.find(i);
            if(target == tempMap.end()){return false;} // invalid item char
            chunk->content.push_back(target->second->Clone());
        }
        chunk->content.push_back(make_shared<Bedrock>()); // bottom border
        world.chunks.insert({xCoord.value(),chunk});
    }

    // check continuity of world
    auto begin = world.chunks.begin()->first;
    auto end = prev(world.chunks.end())->first;

    for(int i = begin; i <= end;i++){
        auto target = world.chunks.find(i);
        if(target == world.chunks.end()){ return false;}
    }

    Cache::default_world_width = (int)world.chunks.size();
    Cache::world_height = (int)heightCheck.value();

    return true;
}

bool WorldLoader::loadMobs(World& world, std::string& src) {

    auto mobsTemp = createTempMobsMap();

    auto mobsData = StringSplitter::splitString(src,SECONDARY_DELIMETER);
    for(auto &i : mobsData){

        auto mob = StringSplitter::splitString(i,THERNARY_DELIMETER);
        if(mob.size() != 2){ return false;}

        string posString = mob[0];
        string idString = mob[1];

        if(idString.size() > 1){ return false;} // too long id

        auto xCoord = NumberParser::parseInt(posString);
        char id = idString[0];

        if(!xCoord.has_value()){ return false;} // Invalid identifier value
        if(world.chunks.find(xCoord.value()) == world.chunks.end()){ return false;} // Invalid coordinate


        auto target = mobsTemp.find(id);
        if(target == mobsTemp.end()){ return false;} // Unknown identifier

        world.spawnEntity(xCoord.value(),target->second->Clone());
    }
    return true;
}

std::map<char, std::shared_ptr<Item>> WorldLoader::createTempItemsCharMap() {
    map<char,shared_ptr<Item>> tempMap;

    for(auto &t : Cache::itemsMap){
        tempMap.insert({t.second->print(),t.second});
    }
    return tempMap;
}

std::map<char, std::shared_ptr<Entity>> WorldLoader::createTempMobsMap() {
    map<char,shared_ptr<Entity>> mobsTemp;

    for(const auto &m : Cache::mobsMap){
        mobsTemp.insert({m.second->getPrintChar(), m.second});
    }
    return mobsTemp;
}
