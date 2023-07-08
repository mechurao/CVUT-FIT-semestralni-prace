//
// Created by mechuon1 on 5/16/23.
//

#include "GameLoader.h"

using namespace std;

bool GameLoader::loadGame(string &saveData, shared_ptr<World>& world, Player*&player) {
    auto data = StringSplitter::splitString(saveData,PRIMARY_DELIMETER);

    if(data.size() != 3){       // invalid params count
        return false;
    }

    string worldData = data[0];
    string playerData = data[1];
    string mobsData = data[2];

    bool worldCheck = loadWorld(worldData, mobsData, world);
    if(!worldCheck){ return false;} // world parsing failed

    bool playerCheck = PlayerLoader::loadPlayer(playerData, world, player);

    return  playerCheck;
}

bool GameLoader::loadWorld(string& worldSrc, string& mobsSrc, shared_ptr<World>&world) {
    bool worldRes = false;

    world = make_shared<World>(worldRes,worldSrc,mobsSrc);
    return worldRes;
}

