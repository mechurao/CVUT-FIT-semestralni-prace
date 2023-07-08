//
// Created by Ondřej Měchura on 20/04/2020.
//

#include "Controller.h"

using namespace std;

optional<Action> Controller::getAction(){
    NCursesManager::lock();
    int ch = getch();
    NCursesManager::unlock();
    auto it = Cache::actions.find(ch);
    if(it == Cache::actions.end()){return nullopt;}
    return  it->second;
}
