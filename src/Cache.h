//
// Created by mechuon1 on 3/28/23.
//

#ifndef SEMESTRALKA_CACHE_H
#define SEMESTRALKA_CACHE_H

#include <map>
#include <string>
#include <optional>
#include <functional>
#include <iostream>


#include "Enums/ActionEnum.h"
#include "Files/FileReader.h"
#include "Item.h"
#include "Blocks/Block.h"
#include "Tools/Tool.h"
#include "Food/Food.h"
#include "Color.h"
#include "World.h"
#include "Entities/Mob.h"
#include "Loaders/CacheLoaders/ActionsLoader.h"
#include "Loaders/CacheLoaders/ColorLoader.h"
#include "Loaders/CacheLoaders/WorldConfigLoader.h"
#include "Loaders/CacheLoaders/PlayerValsLoader.h"
#include "Loaders/CacheLoaders/MobsLoader.h"
#include "Loaders/CacheLoaders/WorldGeneratorLoader.h"
#include "Loaders/CacheLoaders/BlocksLoader.h"
#include "Loaders/CacheLoaders/ToolsLoader.h"
#include "Loaders/CacheLoaders/FoodLoader.h"

/**
 * @class Cache
 * @brief Class to temporarily store values used by game
 */
class Cache {
private:

    /**
     * @brief Default Cache constructor
     */
    Cache() = default;


public:

    /**
     * @brief Map of colors used by game
     * */
    static std::map<int,Color> colorsMap;

    /**
     * @brief Map of all items used by game
     * */
    static std::map<int, std::shared_ptr<Item>> itemsMap;

    /**
     * @brief Map of supported game actions
     * */
    static std::map<int, Action> actions;

    /**
     * @brief World temp values
     * */
    static int world_height, default_world_width;

    /**
     * @brief Colors of default game materials
     * */
    static int bedrock_color,air_color,lava_color;

    /**
     * @brief Background theme colors
     * */
    static int day_background_color, night_background_color;

   /**
    * @brief Player values
    * */
    static int max_health, player_damage, player_color_id, jump_height, fall_damage_height;

    /**
     * @brief World generator properties
     * */
    static double min_air_alt, min_mid_alt, min_bottom_alt;
    static std::vector<int> mid_items_vec, bottom_items_vec;

   /**
    * @brief Map of mobs in game
    * */
    static std::map<int, std::shared_ptr<Entity>> mobsMap;

    /**
     * @brief Clear all data in temp
     * */
    static void clear();

    // Checking methods

    /**
     * @brief Check if item id is valid and free to use
     * @param id Item identifier to check
     * @return True if item identifier is valid, false if not
     * */
    static bool itemIdValid(int id);

    /**
     * @brief Check if entity id is valid and free to use
     * @param id Entity identifier to check
     * @return  True if entity identifier is valid, false if not
     * */
    static bool entityIdValid(int id);

    /**
     * @brief Check parse char validation
     * @param sign Parse character to check
     * @return  True if parse character is valid, false if not
     * */
    static bool parseSignValid(char sign);


/**
 * @brief Initializes data by reading a file and passing its content to a loader.
 *
 * This function uses templates and perfect forwarding to generalize the repeated pattern
 * of file reading and data loading observed in various parts of the code.
 * The Loader parameter is expected to have a static function `load` that accepts
 * a string as its final argument.
 *
 * @tparam Loader The type of the loader to use for processing the content.
 * @tparam Args The types of any additional arguments to pass to the loader.
 * @param path The path of the file to read.
 * @param args Any additional arguments to pass to the loader.
 * @return `true` if the file is successfully read and its content is successfully processed; `false` otherwise.
 */
    template<typename Loader, typename... Args>
    static bool initData(const std::string& path, Args&&... args);

/**
 * @brief Initiates all actions used in game
 * @return True if loading was successful, false if not
 * */
static bool initActions();

/**
 * @brief Initiates all values used by game world
 * @return True if loading was successful, false if not
 * */
static bool initWorldConfig();

/**
 * @brief Initiates player properties values
 * @return True if loading was successful, false if not
 * */
static bool initPlayerValues();

/**
 * @brief Initiates supported colors used for rendering content to screen
 * @return True if loading was successful, false if not
 * */
static bool initColors();

/**
 * @brief Initiates all items used by  game
 * @return True if loading was successful, false if not
 * */
static bool initItems();

/**
 * @brief Initiates values used by game generator
 * @return True if loading was successful, false if not
 * */
static bool initWorldGenerator();

/**
 * @brief Initiates all mobs  used in game
 * @return True if loading was successful, false if not
 * */
static bool initMobs();

/**
 * @brief Check if crafting and drops id's exists
 * */
static bool itemsRequirmentsValid();


/**
 * @brief Cache destructor
 * */
~Cache();

};


#endif //SEMESTRALKA_CACHE_H
