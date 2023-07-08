//
// Created by mechuon1 on 4/29/23.
//

#ifndef SEMESTRALKA_SCREEN_H
#define SEMESTRALKA_SCREEN_H

#include <map>


#include "../Controller.h"
#include "../NCursesManager.h"
#include "../Enums/ActionEnum.h"


/**
 * @brief Screen for displaying and interactiong with various content
 * */
class Screen {

private:

    /**
     * @brief Screen state (if true, screen quites)
     * */
    bool terminated = false;


protected:

    /**
     * @brief Pointer to game controller to handle user input
     * */
    Controller *controller;

    /**
     * @brief Map of screen defined actions
     * */
    std::map<Action,std::function<void()>> actions;

    /**
     * @brief Virtual base of printConent method
     * */
    virtual void printContent() = 0;

    /**
     * @brief Quit current and return to previous screen
     * */
    void quitAction();

    /**
     * @brief Virtual base for confirm action
     * */
    virtual void enterAction();

    /**
     * @brief Virtual base for action up
     * */
    virtual void actionUp();

    /**
     * @brief Virtual base for action down
     * */
    virtual void actionDown();


public:

    /**
     * @brief Screen default constructor
     * */
    Screen();

    /**
     * @brief Starts screen
     * */
    void  Run();


    /**
     * @brief Screen destructor
     * */
    ~Screen();

};


#endif //SEMESTRALKA_SCREEN_H
