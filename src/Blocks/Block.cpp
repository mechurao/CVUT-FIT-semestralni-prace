//
// Created by mechuon1 on 4/24/23.
//

#include "Block.h"
#include "../World.h"

using namespace std;

Block::Block(int id, const string &name, char print,const vector<int>& dropItems, int itemColor, double itemProbability, vector<int>&crafting) : Item(id, name,print,itemColor,itemProbability,crafting) {
   for(auto &i : dropItems){
       this->drops.push_back(i);
   }
}

Block::Block(int id, const string &name, char print, const vector<int> &dropItems, int itemColor,
             double itemProbability): Item(id,name,print,itemColor,itemProbability) {
    for(auto &i : dropItems){
        this->drops.push_back(i);
    }

}



vector<int> Block::useItem(shared_ptr<World> &world, Player*& player, MoveDirection direction) {
    auto targetOpt = world->getTarget(player, direction); // check if there is a place to put a block

    if (!targetOpt.has_value()) {
        return {};
    }

    std::shared_ptr<Item>& target = targetOpt.value().get();

    if (!target->isCrossable()) {
        return {};
    }

    world->build(this->getId(), direction);
    this->durability--;

    return {};
}

shared_ptr<Item> Block::Clone() const{
    return make_shared<Block>(*this);
}





