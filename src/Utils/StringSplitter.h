//
// Created by mechuon1 on 4/6/23.
//

#include <vector>
#include <string>

#ifndef SEMESTRALKA_STRINGSPLITTER_H
#define SEMESTRALKA_STRINGSPLITTER_H

/**
 * @brief Utility to split string by given delimeter
 * */
class StringSplitter {

public:

    /**
     * @brief Split string by given delimeter and return as vector of separated tokens
     * @param input Input string data
     * @param del Split delimeter
     * @return Vector of splitted tokens
     * */
    static std::vector<std::string> splitString(const std::string& input, char del);

};


#endif //SEMESTRALKA_STRINGSPLITTER_H
