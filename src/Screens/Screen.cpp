//
// Created by mechuon1 on 4/29/23.
//

#include "Screen.h"

using namespace std;

Screen::Screen() {
    this->controller = new Controller();
    this->actions.insert({Action::controlQuit, [this]{quitAction();}});
    this->actions.insert({Action::controlEnter,[this]{enterAction();}});
    this->actions.insert({Action::actionUp,[this]{actionUp();}});
    this->actions.insert({Action::actionDown,[this]{actionDown();}});
}

void Screen::quitAction() {
    this->terminated = true;
}
void Screen::enterAction() {}

void Screen::actionUp() {}

void Screen::actionDown() {}



void  Screen::Run() {
    printContent();

    while (!terminated){
        auto action = this->controller->getAction();
        if(action != nullopt){
            auto opt = this->actions.find(action.value());
            if(opt != this->actions.end()){
                clear();

                // trigger found action
             opt->second();
             printContent();
             refresh();
            }
        }
    }

}







Screen::~Screen() {
    delete this->controller;
}





