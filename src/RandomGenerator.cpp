//
// Created by Ondřej Měchura on 13/05/2020.
//

#include "RandomGenerator.h"

using namespace std;

shared_ptr<Item>RandomGenerator::pickItem(const vector<shared_ptr<Item>> &options) {
    random_device rd;
    mt19937 generator(rd());
    uniform_real_distribution<double> distribution(0.0,1.0);
    double total = 0.0;
    for(const auto &item: options){
        total += item->getSpawnProbability();
    }
    double val = distribution(generator) * total;
    double cumulative = 0.0;
    for(const auto& res : options){
        cumulative += res->getSpawnProbability();
        if(val <= cumulative){return res;}
    }
    return nullptr;
}


shared_ptr<Entity> RandomGenerator::pickEntity() {
    random_device rd;
    mt19937 generator(rd());
    uniform_real_distribution<double> distribution(0.0,1.0);
    double total = 0.0;
    for(const auto &mob : Cache::mobsMap){
        total+= mob.second->getSpawnProbability();
    }
    double val = distribution(generator) * total;
    double cumulative = 0.0;
    for(const auto& res : Cache::mobsMap){
        cumulative+=res.second->getSpawnProbability();
        if(val <= cumulative){return res.second;}
    }

    return nullptr;
}


int RandomGenerator::getFromInterval(int lo, int hi) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(lo,hi);
    return dis(gen);
}



