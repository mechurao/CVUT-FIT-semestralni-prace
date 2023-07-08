//
// Created by mechuon1 on 4/22/23.
//


#include "Air.h"

using namespace std;

Air::Air(): Block(AIR_ID, AIR_NAME, AIR_CHAR, {}, Cache::air_color, 0){};

bool Air::isCrossable() const {
    return this->spawnedEntity == nullptr;
}

shared_ptr<Item> Air::Clone() const  {
    return make_shared<Air>(*this);
}
