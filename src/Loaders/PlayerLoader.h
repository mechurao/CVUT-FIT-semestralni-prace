//
// Created by mechuon1 on 5/16/23.
//

#ifndef SEMESTRALKA_PLAYERLOADER_H
#define SEMESTRALKA_PLAYERLOADER_H

#include <string>
#include "../World.h"
#include "../Entities/Player.h"

/**
 * @class PlayerParser
 * @brief Class responsible for parsing player data
 */
class PlayerLoader {
public:
    /**
     * @brief Parses the saved player data string
     *
     * @param playerData String containing the saved player data
     * @param world Shared pointer to the World object
     * @param player Double pointer to the Player object
     * @return true if parsing was successful, false otherwise
     */
    static bool loadPlayer(std::string& playerData, std::shared_ptr<World>& world, Player *&player);
};

#endif //SEMESTRALKA_PLAYERLOADER_H
