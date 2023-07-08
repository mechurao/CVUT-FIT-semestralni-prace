//
// Created by Ondřej Měchura on 13/05/2020.
//

#ifndef SEMESTRALKA_RANDOMGENERATOR_H
#define SEMESTRALKA_RANDOMGENERATOR_H

#include <random>
#include <vector>
#include "Item.h"
#include "Cache.h"

/**
 * @brief Class used as Random picker of Randomly generated objects
 * */
class RandomGenerator {
private:

public:

    /**
     * @brief Pick random item
     * @param options Options to pick
     * @return Selected item
     * */
    static std::shared_ptr<Item> pickItem(const std::vector<std::shared_ptr<Item>>& options);

    /**
     * @brief Pick random entity
     * @param options Options to pick
     * @return Selected entity
     * */
    static std::shared_ptr<Entity> pickEntity();

    /**
     * @brief Get random number from interval
     * @param lo Lowest interval number
     * @param hi Highest interval number
     * @return Selected number
     * */
    static int getFromInterval(int lo, int hi);

};


#endif //SEMESTRALKA_RANDOMGENERATOR_H
