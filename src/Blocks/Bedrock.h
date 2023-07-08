//
// Created by mechuon1 on 4/22/23.
//

#ifndef SEMESTRALKA_BEDROCK_H
#define SEMESTRALKA_BEDROCK_H

#include "Block.h"
#include "../Cache.h"



/**
 * @brief Default unbreakable material placed on world's borders
 * */
class Bedrock :public Block{

public:

    /**
     * @brief Default constructor - all attributes are filled by constant values
     * */
    Bedrock();

    /**
     * @brief Overriden decrease durability method to do nothing (makes bedrock unbreakable)
     * */
    void decreaseDurability(int value) override;

};


#endif //SEMESTRALKA_BEDROCK_H
