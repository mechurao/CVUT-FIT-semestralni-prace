//
// Created by Ondřej Měchura on 03.05.2023.
//

#ifndef SEMESTRALKA_CRAFTINGSCREEN_H
#define SEMESTRALKA_CRAFTINGSCREEN_H

#include "Screen.h"
#include "../Cache.h"

using namespace std;


/**
 * Class derived from screen providing creating new items from items contained in player's inventory
 * */
class CraftingScreen: public Screen{

private:
    /**
     * @brief Pointer to player's inventory
     * */
    std::shared_ptr<Inventory> inventory;

    /**
     * @brief Vector of available crafting options
     * */
    std::vector<std::shared_ptr<Item>> options;

    /**
     * @brief Iterator for navigation in options map
     * */
    std::optional<std::vector<std::shared_ptr<Item>>::iterator> optionsIt;


    /**
     * @brief Map of items identifiers and their count  in player's inventory
     * */
    std::map<int, int> itemsMap;

    /**
     * @brief Initialize helper items map with item identifiers and counts
     * */
    void initItemsMap();

    /**
     * @brief Initialize  craftable items vec
     * */
    void initOptions();

    /**
     * @brief Update  crafting options map
     * */
    void refreshOptions();


    /**
     * @brief Overriden method to print crafting information
     * */
    void printContent() override;

    /**
     * @brief Overriden confirm action (here used for crafting options selection)
     * */
    void enterAction() override;

    /**
     * @brief Overriden prev action (here sets previous available crafting option)
     * */
    void actionUp() override;

    /**
     * @brief Overriden prev action (here sets next available  crafting option)
     * */
    void actionDown() override;




public:

    /**
     * @brief Crafting screen constructor
     * @param inv Shared pointer to player's inventory
     * */
    explicit CraftingScreen(shared_ptr<Inventory>inv);


};


#endif //SEMESTRALKA_CRAFTINGSCREEN_H
