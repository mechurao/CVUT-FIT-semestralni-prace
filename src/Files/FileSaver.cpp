//
// Created by mechuon1 on 5/10/23.
//


#include "FileSaver.h"

using namespace std;

bool FileSaver::saveData(const string &data, const string &filename) {
    ofstream file(filename, ios::out);
    if (!file) { return false;}
    file << data;
    file.close();
    if (!file) { return false; }
    return true;
}
