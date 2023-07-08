//
// Created by mechuon1 on 5/10/23.
//

#include "MessageScreen.h"

using namespace std;

MessageScreen::MessageScreen(const string &message) {
    this->message = message;
}

void MessageScreen::printContent() {
    printw("%s", this->message.data());
}
