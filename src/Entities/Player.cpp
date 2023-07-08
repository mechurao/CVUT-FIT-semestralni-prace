//
// Created by Ondřej Měchura on 05/05/2020.
//

#include "Player.h"

using namespace std;

// constructors
Player::Player() : Entity(PLAYER_ID, PLAYER_NAME, PLAYER_CHAR, Cache::max_health, Cache::player_color_id, 0){

    this->inventory = make_shared<Inventory>();
    this->hand = make_shared<PlayerHand>();
}

Player::Player(const Player &src) : Entity(src){
    this->hand = make_shared<PlayerHand>(); // set hand
    this->inventory = src.inventory->Clone(); // deep copy of inventory
}



PlayerHand &Player::getHand() {
    return *hand;
}




shared_ptr<Inventory> Player::getInventory() {

    return this->inventory;
}

void Player::print() const {
    for(int i = 0; i < this->health;i++){
        printw("%c",PLAYER_HEALTH_SIGN);
    }
    printw("\n");

}

string Player::toString() {
    string result;
    result += to_string(this->currentChunk->first);
    result+=SECONDARY_DELIMETER;
    result+= to_string(this->y);
    result+=SECONDARY_DELIMETER;
    result+= this->inventory->toString();

    return result;
}


std::shared_ptr<Entity> Player::Clone() const {
    return make_shared<Player>(*this);
}


Player::~Player() = default;






