//
// Created by mechuon1 on 4/22/23.
//

#ifndef SEMESTRALKA_CHUNK_H
#define SEMESTRALKA_CHUNK_H



#include <vector>
#include <memory>
#include <string>

#include "Item.h"
#include "Constants.h"


/**
 * @brief Pre-declaration of Item class
 * */
class Item;


/**
 * @brief Classs  representing chunk, used in game world
 * */
class Chunk {
public:

    /**
     * @brief Vector of junk content
     * */
    std::vector<std::shared_ptr<Item>> content;


    /**
     * @brief Returns data for saving purposes
     * @return String representation of Chunk
     * */
    std::string toString();

    /**
     * @brief Chunk destructor
     * */
    ~Chunk();

};


#endif //SEMESTRALKA_CHUNK_H
