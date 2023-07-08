//
// Created by mechuon1 on 5/10/23.
//

#ifndef SEMESTRALKA_DEATH_H
#define SEMESTRALKA_DEATH_H

#include <string>


/**
 * @brief Player death abstract class
 * */
class Death {
public:

    /**
     * @brief Pure virtual method returning info about this accident
     * @return Object specific death message
     * */
    virtual std::string cause() = 0;

};


#endif //SEMESTRALKA_DEATH_H
