//
// Created by Ondřej Měchura on 05/05/2020.
//

#ifndef SEMESTRALKA_INVENTORY_H
#define SEMESTRALKA_INVENTORY_H

// define selection mark


#include <map>
#include <vector>
#include <string>
#include <memory>


#include "World.h"
#include "Entities/Player.h"
#include "Enums/MoveDirection.h"
#include "Stack.h"

class Stack;

/**
 * @brief Class representing player's inventory
 * */
class Inventory {
private:

    /**
     * @brief Iterator pointing to currently selected item
     * */
    std::vector<std::shared_ptr<Stack>>::iterator selectedItem;


    /**
     * @brief Check if inventory is empty
     * @return Yes if empty, false if not
     * */
    [[nodiscard]] bool isEmpty()const;

public:

    /**
     * @brief Vector of stacks of stored items
     * */
    std::vector<std::shared_ptr<Stack>> inventory;


    /**
     * @brief Default inventory constructor
     * */
    Inventory();

    /**
     * @brief Copy constructor
     * @param src Reference to copied inventory
     * */
    Inventory(const Inventory& src);


    // item management

    /**
     * @brief Add new item to inventory
     * @param itemID Identifier of inserted item
     * */
    void addToInventory(int itemID);

    /**
     * @brief Remove an item from inventory
     * @param itemID identifier of removed item
     * */
    void removeFromInventory(int itemID);

    /**
     * @brief Use selected item ( if currently selected option is null, then default tool (player hand) is used)
     * */
    void useSelected(std::shared_ptr<World> world, Player *& player, MoveDirection direction);


    // select methods

    /**
     * @brief Select next inventory options
     * */
    void selectNext();

    /**
     * @brief Select previous inventory options
     * */
    void selectPrev();

    /**
     * @brief Select element at given index
     * @param index index of target inventory option
     * */
    void selectAtIndex(int index);


// helper method for crafting


    /**
     * @brief Prints inventory content to screen
     * */
    void printInventory();

    /**
     * @brief Getter of string representation of inventory
     * @return Inventory encoded to string for saving purposes
     * */
    std::string toString();

    /**
     * @brief Method to make deep copy of inventory
     * @return shared?ptr to newly created inventory object
     * */
    [[nodiscard]] std::shared_ptr<Inventory> Clone () const;

};


#endif //SEMESTRALKA_INVENTORY_H
