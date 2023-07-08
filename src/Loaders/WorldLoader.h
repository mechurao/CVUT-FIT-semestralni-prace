//
// Created by Ondřej Měchura on 16.05.2023.
//

#ifndef SEMESTRALKA_WORLDLOADER_H
#define SEMESTRALKA_WORLDLOADER_H

#pragma once
#include "../World.h"
#include <string>
#include <map>
#include <memory>

/**
 * @brief The WorldParser class is used to load and parse the world and entities from text data.
 */
class WorldLoader {
public:
    /**
     * @brief Loads and parses the world from text data.
     *
     * @param world Instance of the World class where the loaded world will be stored.
     * @param worldData Text data containing information about the world.
     * @return Returns true if the world load and parse was successful, otherwise false.
     */
    static bool loadWorld(World &world, std::string &worldData);

    /**
     * @brief Loads and parses the entities from text data.
     *
     * @param world Instance of the World class where the loaded entities will be stored.
     * @param src Text data containing information about the entities.
     * @return Returns true if the entities load and parse was successful, otherwise false.
     */
    static bool loadMobs(World &world, std::string &src);
private:
    static std::map<char, std::shared_ptr<Item>> createTempItemsCharMap();
    static std::map<char, std::shared_ptr<Entity>> createTempMobsMap();
};

#endif //SEMESTRALKA_WORLDLOADER_H
