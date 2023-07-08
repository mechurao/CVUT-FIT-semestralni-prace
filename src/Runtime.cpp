//
// Created by Ondřej Měchura on 27/03/2020.
//

#include "Runtime.h"

using namespace std;


Runtime::Runtime() {

    // init ncurses
    NCursesManager::init();


    bool allOK = true;

    bool colorsCheck = Cache::initColors();
    bool controlsCheck = Cache::initActions();
    bool worldValsCheck = Cache::initWorldConfig();
    bool playerCheck = Cache::initPlayerValues();

    bool itemsCheck = Cache::initItems();
    bool worldGeneratorCheck = Cache::initWorldGenerator();
    bool mobsCheck = Cache::initMobs();

    string errorTemp;

    if(!colorsCheck){ errorTemp += COLOR_PARSING_ERROR;allOK = false;}
    if(!itemsCheck){ errorTemp += ITEMS_PARSING_ERROR;allOK = false;}
    if(!controlsCheck){errorTemp+= CONTROLS_PARSING_ERROR;allOK = false;}
    if(!worldValsCheck){errorTemp += WORLD_VALS_PARSING_ERROR;allOK = false;}
    if(!playerCheck){errorTemp+=PLAYER_PARSING_ERROR;allOK = false;}
    if(!worldGeneratorCheck){ errorTemp+=WORLD_GENERATOR_PARSING_ERROR; allOK = false;}
    if(!mobsCheck){ errorTemp+=MOBS_PARSING_ERROR;allOK = false;}


     NCursesManager::initColors();

    if(allOK && Cache::itemsRequirmentsValid()){

         MainMenu menu = MainMenu();
         menu.Run();

     }else{
         MessageScreen screen = MessageScreen(errorTemp);
         screen.Run();
     }

     // clear temp
    Cache::clear();

    // finish ncurses
    NCursesManager::terminate();

}

