//
// Created by Ondřej Měchura on 02/05/2020.
//

#include "Item.h"

using namespace std;

int Item::getId() const { return this->id;}

string Item::getName() const {return this->name;}

double Item::getSpawnProbability() const {return this->probability;}




int Item::getDurability() const {return this->durability;}


void Item::initCraftingReq(vector<int>&reg) {

    for(auto &r : reg){
        auto target = this->craftingReq.find(r);

        if(target != this->craftingReq.end()){
            target->second++;
        }else{
            this->craftingReq.insert({r,1});
        }
    }
}



int Item::getColorID() const{
    if(this->spawnedEntity != nullptr){return this->spawnedEntity->color();}
    return this->colorID;
}

void Item::visit(Entity *entity) {
    this->spawnedEntity = entity;
}

void Item::leave() {
    this->spawnedEntity = nullptr;
}

Entity *Item::getSpawnedEntity() const {
    return this->spawnedEntity;
}


map<int, int> Item::getCraftingRequirments() const {
    return this->craftingReq;
}

vector<int> Item::getDrops() const {
    return this->drops;
}





void Item::decreaseDurability(int value){
    this->durability-=value;
};

bool Item::isStackable() const { return true;}

bool Item::isCrossable() const {
    return false;
}


Item::Item(int id, const string &name, char print, int itemColor, double  dropProbability, vector<int>&craft): colorID(itemColor),probability(dropProbability){
    this->id = id;
    this->name = name;
    this->printChar = print;
    this->initCraftingReq(craft);
}

Item::Item(int id, const string &name, char print, int itemColor, double dropProbability): colorID(itemColor),probability(dropProbability) {
    this->id = id;
    this->name = name;
    this->printChar = print;
    this->craftingReq = {};
}

Item::Item(const Item& src){

    /** main info */
    this->id = src.id;
    this->name = src.name;
    this->printChar = src.printChar;
    this->colorID = src.colorID;
    this->probability = src.probability;
    this->durability = src.origDurability;
    this->damage = src.damage;

    /** Craftables*/
    this->craftingReq = src.craftingReq;

    /** Drops*/
    this->drops = src.drops;

};





bool Item::amountMatching(const map<int,int>& src) const{
    if(this->craftingReq.empty()){ return false;} // no craftables to show
    if(src.empty()){ return false;} // inventory is empty

    for(auto &i : this->craftingReq){
       auto target = src.find(i.first); // find item id in plyer inventory
       if(target == src.end()){ return false;} // required item not found
        if(i.second > target->second){return false;} // not enough items in player inventory
    }
    return true;
}




char Item::print() const {
    return this->printChar;
}














