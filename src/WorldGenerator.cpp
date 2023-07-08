//
// Created by Ondřej Měchura on 18/03/2020.
//


#include "WorldGenerator.h"

using namespace std;


void WorldGenerator::generateChunkContent(const shared_ptr<Chunk>& chunk) {

    // zones dimensions
    int airHeight = (int)(Cache::world_height * Cache::min_air_alt);
    int middleHeight = (int)(Cache::world_height * Cache::min_mid_alt);
    int bottomHeight = (int)(Cache::world_height * Cache::min_bottom_alt);


    // zones blocks
    vector<shared_ptr<Item>> midBlocks;
    vector<shared_ptr<Item>> bottBlocks;



    // init blocks for different zones
    for(auto&m : Cache::mid_items_vec){
        midBlocks.push_back(Cache::itemsMap[m]);
    }

    for(auto &b : Cache::bottom_items_vec){
        bottBlocks.push_back(Cache::itemsMap[b]);
    }
    // add lava to bottom block options
    bottBlocks.push_back(make_shared<Lava>());


    // top border
    chunk->content.push_back(make_shared<Bedrock>());

    // generate atmosphere

    for(int i = 0; i < airHeight;i++){
        chunk->content.push_back(make_shared<Air>());
    }


    // generate middle

    for(int j = 0; j < middleHeight;j++){
        chunk->content.push_back(RandomGenerator::pickItem(midBlocks)->Clone());
    }

    // generate bottom
    for(int k = 0; k < bottomHeight;k++ ){
        chunk->content.push_back(RandomGenerator::pickItem(bottBlocks)->Clone());
    }

   // bottom border
    chunk->content.push_back(make_shared<Bedrock>());

    // update temp value if necessary
    if((int)chunk->content.size()-1 != Cache::world_height){
        Cache::world_height = (int) chunk->content.size() - 1;
    }
}


shared_ptr<Chunk> WorldGenerator::getChunk() {
    auto chunk  = make_shared<Chunk>();
    generateChunkContent(chunk);
    return chunk;
}