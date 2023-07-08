//
// Created by mechuon1 on 5/16/23.
//

#ifndef SEMESTRALKA_ACTIONSLOADER_H
#define SEMESTRALKA_ACTIONSLOADER_H

#include <string>
#include <optional>

#include "../../Enums/ActionEnum.h"
#include "../../Constants.h"
#include "../../Utils/StringSplitter.h"
#include "../../Utils/NumberParser.h"
#include "../../Cache.h"

/**
 * @brief Class containing actions loader
 * */
class ActionsLoader {
private:

    /**
     * @brief Find action by given string
     * @param in input string
     * @return Action if given string key is recognized and supported. Otherwise returns nullopt
     * */
    static std::optional<Action> getAction(const std::string& in);


public:

    /**
     * @brief static method loading actions information to game cache
     * @param in input string data
     * @return true if loading was successful, false if not
     *
     * */
    static bool load(std::string& in);

};


#endif //SEMESTRALKA_ACTIONSLOADER_H
