//
// Created by mechuon1 on 4/29/23.
//

#ifndef SEMESTRALKA_INVENTORYSCREEN_H
#define SEMESTRALKA_INVENTORYSCREEN_H


#include "Screen.h"
#include "../Inventory.h"

/**
 * @brief Screen for managing player inventory (swaping and removing items)
 * */
class InventoryScreen: public Screen{
private:

    /**
     * @brief Shared pointer to player's inventory
     * */
    std::shared_ptr<Inventory> inventory;

    /**
     * @brief Overriden action up method (here for selecting previous item)
     * */
    void actionUp() override;

    /**
     * @brief Overriden action down method (here for selecting next item)
     * */
    void actionDown() override;

    /**
     * @brief Overriden enter action (here for confirm selected items to swap)
     * */
    void enterAction() override;

    /**
     * @brief Iterator to currently selected item
     * */
    std::vector<std::shared_ptr<Stack>>:: iterator current;

    /**
     * @brief Iterator to first selected item
     * */
    std::vector<std::shared_ptr<Stack>>:: iterator first = inventory->inventory.end();

    /**
     * @brief Iterator to second selected item
     * */
    std:: vector<std::shared_ptr<Stack>>::iterator second = inventory->inventory.end();

    /**
     * @brief Overriden method to print inventory content
     * */
    void printContent() override;

    /**
     * @brief Swap two selected stacks in inventory
     * */
    void swapStacks();

    /**
     * @brief Delete selected stack from inventory
     * */
    void deleteStack();



public:

    /**
     * @brief Inventory screen constructor
     * @param inv shared_ptr to player's inventory
     * */
    explicit InventoryScreen(std::shared_ptr<Inventory>inv);


};


#endif //SEMESTRALKA_INVENTORYSCREEN_H
