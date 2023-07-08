//
// Created by mechuon1 on 5/10/23.
//

#ifndef SEMESTRALKA_FILESAVER_H
#define SEMESTRALKA_FILESAVER_H

#include <string>
#include <fstream>

#include "../Constants.h"


/**
 * @brief Class for saving content to text file
 * */
class FileSaver {
public:

    /**
     * @brief static method writing given content to specified file
     * @param data data to write
     * @param filename target file
     * @return true if write is successful , false othervise
     * */
    static bool saveData(const std::string& data, const std::string &filename );

};


#endif //SEMESTRALKA_FILESAVER_H
