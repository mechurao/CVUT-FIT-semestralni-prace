//
// Created by mechuon1 on 5/10/23.
//

#ifndef SEMESTRALKA_HUNGRYDEATH_H
#define SEMESTRALKA_HUNGRYDEATH_H


#include "Death.h"
#include "../Constants.h"


/**
 * @brief Derived PlayerDeath object, triggered if player starves to death
 * */
class HungryDeath : public Death {
public:

    /**
     * @brief Overriden cause method with message
     * @return Predefined message, special for starving death message
     * */
    std::string cause() override;

};


#endif //SEMESTRALKA_HUNGRYDEATH_H
