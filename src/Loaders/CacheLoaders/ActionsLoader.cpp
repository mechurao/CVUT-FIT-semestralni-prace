//
// Created by mechuon1 on 5/16/23.
//

#include "ActionsLoader.h"

using namespace std;

optional<Action> ActionsLoader::getAction(const string &in) {

    if(in == MOVE_LEFT_KEY) {return  moveLeft;}
    if(in == MOVE_RIGHT_KEY){return  moveRight;}
    if(in == MOVE_JUMP_KEY){return  moveJump;}
    if(in == ACTION_LEFT_KEY){return  actionLeft;}
    if(in == ACTION_RIGHT_KEY){return actionRight;}
    if(in == ACTION_UP_KEY){return  actionUp;}
    if(in == ACTION_DOWN_KEY){return  actionDown;}
    if(in == CONTROL_QUIT_KEY){return  controlQuit;}
    if(in == CONTROL_ENTER_KEY){return  controlEnter;}
    if(in == CONTROL_SAVE_KEY){return  controlSave;}
    if(in == CONTEXT_BACK_KEY){return  contextBack;}
    if(in == CONTEXT_NEXT_KEY){return  contextNext;}
    if(in == OPTION_0_KEY){return option0;}
    if(in == OPTION_1_KEY){return option1;}
    if(in == OPTION_2_KEY){return option2;}
    if(in == OPTION_3_KEY){return option3;}
    if(in == OPTION_4_KEY){return option4;}
    if(in == OPTION_5_KEY){return option5;}
    if(in == OPTION_6_KEY){return option6;}
    if(in == OPTION_7_KEY){return option7;}
    if(in == OPTION_8_KEY){return option8;}
    if(in == OPTION_9_KEY){return option9;}
    if(in == GAME_INVENTORY_KEY){return gameInventory;}
    if(in == GAME_CRAFTING_KEY){return gameCrafting;}
    if(in == GAME_CRAFTING_REMOVE_KEY){return gameCraftingRemove;}
    return std::nullopt;
}

bool ActionsLoader::load(string &in) {
    auto tokens = StringSplitter::splitString(in,PRIMARY_DELIMETER);
    for(auto &t : tokens){

        auto tmp = StringSplitter::splitString(t,SECONDARY_DELIMETER);
        if(tmp.size() != 2){return false; } // missing parameter

        // get action
        auto action = getAction(tmp[0]);
        if(!action.has_value()){ return false;} // no matching action found

        auto key = NumberParser::parseInt(tmp[1]);
        if(!key.has_value()){ return false;}

        //add new action to map
        auto inPair = make_pair(key.value(), action.value());
        Cache::actions.insert(inPair);
    }
    return true;
}
