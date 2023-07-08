//
// Created by Ondřej Měchura on 31/05/2020.
//

#ifndef SEMESTRALKA_MOB_H
#define SEMESTRALKA_MOB_H


#include <iostream>
#include <vector>

#include "Entity.h"

/**
 * @brief Mob base class
 * */
class Mob: public Entity{

private:

    /**
     * @brief Day activity check
     * */
    bool dayActivity;

    /**
     * @brief Night activity check
     * */
    bool nightActivity;


public:

    /**
     * @brief Mob constructor
     * @param id Unique mob identifier
     * @param name Mob name
     * @param printChar Unique mob character for saving purposes
     * @param hp Mob health points
     * @param color Identifier of mob volor used by rendering
     * @param drops vector of items dropped if mob is killed
     * @param probability mob spawn probability
     * */
    Mob(int id,std::string& name,char printChar, int hp, int color, const std::vector<int>& drops, double probability, bool dayActive, bool nightActive);


    /**
     * @brief Mob copy constructor
     * @param src Reference to copied object
     * */

    Mob(const Mob& src);

    /**
     * @brief Overriden day phase activity checker
     * @param phase Day phase to check
     * @return True if active, otherwise not
     *
     * */
    bool isActive(DayPhase phase) override;




   /**
     * @brief Overriden toString method for encoding mob data to string
     * @return String representation of mob for saving purposes
     * */
    std::string toString() override;

    /**
     * @brief Overrided clone method
     * @return shared_ptr to newly created Mob
     * */
    [[nodiscard]] std::shared_ptr<Entity> Clone() const override;

};

#endif //SEMESTRALKA_MOB_H
