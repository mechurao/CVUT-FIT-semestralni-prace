//
// Created by mechuon1 on 4/22/23.
//

#include "Bedrock.h"



Bedrock::Bedrock(): Block(BEDROCK_ID, BEDROCK_NAME, BEDROCK_CHAR, {}, Cache::bedrock_color, 0){

}

/** Overriden decreaseDurability method (no damage for bedrock)*/
void Bedrock::decreaseDurability(int value) {}
