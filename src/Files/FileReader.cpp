//
// Created by mechuon1 on 3/28/23.
//

#include "FileReader.h"

using namespace std;

bool FileReader::readFile(const string &path,string &res) {
    string buffer;
    ifstream file;
    file.open(path);
    if(file.good()){

        while (getline(file, buffer)){

            if(buffer[0] != COMMENT_MARK){
                res+=buffer;
            }
        }
    }else{ return false;}
    file.close();
    return true;
}



