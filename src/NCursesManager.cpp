//
// Created by mechuon1 on 4/13/23.
//

#include "NCursesManager.h"

using namespace std;

mutex NCursesManager::ncurses_mutex;


void NCursesManager::init() {
    nodelay(stdscr,TRUE);
    curs_set(0);
    initscr();

    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr,TRUE);
    curs_set(0);


    // colors
    start_color();
    use_default_colors();

    timeout(0); // Non-blocking getch()
}




void NCursesManager::initColors() {

    for(auto& color : Cache::colorsMap){
        init_color((short )color.second.getID(), color.second.getR(),color.second.getG(),color.second.getB());
        init_pair((short )color.second.getID(),(short )color.second.getID(),(short )color.second.getID());
    }
}



void NCursesManager::lock() {
    ncurses_mutex.lock();
}

void NCursesManager::unlock() {
    ncurses_mutex.unlock();
}

void NCursesManager::refreshContent() {
    refresh();
}

void NCursesManager::terminate() {
    endwin();
}


NCursesManager::~NCursesManager() {
    ncurses_mutex.unlock();
  terminate();
}

