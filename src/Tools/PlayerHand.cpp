//
// Created by mechuon1 on 4/24/23.
//

#include "PlayerHand.h"

using namespace std;

PlayerHand::PlayerHand(): Tool(HAND_ID, HAND_NAME, HAND_CHAR, 1, Cache::player_damage, 2, 0) {

}
PlayerHand::PlayerHand(const PlayerHand &src) = default;;


void PlayerHand::decreaseDurability(int val) {}

std::shared_ptr<Item> PlayerHand::Clone() const {
    return make_shared<PlayerHand>(*this);
}

