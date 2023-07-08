//
// Created by mechuon1 on 4/6/23.
//

#include <iostream>
#include "StringSplitter.h"

using namespace std;

vector<string> StringSplitter::splitString(const string &input, char del) {
    size_t start;
    size_t end = 0;

    vector<string> out;

    while ((start = input.find_first_not_of(del, end)) != string::npos) {
        end = input.find(del, start);
        out.push_back(input.substr(start, end - start));
    }
    return out;
}
