//
// Created by mechuon1 on 5/15/23.
//

#include "Lava.h"

using namespace std;

Lava::Lava(): Block(LAVA_ID, LAVA_NAME, LAVA_CHAR, {}, Cache::lava_color, LAVA_PROBABILITY) {

}

bool Lava::isCrossable() const {
    return true;
}

void Lava::visit(Entity *entity) {
    entity->death = make_shared<LavaDeath>();
}




shared_ptr<Item> Lava::Clone() const  {
return make_shared<Lava>(*this); // Returns a copy of Lava
}

