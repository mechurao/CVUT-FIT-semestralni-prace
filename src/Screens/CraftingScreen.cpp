//
// Created by Ondřej Měchura on 03.05.2023.
//

#include "CraftingScreen.h"

#include <utility>


void CraftingScreen::initItemsMap() {

    for(auto &i : this->inventory->inventory){
        if(i != nullptr){

            auto target = this->itemsMap.find(i->id);
            if(target != this->itemsMap.end()){
                target->second+= (int) i->items.size();
            }else{
                this->itemsMap.insert({i->id,(int)i->items.size()});
            }
        }
    }
}


void CraftingScreen::initOptions() {
    for(auto &i : Cache::itemsMap){
        if(i.second->amountMatching(this->itemsMap)){
            this->options.push_back(i.second);
        }
    }

    if(!this->options.empty()){
        this->optionsIt = this->options.begin();
    }else{
        this->optionsIt = nullopt;
    }
}

void CraftingScreen::refreshOptions() {

    /** Clear old data*/
    this->itemsMap.clear();
    this->options.clear();


    this->initItemsMap();
    this->initOptions();
}



CraftingScreen::CraftingScreen( shared_ptr<Inventory> inv) {

    this->inventory = std::move(inv);
    this->refreshOptions();

}


void CraftingScreen::enterAction() {
    if(this->optionsIt == nullopt){ return;}

    for(auto &r : (*this->optionsIt.value())->getCraftingRequirments()){
        this->inventory->removeFromInventory(r.first);
    }

    this->inventory->addToInventory((*this->optionsIt.value())->getId());

    this->refreshOptions();
}

void CraftingScreen::actionUp() {
    if(this->optionsIt == nullopt){ return;}

    if(this->optionsIt.value() == this->options.begin()){
        this->optionsIt.value() = prev(this->options.end());
        return;
    }
    this->optionsIt.value()--;
}

void CraftingScreen::actionDown() {
    if(this->optionsIt == nullopt){ return;}

    if(next(this->optionsIt.value()) == this->options.end()){
        this->optionsIt.value() = this->options.begin();
        return;
    }
    this->optionsIt.value()++;
}





void CraftingScreen:: printContent() {
    printw("%s\n",CRAFTING_TITLE);

    for(auto it = this->options.begin();it != this->options.end();it++){
        printw("%s ",(*it)->getName().data());

        if(it == this->optionsIt.value()){
            printw("*");
        }
        printw("\n");
    }
}



