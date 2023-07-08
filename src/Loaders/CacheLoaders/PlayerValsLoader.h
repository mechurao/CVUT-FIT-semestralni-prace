//
// Created by mechuon1 on 5/16/23.
//

#ifndef SEMESTRALKA_PLAYERVALSLOADER_H
#define SEMESTRALKA_PLAYERVALSLOADER_H

#include <string>
#include <map>

#include "../../Constants.h"
#include "../../Utils/StringSplitter.h"
#include "../../Utils/NumberParser.h"
#include "../../Cache.h"

/**
 * @brief Class containing player constant values loader
 * */
class PlayerValsLoader {

private:
    /**
     * @brief Getter of control map, used for keys validation
     * @return map aff all supported keys and find states
     * */
    static std::map<std::string,bool> getCheckMap();

public:

    /**
     * @brief static method loading player constants to game cache
     * @param in input string data
     * @return true if loading was successful, false if not
     *
     * */
    static bool load(std::string &in);

};


#endif //SEMESTRALKA_PLAYERVALSLOADER_H
