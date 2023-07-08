//
// Created by Ondřej Měchura on 27/03/2020.
//

#ifndef SEMESTRALKA_RUNTIME_H
#define SEMESTRALKA_RUNTIME_H



#include "Game.h"

#include "Cache.h"
#include "Screens/MainMenu.h"
#include "Screens/MessageScreen.h"


/**
 * @brief Main game running class
 * */
class Runtime {
private:

    /**
     * @brief Game main menu
     * */
    MainMenu mainMenu;

public:

    /**
     * @brief Constructor (initiates game core)
     * */
    Runtime();

};


#endif //SEMESTRALKA_RUNTIME_H
