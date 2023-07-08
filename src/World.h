//
// Created by Ondřej Měchura on 23.03.2023.
//

#ifndef SEMESTRALKA_WORLD_H
#define SEMESTRALKA_WORLD_H




#include <string>
#include <list>
#include <chrono>
#include <map>
#include <memory>


#include "Item.h"
#include "WorldGenerator.h"
#include "Chunk.h"
#include "Enums/MoveDirection.h"
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "Death/FallDeath.h"
#include "Death/LavaDeath.h"
#include "Loaders/WorldLoader.h"
#include "Enums/DayPhase.h"



/**
 * @brief Class containing game world
 * */
class World {
private:
    /**
     * @brief vector of entities spawned in world
     * */
    std::vector<std::shared_ptr<Entity>> entities;


    /**
     * @brief Value indicator if all was load and set up
     * */
    bool initiated = false;


    /**
     * @brief Generates and saves new world
     * */
    void initWorld();

    /**
     * @brief World day phase
     * */
    DayPhase phase = DayPhase::day;


public:
    /**
     * @brief Main player character
     * */
    Player* player = nullptr;


    /**
     * @brief Map of chunks contained in world
     * */
    std::map<int, std::shared_ptr<Chunk>> chunks;


    /**
     * @brief Default world constructor
     * */
    World();

    /**
     * @brief Constructor from save
     * @param res reference to check parameter
     * @param worldSrc save data to be loaded
     * @param mobsSrc mobs data to be loaded
     * */
    World(bool & res, std::string& worldSrc, std::string & mobsSrc);


    /**
     * @brief Spawn player to random coordinates
     * @return Pointer to spawned player
     * */
    Player* spawnPlayer();

    /**
     * @brief Spawn player to exact location
     * @param x Spawn X coordinate
     * @param y Spawn Y coordinate
     * @return Pointer to spawned player
     * */
    Player* spawnPlayer(int x, int y);

    /**
     * @brief Day phase control
     * */
    void switchDayPhase();


// moves

    /**
     * @brief Move entity up
     * @param entity Entity to move
     * */
    void moveUp(Entity* entity);

    /**
     * @brief Move entity right
     * @param entity Entity to move
     * */
    void moveRight(Entity* entity);

    /**
     * @brief Move entity left
     * @param entity Entity to move
     * */
    void moveLeft(Entity* entity);

    /**
     * @brief Simulates gravity for entity
     * @param entity Entity to fall
     * @return Count of blocks entity fell off
     * */
    int freeFall( Entity* entity) const;


    /**
     * @brief Day phase getter
     * @return Current day phase in world
     * */
    [[nodiscard]] DayPhase getPhase() const;

    /**
     * @brief Build new block in given direction
     * @param itemID Identifier of item to be placed
     * @param direction Direction to perform action
     * */
    void build(int itemID, MoveDirection direction);

    /**
     * @brief Destroy block in given direction
     * @param direction Direction to perform action
     * */
    void destroy(MoveDirection direction);

    /**
     * @brief Update content in given chunk
     * @param target Reference to chunk to update
     * */

    void updateChunkContent(std::shared_ptr<Chunk>& target) const;


    /**
     * @brief Returns reference to Item in given direction from player
     * @param player Pointer to player trigerring this action
     * @param direction Direction to perform action
     * @return reference  to element in given direction (nullopt in case of invalid direction)
     * */
    std::optional<std::reference_wrapper<std::shared_ptr<Item>>> getTarget( Player *& player, MoveDirection direction) const;

    /**
     * @brief Converts world to data string
     * @return String representation of world for saving purposes
     * */
    std::string toString();

    /**
     * @brief Converts entities spawned in world to data string
     * @return String representation of spawned entities for saving purposes
     * */
    std::string entitiesToString();

    /** @brief Returns all alive entities in world
     * @return vector of shared_pointers to all alive entities. dead entities are ignored
     * */
    std::vector<std::shared_ptr<Entity>>  getEntities();


    /**
     * @brief World destructor releasing alocated sources
     * */
    ~World();

/**
 * @brief Spawn entity to world at given coordinates
 * @param x X coordinate to spawn
 * @param entity Entity to spawn
 * */
void spawnEntity(int x,const std::shared_ptr<Entity>& entity);
};


#endif //SEMESTRALKA_WORLD_H
