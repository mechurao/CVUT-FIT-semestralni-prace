//
// Created by mechuon1 on 5/12/23.
//

#ifndef SEMESTRALKA_STACK_H
#define SEMESTRALKA_STACK_H

#include "Item.h"
#include "NCursesManager.h"

#include "Constants.h"

/**
 * @brief Class to store items in game inventory
 * */
struct Stack {

    /**
     * @brief ID of item contained in stack
     * */
    int id;

    /**
     * @brief Vector of stored items
     * */
    std::vector<std::shared_ptr<Item>> items;

    /**
     * @brief Prints stack content to screen
     * */
    void print();

    /**
     * @brief Formats stack content to data string
     * @return String stack representation for saving purposes
     * */
    std::string toString();

    /**
     * @brief Default stack desctructor
     * */
    ~Stack() = default;

};


#endif //SEMESTRALKA_STACK_H
