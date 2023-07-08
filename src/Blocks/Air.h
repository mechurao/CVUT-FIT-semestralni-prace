//
// Created by mechuon1 on 4/22/23.
//

#ifndef SEMESTRALKA_AIR_H
#define SEMESTRALKA_AIR_H


#include "Block.h"
#include "../Cache.h"


/**
 * @brief Default "null" material. When another block is destroyed, this will take it's place.
 *        Also changes color, depending on day phase in game
 * */
class Air : public Block{
public:

    /**
     * @brief Default constructor (all attributes are filled by constant values)
     * */
    Air();

    /**
     * @brief Overriden crossable state checker
     * @return Returns false only if any entity is contained. Otherwise returns true
     * */
    [[nodiscard]] bool isCrossable()const override;

    /**
     * @brief Overriden Clone method
     * @return shared_ptr to newly created Air block
     * */
    [[nodiscard]] std::shared_ptr<Item> Clone() const override;


};


#endif //SEMESTRALKA_AIR_H
