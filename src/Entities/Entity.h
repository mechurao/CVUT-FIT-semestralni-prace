//
// Created by mechuon1 on 4/29/23.
//

#ifndef SEMESTRALKA_ENTITY_H
#define SEMESTRALKA_ENTITY_H

#include <vector>
#include <map>
#include <string>
#include <unistd.h>


#include "../Chunk.h"
#include "../Timer.h"
#include "../Death/Death.h"
#include "../Enums/DayPhase.h"

/**
 * @brief Constant showing entity jump duration in miliseconds
 * */
#define JUMP_DURATION_MS 500


/**
 * @brief Predeclared classes
 * */
class Item;

class World;

class Chunk;


/**
 * @brief Base class of entity spawned to world
 * */
class Entity {
protected:

    /**
     * @brief Entity ID
     * */
    int id;

    /**
     * @brief Unique entity char for saving purposes
     * */
    char printChar;

    /**
     * @brief Entity name
     * */
    std::string name;

    /**
     * @brief Entity health
     * */
    int health;

    /**
     * @brief Pointer to entity home world
     * */
    World *world = nullptr;

    /**
     * @brief Spwan probability of entity (used for spawning to world)
     * */
    double spawnProbability;

    /**
     * @brief Entity color identifier
     * */
    int colorID;

public:

    /**
     * @brief Exact entity Y coordinate
     * */
    int y = 0;

    /**
     * @brief Entity home world iterator containing position where entity is located on (first is X coordinate of player)
     * */
    std::map<int, std::shared_ptr<Chunk>>::iterator currentChunk;

    /**
     * @brief Vector of entity drop items (dropped if entity is killed)
     * */
    std::vector<int> drops;


    /**
     * @brief Main entity constructor
     * @param id Unique entity identifier
     * @param name Entity name
     * @param printChar Unique character used for saving purposes
     * @param health Entity health
     * @param color Color identifier  used to render on screen
     * @param probability Entity spawn probability
     * */
    Entity(int id, const std::string &name, char printChar, int health, int color, double probability);

    /**
     * @brief Enlarged entity constructor with drops
     * @param id Unique entity identifier
     * @param name Entity name
     * @param printChar Unique character used for saving purposes
     * @param health Entity health
     * @param color Color identifier  used to render on screen
     * @param drops Vector of items identifiers dropped if entity is killed
     * @param probability Entity spawn probability
     * */
    Entity(int id, const std::string &name, char printChar, int health, int color, const std::vector<int> &drops,
           double probability);

    /**
     * @brief Entity copy constructor
     * @param src Reference to copied  Entity
     * */
    Entity(const Entity &src);


    /**
     * @brief Entity jump timer, running on parallel thread if Entity jumped. When Runs out, free fall method is triggered
     * */
    std::shared_ptr<Timer> jumpTimer;

    /** Entity death shared_ptr (default null of course)*/
    std::shared_ptr<Death> death = nullptr;

    /**
     * @brief virtual method to spawn entity to home world
     * @param homeWorld pointer to Entity home world
     * @param pos iterator containing Entity location
     * @param yCoord Default entity Y coordinate
     * */
    virtual void spawn(World *homeWorld, std::map<int, std::shared_ptr<Chunk>>::iterator &pos, int yCoord);

    /**
     * @brief Move entity up
     * */
    void moveUp();

    /**
     * @brief Move entity right
     * */
    void moveRight();

    /**
     * @brief Move entity left
     * */
    void moveLeft();

    /**
     * @brief Move entity in random direction
     * */
    void moveRandom();

    /**
     * @brief Free fall of entity
     * */
    void freeFall();

    /**
     * @brief Removes certain  health points from entity
     * @param damage count of health points to be removed
     * */
    void hurt(int damage);

    /**
     * @brief Check is entity is dead
     * @return true if entity hp equals 0
     * */
    [[nodiscard]] bool isDead() const;

    /**
     * @brief Restores hp to entity of given amount
     * @param hp Count of health points to be restored
     * */
    void restoreHP(int hp);


    /**
     * @brief Entity identifier getter
     * @return Identifier of entity
     * */
    [[nodiscard]] int getID() const;

    /**
     * @brief Entity color identifier getter
     * @return Identifier of entity color
     * */
    [[nodiscard]] int color() const;

    /**
     * @brief Entity spawn probability getter
     * @return Entity probability to spawn
     * */
    [[nodiscard]] double getSpawnProbability() const;


    /**
     * @brief Entity print char getter
     * @return Unique entity print character
     * */
    [[nodiscard]] char getPrintChar() const;

    /**
      * @brief Check entity activity during given day phase
      * @param phase Day phase to check
      * @return True if Entity is active during this period, otherwise false
      * */
    virtual bool isActive(DayPhase phase);


    /**
     * @brief Virtual base for entity clone method
     * */
    [[nodiscard]] virtual std::shared_ptr<Entity> Clone() const = 0;

    /**
     * @brief Returns string representation of entity for saving purposes
     * @return data of entity formatted to string
     * */
    virtual std::string toString();

    /**
     * @brief Virtual entity destructor
     * */
    virtual ~Entity();

};


#endif //SEMESTRALKA_ENTITY_H
