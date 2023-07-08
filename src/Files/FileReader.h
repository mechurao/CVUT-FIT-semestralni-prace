//
// Created by mechuon1 on 3/28/23.
//

#ifndef SEMESTRALKA_FILEREADER_H
#define SEMESTRALKA_FILEREADER_H

#include <string>
#include <fstream>

#include "../Constants.h"

/**
 * @brief Class used for read content from text files
 * */
class FileReader {
private:

    /**
     * @brief Default constructor
     * */
    FileReader() = default;

public:

    /**
     * @brief Static method to read string data from given file
     * @param path path to target file
     * @param reference to output string
     * @return true if read is success, false if not
     * */
    static bool readFile(const std::string& path,std::string& res);

};


#endif //SEMESTRALKA_FILEREADER_H
