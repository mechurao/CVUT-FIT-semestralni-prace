//
// Created by Ondřej Měchura on 31/05/2020.
//

#include "Mob.h"

#include <utility>

using namespace std;


Mob::Mob(int id, std::string& name, char printChar, int hp, int color, const std::vector<int>& drops, double probability, bool dayActive, bool nightActive)
        : Entity(id, name, printChar, hp, color, drops, probability){
    this->dayActivity = dayActive;
    this->nightActivity = nightActive;
}

Mob::Mob(const Mob &src): Entity(src) {
    this->dayActivity = src.dayActivity;
    this->nightActivity = src.nightActivity;
}


bool Mob::isActive(DayPhase phase) {
    switch ( phase) {
        case DayPhase::day:{
            return this->dayActivity;

        }
        case  DayPhase::night:{
            return this->nightActivity;
        }
    }
    return false;
}



string Mob::toString() {
    return Entity::toString();
}

std::shared_ptr<Entity> Mob::Clone() const {
    return make_shared<Mob>(*this);
}







