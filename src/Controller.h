//
// Created by Ondřej Měchura on 20/04/2020.
//

#ifndef SEMESTRALKA_CONTROLLER_H
#define SEMESTRALKA_CONTROLLER_H


#include <optional>


#include "Enums/ActionEnum.h"
#include "NCursesManager.h"

/**
 * @brief Class to handle user key input
 * */
class Controller{

public:

    /**
     * @brief Get action from Cache based on pressed key
     * @return If Action is supported and found, it's enum representation is returned, otherwise result is nullopt
     * */
    static std::optional<Action> getAction();
};

#endif //SEMESTRALKA_CONTROLLER_H
