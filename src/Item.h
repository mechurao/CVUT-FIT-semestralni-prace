//
// Created by Ondřej Měchura on 02/05/2020.
//

#ifndef SEMESTRALKA_ITEM_H
#define SEMESTRALKA_ITEM_H



#include <vector>
#include <map>
#include <memory>
#include <string>


#include "Color.h"
#include "Enums/MoveDirection.h"
#include "Entities/Entity.h"


/** Predeclared  classes */
class Player;
class Entity;
class World;
class Item;



/**
 * @brief Item base class, containing on of the main game units
 * */
class Item {
private:

    /**
     * @brief Item identifier
     * */
    int id;

    /**
     * @brief Item name
     * */
    std::string name;

    /**
     * @brief Init crafting requirments map
     * @param input vector of crafting requirments identifiers
     * */
    void initCraftingReq(std::vector<int>& input);

protected:


    /**
     * @brief Unique char used for printing and parsing operations
     * */
    char printChar;

    /**
     * @brief Item durability (decrease by use)
     * */
    int durability = 1;

    /**
     * @brief Durability information for saving purposes
     * */
    int origDurability = 1;

    /**
     * @brief Damage dealt to another item/mob
     * */
    int damage = 1;

    /**
     * @brief Item color ID for rendering usage
     *  */
    int colorID;

    /**
     * @brief Item drop probability
     * */
    double probability;

    /**
     * @brief Map of item crafting requirments (id,amount)
     * */
    std::map<int,int> craftingReq;

    /**
     * @brief Vector of items identifiers dropped by item
     * */
    std::vector<int>drops;

    /**
     * @brief Entity staying on Item
     * */
    Entity* spawnedEntity = nullptr;


public:


    /**
     * @brief Default item constructor
     * @param id Unique item identifier
     * @param name Item name
     * @param printChar Unique item character for saving purposes
     * @param itemColor Identifier of item color, used for rendering
     * @param dropProbability Item drop probability
     * */
    Item(int id, const std::string& name, char printChar, int itemColor, double dropProbability);

    /**
     * @brief Item constructor with added crafting requirments
     * @param id Unique item identifier
     * @param name Item name
     * @param printChar Unique item character for saving purposes
     * @param itemColor Identifier of item color, used for rendering
     * @param dropProbability Item drop probability
     * @param craft Vector of crafting required items identifiers
     * */
    Item(int id, const std::string& name, char printChar, int itemColor, double dropProbability, std::vector<int>& craft);

    /**
     * @brief Item copy constructor
     * @param src Reference to copied item
     * */
    Item(const Item& src);


    /**
     * @brief Iten identifier getter
     * @return Item identifier
     * */
    [[nodiscard]] int getId()const;

    /**
     * @brief Item name getter
     * @return Returns name of item
     * */
    [[nodiscard]] std::string getName() const;

    /**
     * @brief Item spawn probability getter
     * @return Item spawn probability
     * */
    [[nodiscard]] double getSpawnProbability()const;

    /**
     * @brief Item durability getter
     * @return Item current durability
     * */
    [[nodiscard]] int getDurability() const;

    /**
     * @brief Item color identifier getter
     * @return Item Color identifier for rendering purpose
     * */
    [[nodiscard]] int getColorID() const;

    /**
     * @brief Set entity to item
     * @param entity Entity to set on
     * */
    virtual void visit(Entity * entity);

    /**
     * @brief Remove entity from item
     * */
    void leave();

    /**
     * @brief Returns reference to spawned entity
     * @return Pointer to spawned entity
     * */
    [[nodiscard]] Entity* getSpawnedEntity() const;


    /**
     * @brief Item crafting requirments getter
     * @return Item ideftifiers required to crafting in (itemID,amount) format
     * */
    [[nodiscard]] std::map<int,int> getCraftingRequirments()const;

    /**
     * @brief Item drops getter
     * @return Vector of item identifiers dropped on item break
     * */
    [[nodiscard]] std::vector<int> getDrops() const;


    /**
     * @brief Decreases item durability by given value
     * @param value Durability value to decrees
     * */
    virtual void decreaseDurability(int value);


    /**
     * @brief Checks if item can be added to stack
     * @return True if item is collectible to stack
     * */
    [[nodiscard]] virtual bool isStackable()const;

    /**
     * @brief Check if item can be visited by entity
     * @return True in case of solid object
     * */
    [[nodiscard]] virtual bool isCrossable()const;

    /**
     * @brief Virtual base of useItem method
     * @param world Reference to owner world of item
     * @param player Reference to player interactiong with item
     * @param direction Direction where to perform action
     * @return Vector of returned items identifiers
     * */
    virtual std::vector<int> useItem(std::shared_ptr<World>& world, Player *& player, MoveDirection direction) {return {};};

    /**
     * @brief Item print character getter
     * @return Item print character por saving and rendering purposes
     * */
    [[nodiscard]] char print()const;

    /**
     * @brief Virtual base of Clone method
     * */
    [[nodiscard]] virtual std::shared_ptr<Item> Clone() const = 0;

    /**
     * @brief Inventory amount checker
     * @param src Inventory in (itemID, amount) format
     * @return True if item can be made from items contained in inventory, false otherwise
     * */
    [[nodiscard]] bool amountMatching(const std::map<int,int>& src) const;


    /**
     * @brief Item destructor
     * */
    virtual ~Item()= default;
};






#endif //SEMESTRALKA_ITEM_H
