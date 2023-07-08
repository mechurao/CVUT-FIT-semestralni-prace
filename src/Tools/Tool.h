//
// Created by mechuon1 on 4/24/23.
//

#ifndef SEMESTRALKA_TOOL_H
#define SEMESTRALKA_TOOL_H

#include <string>

#include "../Color.h"
#include "../Item.h"


/**
 * @brief Class representing tool, which can interact with game world
 * */
class Tool : public Item {

public:

    /**
     * @brief Primary  tool constructor
     * @param identifier Unique item identifier
     * @param itemName Item name
     * @param print Unique print char for saving purposes
     * @param dur Tool durability
     * @param dmg Tool damage
     * @param itemColor Identifier of color used for rendering
     * @param itemProbability Tool drop probability
     * */
    Tool(int identifier, const std::string &itemName, char print,int dur, int dmg, int itemColor, double itemProbability);


    /**
     * @brief Secondary  tool constructor
     * @param identifier Unique item identifier
     * @param itemName Item name
     * @param print Unique print char for saving purposes
     * @param dur Tool durability
     * @param dmg Tool damage
     * @param itemColor Identifier of color used for rendering
     * @param itemProbability Tool drop probability
     * @param crafting vector of item identifiers, required to craft current item
     * */
    Tool(int identifier, const std::string &itemName, char print,int dur, int dmg, int itemColor, double itemProbability,std::vector<int>&crafting);

    /**
     * @brief Tool copy constuctor
     * @param src Reference to copied object
     * */
    Tool(const Tool &src) = default;



    /**
     * @brief Overriden useItem method. In this case interacts with game world, can break blocks and deal damage to entities
     * @param world Reference to owner world
     * @param player Reference to player, owning this object
     * @param direction Direction to perform action
     * @return Vector of item identifiers of items dropped from broken objects
     * */
    std::vector<int> useItem(std::shared_ptr<World>& world, Player *& player, MoveDirection direction) override;

    /**
     * @brief Overriden stackable method
     * @return False, Tools are never stackable
     * */
    [[nodiscard]] bool isStackable() const override;

    /**
     * @brief Overriden clone method
     * @return Smart pointer of newly created Tool
     * */
    [[nodiscard]] std::shared_ptr<Item> Clone() const override;

};


#endif //SEMESTRALKA_TOOL_H
