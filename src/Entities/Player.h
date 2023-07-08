//
// Created by Ondřej Měchura on 05/05/2020.
//

#ifndef SEMESTRALKA_PLAYER_H
#define SEMESTRALKA_PLAYER_H

#include "../Inventory.h"
#include "../Cache.h"
#include "../Tools/PlayerHand.h"
#include "../Constants.h"

/**
 * @brief Predeclared classes used by Player class
 * */
class Inventory;
class PlayerHand;



/**
 * @brief Player class, representing movable player
 * */
class Player: public Entity{
private:


    /**
     * @brief shared_ptr to player inventory
     * */
    std::shared_ptr<Inventory> inventory;

    /**
     * @brief Default tool, used if selected item in inventory is empty
     * */
    std::shared_ptr<PlayerHand>hand;


public:

    /**
     * @brief Default constructor of Player (all attributes are filled with constants)
     * */
    Player();

    /**
     * @brief Player copy constructor
     * @param src reference to copied object
     * */
    Player(const Player& src);

    /**
     * @brief Player hand getter
     * @return Reference to Player's hand
     * */
    PlayerHand& getHand() ;


    /**
     * @brief Player inventory getter
     * @return shared_ptr to player's inventory
     * */
    std::shared_ptr<Inventory> getInventory();

    /**
     * @brief Print player info on screen
     * */
    void print() const;


    /**
     * @brief Overriden toString method
     * @return String representation of Player for saving purposes
     * */
    std::string toString() override;

    /**
     * @brief Overrided clone method
     * @return shared_ptr to cloned player object
     * */
    [[nodiscard]] std::shared_ptr<Entity> Clone() const override;


    /**
     * @brief Overriden player destructor (deleted player hand and inventory)
     * */
    ~Player() override;

};


#endif //SEMESTRALKA_PLAYER_H
