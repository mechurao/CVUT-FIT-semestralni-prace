//
// Created by mechuon1 on 5/17/23.
//

#ifndef SEMESTRALKA_TOOLSLOADER_H
#define SEMESTRALKA_TOOLSLOADER_H

#include <string>

#include "../../Utils/StringSplitter.h"
#include "../../Utils/NumberParser.h"
#include "../../Cache.h"

/**
 * @brief Class containing tools loader
 * */
class ToolsLoader {
public:

    /**
     * @brief static method loading tools objects  to game cache
     * @param in input string data
     * @return true if loading was successful, false if not
     *
     * */
    static bool load(std::string &in);

};


#endif //SEMESTRALKA_TOOLSLOADER_H
