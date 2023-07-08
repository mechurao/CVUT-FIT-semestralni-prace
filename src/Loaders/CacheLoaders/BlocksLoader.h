//
// Created by mechuon1 on 5/16/23.
//

#ifndef SEMESTRALKA_BLOCKSLOADER_H
#define SEMESTRALKA_BLOCKSLOADER_H

#include <string>

#include "../../Cache.h"
/**
 * @brief Class containing game blocks loader
 * */
class BlocksLoader {


public:

    /**
     * @brief static method loading blocks information to game cache
     * @param in input string data
     * @return true if loading was successful, false if not
     *
     * */
    static bool load(std::string& in);

};


#endif //SEMESTRALKA_BLOCKSLOADER_H
