//
// Created by mechuon1 on 4/24/23.
//

#ifndef SEMESTRALKA_BLOCK_H
#define SEMESTRALKA_BLOCK_H

#include <string>
#include <vector>

#include "../Item.h"



/**
 * @brief Base Block class, itherited from abstract Item class
 * */
class Block : public Item {

public:

    /**
     * @brief Block constructor accepting its attributes
     * */
    Block(int id, const std::string& name, char print, const std::vector<int>&dropItems, int itemColor, double itemProbability);


    /**
     * @brief Block constructor enlarged with crafting requirments
     * */
    Block(int id, const std::string& name, char print,const std::vector<int>&dropItems, int itemColor, double itemProbability, std::vector<int>&crafting);



    /**
     * @brief Block copy constructor (set default, nothing special is required here)
     * @param src source block to copy data from
     * */
    Block(const Block& src) = default;

    /**
     * @brief Overriden method for  item use (in this case current block is removed from inventory and replaced by another one)
     * @param world Reference to World, containing this block
     * @param player Reference to player, which is using this
     * @param direction Direction of performed action
     * @return vector of items obtained by this action
     * */
    std::vector<int> useItem(std::shared_ptr<World>& world, Player*& player, MoveDirection direction) override;

    /**
     * @brief Overriden clone method
     * @return shared_ptr to newly created Block
     * */
    [[nodiscard]] std::shared_ptr<Item> Clone()const override;

};






#endif //SEMESTRALKA_BLOCK_H
