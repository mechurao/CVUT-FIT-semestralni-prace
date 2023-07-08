//
// Created by mechuon1 on 5/16/23.
//

#include "PlayerLoader.h"

using namespace std;

bool PlayerLoader::loadPlayer(std::string &playerData, std::shared_ptr<World> &world, Player *&player) {
    auto data = StringSplitter::splitString(playerData,SECONDARY_DELIMETER);

    if(data.size() != 3){return false;} // invalid params count

    string xPos = data[0];
    string yPos = data[1];
    string inventoryData = data[2];

    // X coordinate
    auto xCoord = NumberParser::parseInt(xPos);
    if(!xCoord.has_value()){ return false;} // Not number value

    auto yCoord = NumberParser::parseInt(yPos);
    if(!yCoord.has_value()){
        return false;} // Not number value
    if(yCoord.value() <=0){ return false;} // Invalid coordinate

    if(world == nullptr){ return false;}
    player = world->spawnPlayer(xCoord.value(),yCoord.value());

    if(player == nullptr ){return false;}

    // inventory

    if(!(inventoryData.size() == 1 && inventoryData == string(1,THERNARY_DELIMETER))){ // check if inventory is empty
        map<char,int> tempMap;


        for(auto &i : Cache::itemsMap){
            tempMap.insert({i.second->print(),i.second->getId()});
        }

        for(auto &s : inventoryData){
            auto target = tempMap.find(s);
            if(target == tempMap.end()){ return false;} // item not found
            player->getInventory()->addToInventory(target->second);
        }
    }
    return true;
}
