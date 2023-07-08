//
// Created by mechuon1 on 5/15/23.
//

#ifndef SEMESTRALKA_LAVADEATH_H
#define SEMESTRALKA_LAVADEATH_H

#include "Death.h"
#include "../Constants.h"

/**
 * @brief Derived PlayerDeath object, triggered if player steps on lava
 * */
class LavaDeath: public Death{

public:

    /**
     * @brief Overriden cause method with message
     * @return Predefined message, special for player death by stepping on lava
     * */
    std::string cause() override;

};


#endif //SEMESTRALKA_LAVADEATH_H
