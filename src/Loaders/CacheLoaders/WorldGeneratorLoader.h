//
// Created by mechuon1 on 5/16/23.
//

#ifndef SEMESTRALKA_WORLDGENERATORLOADER_H
#define SEMESTRALKA_WORLDGENERATORLOADER_H

#include <string>
#include <map>

#include "../../Constants.h"
#include "../../Cache.h"

/**
 * @brief Class containing game world generator  loader
 * */
class WorldGeneratorLoader {
private:

private:
    /**
     * @brief Getter of control map, used for keys validation
     * @return map aff all supported keys and find states
     * */
    static std::map<std::string,bool> getCheckMap();
public:

    /**
     * @brief static method loading game world generator constants to game cache
     * @param in input string data
     * @return true if loading was successful, false if not
     *
     * */
    static  bool load(std::string& in);


};


#endif //SEMESTRALKA_WORLDGENERATORLOADER_H
