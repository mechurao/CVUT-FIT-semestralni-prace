//
// Created by mechuon1 on 4/26/23.
//

#include "Color.h"

using namespace std;

Color::Color(int colorID,string &colorName, int red, int green, int blue)
:id(colorID),
name(colorName),
r(toNcursesValue(red)),
g(toNcursesValue(green)),
b(toNcursesValue(blue)){}

int Color::toNcursesValue(int value) {
    return (value * 1000) / 255;
}

int Color::getID() const {
    return this->id;
}

string Color::getName() const {
    return this->name;
}

short Color::getR() const {
    return (short )this->r;
}

short Color::getG() const {
    return (short )this->g;
}

short Color::getB() const {
    return (short )this->b;
}



