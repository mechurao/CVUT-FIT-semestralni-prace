//
// Created by mechuon1 on 5/16/23.
//

#ifndef SEMESTRALKA_COLORLOADER_H
#define SEMESTRALKA_COLORLOADER_H

#include <string>
#include "../../Utils/StringSplitter.h"
#include "../../Utils/NumberParser.h"
#include "../../Constants.h"
#include "../../Color.h"
#include "../../Cache.h"

/**
 * @brief Class containing game colors loader
 * */
class ColorLoader {
public:

    /**
     * @brief static method loading colors information  to game cache
     * @param in input string data
     * @return true if loading was successful, false if not
     *
     * */
    static bool load(std::string& in);

};


#endif //SEMESTRALKA_COLORLOADER_H
