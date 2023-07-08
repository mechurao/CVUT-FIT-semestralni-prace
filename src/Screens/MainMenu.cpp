//
// Created by Ondřej Měchura on 16/05/2020.
//

#include "MainMenu.h"




MainMenu::MainMenu()= default;

void MainMenu::newGameAction() {
    bool res;
    auto game = new Game(res);
    game->Run();
    delete game;
}

void MainMenu::loadGameAction() {
    string save;

    bool check = FileReader::readFile(SAVE_FILE_NAME,save);

    if(!check){
        MainMenu::showError();
        return;
    }

    bool res;
    auto game = new Game(res,save);

    if(!res){
        delete game;
        MainMenu::showError();
        return;
    }

    game->Run();
    delete game;
}

void MainMenu::quitGameAction() {
    this->quitAction();
}


void MainMenu::enterAction() {
    switch (this->selected->first) {
        case MenuOption::newGame:newGameAction();
            break;
        case MenuOption::loadGame:loadGameAction();
            break;
        case MenuOption::exitGame:quitGameAction();
            break;
    }
}



void MainMenu::actionDown() {

    if(next(this->selected) == this->optionsMap.end()){
        this->selected = this->optionsMap.begin();
        return;
    }
    this->selected++;
}

void MainMenu::actionUp() {
    if(this->selected == this->optionsMap.begin()){
        this->selected = prev(this->optionsMap.end());
        return;
    }
    this->selected--;
}
void MainMenu::showError() {
    MessageScreen screen = MessageScreen("Failure");
    screen.Run();
    clear();
}


void MainMenu::printContent() {

    for (auto &i : this->optionsMap){
        printw("%s",i.second.data());
        if(i.first == this->selected->first){ printw("%c",MENU_SELECT_MARK);}
        printw("\n");
    }
}




