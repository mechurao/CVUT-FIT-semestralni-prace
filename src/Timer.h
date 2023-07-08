// Created by Ondřej Měchura on 22/04/2020.
//

#ifndef SEMESTRALKA_TIMER_H
#define SEMESTRALKA_TIMER_H


#include <chrono>
#include <functional>
#include <thread>
#include <mutex>

#include "Constants.h"

/**
 * @brief Timer class (measuring time in parallel thread)
 * */
class Timer {

private:

    /**
     * @brief Main timer function
     * */
    void timerThreadFunction();

    /**
     * @brief Time interval to run in seconds
     * */
    std::chrono::milliseconds secs;

    /**
     * @brief Callback action to be triggered after timer finishes
     * */
    std::function<void()> callback;

    /**
     * @brief Check if timer is running
     * */
    bool isRunning;

    /**
     * @brief Check if Timer should terminate
     * */
    bool shouldTerminate;

    /**
     * @brief Timer mutex
     * */
    std::mutex mtx;

    /**
     * @brief Thread for timer
     * */
    std::thread timerThread;

public:

    /**
     * @brief Default Timer constructor
     * @param secs Time interval to run
     * @param callback Action to be triggered after finishing timer
     * */
    Timer(std::chrono::milliseconds secs, std::function<void()> callback);

    /**
     * @brief Start timer
     * */
    void start();


    /**
     * @brief Stop running timer
     * */
    void terminate();

    /**
     * @brief Timer state checker
     * @return True if timer is still running, false if not
     * */
    [[nodiscard]] bool running() const;
};


#endif //SEMESTRALKA_TIMER_H
