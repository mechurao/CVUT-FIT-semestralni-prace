//
// Created by mechuon1 on 3/23/23.
//

#ifndef SEMESTRALKA_GAME_H
#define SEMESTRALKA_GAME_H

#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include <unistd.h>

#include "Entities/Player.h"
#include "World.h"
#include "Controller.h"
#include "Renderer.h"
#include "Screens/InventoryScreen.h"
#include "Screens/CraftingScreen.h"
#include "Screens/MessageScreen.h"
#include "Files/FileSaver.h"
#include "Loaders/GameLoader.h"

/**
 * @brief Main game class controlling the game loop and game state
 */
class Game {
private:

    /** @brief Game running state*/
    int state = GAME_RUNNING;

    /** @brief Player object */
    Player* player;

    /** @brief Game world object */
    std::shared_ptr<World> world;

    /** @brief Renderer class */
    std::shared_ptr<Renderer> renderer;

    /** @brief Left move action */
    void leftMove();

    /** @brief Right move action */
    void rightMove();

    /** @brief Jump action */
    void jump();

    /** @brief Left action method */
    void actionLeft();

    /** @brief Right action method */
    void actionRight();

    /** @brief Up action method */
    void actionUp();

    /** @brief Down action method */
    void actionDown();

    /** @brief Terminate game and return to menu  */
    void quitGame();

    /** @brief Save game to text file */
    void saveGame();

    /** @brief Select i-th item in fast-access inventory */
    void inventorySelect(int index);

    /** @brief Select next stack in player's inventory*/
    void selectInventoryNext();

    /** @brief Select previous stack in player's inventory*/
    void selectInventoryPrev();

    /** @brief Open inventory screen */
    void openInventory();

    /** @brief Open crafting screen */
    void openCrafting();

    /** @brief Open screen */
    void openScreen( const std::shared_ptr<Screen>& screen);

public:

    /** @brief Game constructor, returning result */
    explicit Game(bool&  res);

    /** @brief Game constructor from save data */
    Game(bool& res,std::string& saveData);

    /** @brief Main game loop */
    void Run();

    /** @brief Get game save data */
    std::string toString();

    /** @brief Game destructor */
    ~Game();

};

#endif //SEMESTRALKA_GAME_H
