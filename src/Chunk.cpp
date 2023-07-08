//
// Created by mechuon1 on 4/22/23.
//

#include "Chunk.h"

using namespace std;

string Chunk::toString() {
    string data;
    for(auto &s : this->content){
        if (s->getId() != BEDROCK_ID){
            data += s->print();
        }
    }
    return data;
}


Chunk::~Chunk() {
    this->content.clear();

}
