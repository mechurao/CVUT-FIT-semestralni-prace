//
// Created by Ondřej Měchura on 22/04/2020.
//

#include "Timer.h"


using namespace std;

// Timer.cpp
void Timer::timerThreadFunction() {
    auto startTime = chrono::steady_clock::now();
    auto targetTime = startTime + secs;

    while (chrono::steady_clock::now() < targetTime) {
        if (shouldTerminate) {
            isRunning = false;
            return;
        }
        this_thread::sleep_for(chrono::milliseconds(JUMP_TIME_INTERVAL_MS));
    }

    callback();
    isRunning = false;
}

Timer::Timer(chrono::milliseconds secs, function<void()> callback)
        : secs(secs), callback(std::move(callback)), isRunning(false), shouldTerminate(false) {
}

void Timer::start() {
    lock_guard<mutex> lock(mtx);
    if (isRunning) {
        return;
    }
    isRunning = true;
    if (timerThread.joinable()) {
        timerThread.join();
    }
    timerThread = thread([this] { timerThreadFunction(); });
}



void Timer::terminate() {
    {
        lock_guard<mutex> lock(mtx);
        shouldTerminate = true;
    }
    if (timerThread.joinable()) {
        timerThread.join();
    }
    isRunning = false;
}

bool Timer::running() const {
    return isRunning;
}




