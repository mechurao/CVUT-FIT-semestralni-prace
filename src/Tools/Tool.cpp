//
// Created by mechuon1 on 4/24/23.
//

#include "Tool.h"
#include "../World.h"

using namespace std;

Tool::Tool(int identifier, const string &itemName, char print, int dur, int dmg, int itemColor, double itemProbability,
           vector<int> &crafting): Item(identifier,itemName,print,itemColor,itemProbability,crafting) {
    this->damage = dmg;
    this->durability = dur;

}


Tool::Tool(int identifier, const string &itemName, char print,int dur, int dmg, int itemColor, double itemProbability) : Item(identifier, itemName,print,itemColor, itemProbability) {
    this->durability = dur;
    this->damage = dmg;
}





vector<int> Tool::useItem(shared_ptr<World>&world, Player*&player, MoveDirection direction) {
    auto targetOpt = world->getTarget(player, direction);

    if (!targetOpt.has_value()) {
        return {}; // if target doesn't exist, nothing can be obtained
    }

    std::shared_ptr<Item>& target = targetOpt.value().get();
    vector<int> res;

    if (target->isCrossable()) {
        return res; // nothing to do if block is crossable
    }

    if (target->getSpawnedEntity() != nullptr) {
        target->getSpawnedEntity()->hurt(this->damage);
        if (target->getSpawnedEntity()->isDead()) {
            for (auto &d : target->getSpawnedEntity()->drops) {
                res.push_back(d);
            }
            target->leave();
        }
    } else {
        target->decreaseDurability(this->damage);

        if (target->getDurability() <= 0) {
            res = target->getDrops();
            world->destroy(direction);
        }
    }

    // decrease tool durability
    this->decreaseDurability(1);

    return res;
}

bool Tool::isStackable() const {
    return false;
}

shared_ptr<Item> Tool::Clone() const {
    return make_shared<Tool>(*this);
}



