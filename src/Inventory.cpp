//
// Created by Ondřej Měchura on 05/05/2020.
//

#include "Inventory.h"

using namespace std;

Inventory::Inventory() {
    for(int i = 0; i < INVENTORY_SIZE;i++){
        this->inventory.push_back(nullptr);
    }

    if(this->inventory.empty()){ return;}
    this->selectedItem = this->inventory.begin();
}

Inventory::Inventory(const Inventory &src) {

    // init inventory space
    for(int i = 0; i < (int)src.inventory.size();i++){
        this->inventory.push_back(nullptr);
    }

    // dopy items
    for(auto &s : src.inventory){
        if(s != nullptr){
            if(!s->items.empty()){
                for(int i = 0; i < (int)s->items.size();i++){
                    this->addToInventory(s->id);
                }
            }
        }
    }
}



bool Inventory::isEmpty() const {
    for(const auto &s : this->inventory){
        if(s != nullptr){ return false;}
    }
    return true;
}



void Inventory::addToInventory(int itemID) {

    /** Check item ID*/
    auto target = Cache::itemsMap.find(itemID);
    if (target == Cache::itemsMap.end()) { return; }


    if ((target->second->isStackable())) {
        // check if stack with this item exists. If yes, add item to it
        for (auto &it: this->inventory) {
            if (it != nullptr) {
                if (it->id == itemID) {
                    if (it->items[0]->isStackable() && (it->items.size() < MAX_STACK_SIZE)) {
                        it->items.push_back(Cache::itemsMap[itemID]->Clone());
                        return;
                    }
                }
            }
        }
    }

    // Make new stack
    auto  newStack = make_shared<Stack>();
    newStack->id = itemID;
    newStack->items.push_back(Cache::itemsMap[itemID]->Clone());

    // And find new place for it
    for(auto &i : this->inventory){
        if(i == nullptr){
            i = newStack;
            return;
        }
    }
}

void Inventory::removeFromInventory(int itemID) {
    for(auto & stack : this->inventory) {
        if (stack != nullptr) {
            if (stack->id == itemID) {
                if (stack->items.empty()) { return; }
                stack->items.erase(stack->items.begin());

                if (stack->items.empty()) {
                    stack = nullptr;
                }
                return;

            }
        }
    }
}


void Inventory::useSelected(shared_ptr<World> world, Player*& player, MoveDirection direction) {
    shared_ptr<Stack> selectedStack = *this->selectedItem;
    if(selectedStack != nullptr){
        selectedStack->items[0]->useItem(world, player, direction);
        if(selectedStack->items[0]->getDurability() == 0){
            selectedStack->items.erase(selectedStack->items.begin());
        }
        if(selectedStack->items.empty()){
            *this->selectedItem = nullptr;
        }
    }else{
        auto res = player->getHand().useItem(world, player, direction);
        for(auto &i : res){
            this->addToInventory(i);
        }
    }
}





// select next item in inventory
void Inventory::selectNext() {
    if(next(this->selectedItem) == this->inventory.end()){
        this->selectedItem = this->inventory.begin();
        return;
    }
    this->selectedItem++;
}

void Inventory::selectPrev() {
    if(this->selectedItem == this->inventory.begin()){
        this->selectedItem = prev(this->inventory.end());
        return;
    }
    this->selectedItem--;
}

void Inventory::selectAtIndex(int index) {
    if(index >= (int)this->inventory.size()){ return;} // paranoid length validation
    this->selectedItem = this->inventory.begin()+index;
}



void Inventory::printInventory() {
    for(auto it = this->inventory.begin(); it != this->inventory.end();it++){
        if( (*it) != nullptr ){
            (*it)->print();
        }else{
            printw("%s",INVENTORY_EMPTY_SLOT_SIGN);
        }

        if(it == this->selectedItem){ printw("%c",INVENTORY_SELECTION_SIGN);}
        printw("\n");
    }
}

string Inventory::toString() {
    string result;

    if(!this->isEmpty()){
        for(auto &i : this->inventory){
            if(i != nullptr){
                for(auto &j : i->items){
                    result+=j->print();
                }
            }
        }
    }else{
        result+=THERNARY_DELIMETER;
    }

    return result;
}

std::shared_ptr<Inventory> Inventory::Clone() const {
    return make_shared<Inventory>(*this);
}





