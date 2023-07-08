//
// Created by mechuon1 on 5/2/23.
//

#ifndef SEMESTRALKA_FOOD_H
#define SEMESTRALKA_FOOD_H

#include "../Item.h"
#include "../Entities/Player.h"
#include "../Death/HungryDeath.h"

/**
 * @brief Class representing food, eatable by player
 * */
class Food : public Item {
private:

    /**
     * @brief Player HP restored by food
     * */
    int restoreHP;

public:

    /**
     * @brief Main food constructor
     * @param identifier Unique item identifier
     * @param itemName Name of item
     * @param print Print character used for saving purposes
     * @param hp amount of health points restored by food
     * @param itemColor Unique identifier of item color, used for rendering
     * @param dropProbability Drop probability of item
     * */
    Food(int identifier, const std::string &itemName, char print,int hp, int itemColor, double dropProbability);

    /**
     * @brief Enlarged  food constructor
     * @param identifier Unique item identifier
     * @param itemName Name of item
     * @param print Print character used for saving purposes
     * @param hp amount of health points restored by food
     * @param itemColor Unique identifier of item color, used for rendering
     * @param dropProbability Drop probability of item
     * @param crafting vector of items identifiers, required to make an item
     * */
    Food(int identifier, const std::string &itemName, char print,int hp, int itemColor, double dropProbability, std::vector<int>& crafting);

    /**
     * @brief Food copy constuctor
     * @param src reference of copied item
     * */
    Food(const Food &src);


    /**
     * @brief Overriden useItem method (in this case restoring player's health by given restoreHp amount)
     * @param world reference to owner world
     * @param player pointer to player using this item
     * @param direction direction of action perform
     * @return vector of obtained items identifiers
     * */
    std::vector<int> useItem(std::shared_ptr<World>& world, Player*& player, MoveDirection direction) override;

    /**
     * @brief Overrided clone method
     * @return shared_ptr no newly created food item
     * */
    [[nodiscard]] std::shared_ptr<Item> Clone() const override;

};


#endif //SEMESTRALKA_FOOD_H
