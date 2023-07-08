//
// Created by mechuon1 on 5/10/23.
//

#ifndef SEMESTRALKA_FALLDEATH_H
#define SEMESTRALKA_FALLDEATH_H

#include "Death.h"
#include "../Constants.h"



/**
 * @brief Derived PlayerDeath object, triggered if player dies by fall
 * */
class FallDeath : public Death {

public:
    /**
     * @brief Overriden cause method with message
     * @return Predefined message, special for fall death message
     * */
    std::string cause() override;

};


#endif //SEMESTRALKA_FALLDEATH_H
