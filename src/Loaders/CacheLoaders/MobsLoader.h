//
// Created by mechuon1 on 5/16/23.
//

#ifndef SEMESTRALKA_MOBSLOADER_H
#define SEMESTRALKA_MOBSLOADER_H

#include <string>

#include "../../Cache.h"

/**
 * @brief Class containing mobs loader
 * */
class MobsLoader {

public:

    /**
     * @brief static method loading mobs objects to game cache
     * @param in input string data
     * @return true if loading was successful, false if not
     *
     * */
    static bool load(std::string& in);

};


#endif //SEMESTRALKA_MOBSLOADER_H
