//
// Created by mechuon1 on 5/2/23.
//

#include "Food.h"

using namespace std;

Food::Food(int identifier, const string &itemName,char print, int hp, int itemColor, double dropProbability, vector<int>&crafting) : Item(identifier, itemName,print,itemColor,dropProbability,crafting){
    this->restoreHP = hp;
}


Food::Food(int identifier, const string &itemName,char print, int hp, int itemColor, double dropProbability) : Item(identifier, itemName,print,itemColor,dropProbability){
    this->restoreHP = hp;
}

Food::Food(const Food &src) : Item(src) {
    this->restoreHP = src.restoreHP;
}




vector<int> Food::useItem(shared_ptr<World>&world, Player*&player, MoveDirection direction) {
    player->restoreHP(this->restoreHP);
    if (player->isDead()) {
        player->death = make_shared<HungryDeath>();
    }

    this->durability--;
    return {};
}

shared_ptr<Item>Food::Clone() const{
    return make_shared<Food>(*this);
}









