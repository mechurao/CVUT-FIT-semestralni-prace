//
// Created by mechuon1 on 4/29/23.
//

#include "InventoryScreen.h"

#include <utility>

using namespace std;

InventoryScreen::InventoryScreen(shared_ptr<Inventory>inv) : inventory(std::move(inv)) {

    this->actions.insert({Action::gameCraftingRemove,[this]{ deleteStack();}});

    this->current = this->inventory->inventory.begin();
}

void InventoryScreen::actionDown()  {
    if(next(this->current) == this->inventory->inventory.end()){
        this->current = this->inventory->inventory.begin();
        return;
    }
    this->current++;
}

void InventoryScreen::actionUp() {
    if(this->current == this->inventory->inventory.begin()){
        this->current = prev(this->inventory->inventory.end());
        return;
    }
    this->current--;
}

void InventoryScreen::enterAction() {

    if(this->first == this->inventory->inventory.end() && this->second == this->inventory->inventory.end()){
        this->first = this->current;

    }else if(this->first != this->inventory->inventory.end() && this->second == this->inventory->inventory.end()){

        if(this->current == this->first){
            this->first = this->inventory->inventory.end();
            return;
        }

        this->second = this->current;

    }else if(this->first == this->inventory->inventory.end() && this->second != this->inventory->inventory.end()){
        if(this->second == this->current){
            this->second = this->inventory->inventory.end();
            return;
        }
        this->first - this->current;

    }



    if(this->first != this->inventory->inventory.end() && this->second != this->inventory->inventory.end()){
        this->swapStacks();
        this->first = this->inventory->inventory.end();
        this->second = this->inventory->inventory.end();
    }
}

void InventoryScreen::deleteStack() {
    if((*this->current) == nullptr){ return;}
    (*this->current)->items.clear();
    (*this->current) = nullptr;

}

void InventoryScreen::swapStacks() {
    swap(*first,*second);
}



void InventoryScreen::printContent() {

  for(auto it = this->inventory->inventory.begin(); it != this->inventory->inventory.end();it++){
      if( (*it) != nullptr ){
          (*it)->print();
      }else{
          printw("[]");
      }

      if(it == this->first || it == this->second){
          printw("#");
      }else{
          printw(" ");
      };

      if(it == this->current){ printw("*");}
      printw("\n");
  }
}
