//
// Created by mechuon1 on 5/16/23.
//

#ifndef SEMESTRALKA_GAMELOADER_H
#define SEMESTRALKA_GAMELOADER_H

#include <string>
#include "../World.h"
#include "../Entities/Player.h"
#include "../Utils/NumberParser.h"
#include "../Utils/StringSplitter.h"
#include "PlayerLoader.h"

/**
 * @class GameLoader
 * @brief Class responsible for loading game data to cache
 */
class GameLoader {
private:
    /**
     * @brief Parses the saved world data string
     *
     * @param worldSrc String containing the saved world data
     * @param mobsSrc String containing the saved mobs data
     * @param world Shared pointer to the World object
     * @return true if parsing was successful, false otherwise
     */
    static bool loadWorld(std::string& worldSrc, std::string& mobsSrc, std::shared_ptr<World>& world);

public:
    /**
     * @brief Parses the saved game data string
     *
     * @param saveData String containing the saved game data
     * @param world Shared pointer to the World object
     * @param player Pointer to the Player object
     * @return true if parsing was successful, false otherwise
     */
    static bool loadGame(std::string& saveData, std::shared_ptr<World>& world, Player *&player);
};

#endif //SEMESTRALKA_GAMELOADER_H
