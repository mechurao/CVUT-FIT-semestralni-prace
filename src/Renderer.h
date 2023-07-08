//
// Created by Ondřej Měchura on 07/04/2020.
//

#include <list>
#include <unistd.h>
#include <atomic>

#include "NCursesManager.h"
#include "World.h"
#include "Entities/Player.h"


#ifndef SEMESTRALKA_RENDERER_H
#define SEMESTRALKA_RENDERER_H

/**
 * @brief Class responsible for rendering content on screeen
 * */

class Renderer{

private:

    /**
     * @brief Render thread
     * */
    std::thread thr;

    /**
     * @brief Main render function
     * @param renderer Pointer to runing renderer
     * */
    static void renderThread(Renderer* renderer);


public:

    /**
     * @brief Terminate signal
     * */
    std::atomic<bool> shouldTerminate;

    /**
     * @brief Data to render
     * */
    std::shared_ptr<World> worldData = nullptr;

    /**
     * @brief Constructor accepting data to render
     * @param world World to render
     * */
    explicit Renderer(std::shared_ptr<World> world);

    /**
     * @brief State checker
     * @return True if renderer is running, false if not
     * */
    std::atomic<bool> threadRunning;

    /**
    * @brief Continuity checker
    * @return True if renderer will be stopping, false if not
    * */
    std::atomic<bool> shouldRender{true};

    /**
     * @brief Control value to continuity check
     * */
    bool shouldBeRunning = false;

    /**
     * @brief Destructor
     * */
    ~Renderer();

    /**
     * @brief Start renderer
     * */
    void start();

    /**
     * @brief Pause renderer
     * */
    void pauseRendering();
    /**
     * @brief Resume renderer
     * */
    void resumeRendering();

    /**
     * @brief Terminate renderer
     * */
    void terminate();

};


#endif //SEMESTRALKA_RENDERER_H
