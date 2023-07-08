//
// Created by mechuon1 on 4/13/23.
//

#ifndef SEMESTRALKA_NCURSESMANAGER_H
#define SEMESTRALKA_NCURSESMANAGER_H


#include <ncurses.h>
#include <stdlib.h>
#include <fcntl.h>

#include "Cache.h"

/**
 * @brief Class responsible for interacting wwith NCurses library
 * */
class NCursesManager {
private:

    /**
     * @brief Mutex to protect critical zone
     * */
    static std::mutex ncurses_mutex;


public:

    /**
     * @brief NCurses copy constructor
     * */
    NCursesManager(const NCursesManager &) = delete;

    /**
     * @brief Overriden = operator
     * */
    NCursesManager &operator=(const NCursesManager &) = delete;

    /**
     * @brief Initialize all used colors
     * */
    static void initColors();

    /**
     * @brief Init NCurses library
     * */
    static void init();


    /**
     * @brief Lock critical section
     * */
    static void lock();

    /**
     * @brief Unlock critical section
     * */
    static void unlock();

    /**
     * @brief Refresh screen content
     * */
    static void refreshContent();

    /**
     * @brief Terminate ncurses
     * */
    static void terminate();

    /**
     * @brief Destructor
     * */
    ~NCursesManager();

};


#endif //SEMESTRALKA_NCURSESMANAGER_H
