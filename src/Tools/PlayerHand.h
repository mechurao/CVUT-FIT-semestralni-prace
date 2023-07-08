//
// Created by mechuon1 on 4/24/23.
//

#ifndef SEMESTRALKA_PLAYERHAND_H
#define SEMESTRALKA_PLAYERHAND_H

#include "../Color.h"
#include "Tool.h"
#include "../Cache.h"

/**
 * @brief Class representing Player's hand (default tool), which is always available
 * */
class PlayerHand : public Tool{
public:

    /**
     * @brief Player hand constructor (all atributes are filled as constants)
     * */
    PlayerHand();

    /**
     * @brief Copy constructor
     * @param src Reference to copied player hand
     * */
    PlayerHand(const PlayerHand& src);


    /**
     * @brief overriden decrease durability (player hand has unlimited durability)
     * @param val durabilitu to decrease (has no effect in this case)
     * */
    void decreaseDurability(int val) override;

    /**
     * @brief Overriden Clone method
     * @return Pointer to newly created PlayerHand object
     * */
    [[nodiscard]] std::shared_ptr<Item> Clone() const override;


};


#endif //SEMESTRALKA_PLAYERHAND_H
