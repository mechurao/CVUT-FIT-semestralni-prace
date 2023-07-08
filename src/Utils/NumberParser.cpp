//
// Created by mechuon1 on 4/14/23.
//

#include "NumberParser.h"

using namespace std;

optional<int> NumberParser::parseInt(const string &input) {
    try {
        int key = stoi(input);
        return key;
    }catch (...){
        return nullopt;
    }
}

optional<double> NumberParser::parseDouble(const string &input) {
    try {
        double val = stod(input);
        return val;
    }catch (...){
        return nullopt;
    }
}
