//
// Created by mechuon1 on 5/12/23.
//

#include "Stack.h"

using namespace std;

void Stack::print() {
    printw(STACK_PRINT_FORMAT, this->items[0]->getName().data(), (int)this->items.size());
}

string Stack::toString() {
    string content;

    for(size_t i = 0; i < this->items.size();i++){
        content+= this->items[0]->print();
    }
    return content;
}
