


#ifndef SEMESTRALKA_WORLDGENERATOR_H
#define SEMESTRALKA_WORLDGENERATOR_H


#include <vector>
#include <memory>


#include "RandomGenerator.h"
#include "Cache.h"
#include "Item.h"
#include "Blocks/Bedrock.h"
#include "Blocks/Air.h"
#include "Chunk.h"
#include "Blocks/Lava.h"

class Bedrock;
class Air;

/**
 * @brief class  for world generation
 * */

class  WorldGenerator{

public:
    /**
 * @brief Geenerate content by set rules in given chunk
 * @param chunk shared_ptr to target chunk
 * */
    static void generateChunkContent(const std::shared_ptr<Chunk>&chunk);


/**
 * @brief Makes new chunk from scratch
 * @return shared_ptr to new created chunk
 * */
    static std::shared_ptr<Chunk> getChunk();

};



#endif //SEMESTRALKA_WORLDGENERATOR_H



