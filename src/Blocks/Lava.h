//
// Created by mechuon1 on 5/15/23.
//

#ifndef SEMESTRALKA_LAVA_H
#define SEMESTRALKA_LAVA_H

#include "Block.h"
#include "../Cache.h"

/**
 * @brief Default lava block, always lethal for entity stepping on it
 * */
class Lava: public Block{
public:

    /**
     * @brief Default constructor (all attributes are filled by constant values)
     * */
    Lava();

    /**
     * @brief Overriden isCrossable method
     * @return Always yes ( but for once and last)
     * */
    [[nodiscard]] bool isCrossable() const override;

    /**
     * @brief Overriden visit method (kill entity instantly)
     * @param entity Reference to entity stepping on this block
     * */
    void visit(Entity * entity) override;

    /**
     * @brief Overriden Clone method
     * @return shared_ptr to newly created lava block
     * */
    [[nodiscard]] std::shared_ptr<Item> Clone() const override;



};


#endif //SEMESTRALKA_LAVA_H
