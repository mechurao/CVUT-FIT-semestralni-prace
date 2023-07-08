//
// Created by mechuon1 on 4/14/23.
//

#ifndef SEMESTRALKA_NUMBERPARSER_H
#define SEMESTRALKA_NUMBERPARSER_H



#include <optional>
#include <string>
#include <iostream>

/**
 * @brief Number parser class with value validation
 * */
class NumberParser {

public:
    /**
     * @brief Parse integer from string
     * @param input Input string data
     * @return Parsed int, if conversion succeeded, otherwise nullopt
     * */
    static std::optional<int> parseInt(const std::string& input);

    /**
     * @brief Parse double from string
     * @param input Input string data
     * @return Parsed double value, if conversion succeeded, otherwise nullopt
     * */
    static std::optional<double> parseDouble(const std::string& input);

};


#endif //SEMESTRALKA_NUMBERPARSER_H
