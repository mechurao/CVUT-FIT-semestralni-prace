//
// Created by mechuon1 on 5/10/23.
//

#ifndef SEMESTRALKA_MESSAGESCREEN_H
#define SEMESTRALKA_MESSAGESCREEN_H

#include "Screen.h"

/**
 * @brief Screen for display warning or other messages
 * */
class MessageScreen: public Screen{
private:

    /**
     * @brief Displayed message
     * */
    std::string message;

public:

    /**
     * @brief MessageScreen constructor
     * @param message Message to show
     * */
    explicit MessageScreen(const std::string & message);

    /**
     * @brief Overriden printcontent content method - here to just print message to terminal
     * */
    void printContent() override;



};


#endif //SEMESTRALKA_MESSAGESCREEN_H
