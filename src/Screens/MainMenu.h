//
// Created by Ondřej Měchura on 16/05/2020.
//


#include <map>
#include <vector>
#include <iostream>


#include "../Enums/MenuOption.h"
#include "../Controller.h"
#include "MessageScreen.h"
#include "../Game.h"
#include "../Files/FileReader.h"
#include "../Constants.h"



#ifndef SEMESTRALKA_MAINMENU_H
#define SEMESTRALKA_MAINMENU_H


/**
 * @brief Main menu class - showing game options
 * */
class MainMenu: public Screen{
private:

    /**
     * @brief Supported options map
     * */
    std::map<MenuOption, std::string> optionsMap = {
            std::pair<MenuOption, std::string>(newGame, NEW_GAME_OPTION_TITLE),
            std::pair<MenuOption, std::string>(loadGame, LOAD_GAME_OPTION_TITLE),
            std::pair<MenuOption, std::string>(exitGame, EXIT_GAME_OPTION_TITLE)
    };


    /**
     * @brief Iterator to selected option
     * */
    std::map<MenuOption,std::string>::iterator selected = this->optionsMap.begin();

    /**
     * @brief Starts new game from scratch
     * */
    static void newGameAction();

    /**
     * @brief Loads saved game
     * */
    static void loadGameAction();

    /**
     * @brief  Quites program
     * */
    void quitGameAction();

    /**
     * @brief Shows error message
     * */
    static void showError();


public:

    /**
     * @brief Menu constructor
     * */
    MainMenu();

    /**
     * @brief Overriden Enter action (here for confirm selected option)
     * */
    void enterAction() override;

    /**
     * @brief  Overriden up action - here for  select previous option in menu
     * */
    void actionUp() override;

    /**
     * @brief  Overriden down action - here for  select next option in menu
     * */
    void actionDown() override;

    /**
     * @brief Print menu to terminal
     * */
    void printContent() override;


};


#endif //SEMESTRALKA_MAINMENU_H
