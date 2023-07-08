//
// Created by mechuon1 on 4/26/23.
//

#ifndef SEMESTRALKA_COLOR_H
#define SEMESTRALKA_COLOR_H


#include <string>

/**
 * @brief Class representing Color in RGB format
 * */
class Color {
private:

    /**
     * @brief Color identifier
     * */
    int id;

    /**
     * @brief Color name
     * */
    std::string name;

    /**
     * Color R,G,B values
     * */
    int r,g,b;

    /**
     * @brief Ncurses value converter
     * @param value Original color value
     * @return Converted value acceptable by NCurses
     * */
    static int toNcursesValue(int value);


public:
    /**
     * @brief Color constructor from rgb format
     * @param colorID Unique color identifier
     * @param colorName Name of color
     * @param red Red color part
     * @param green Green color part
     * @param blue Blue color part
     * */
    Color(int colorID,std::string& colorName,int red, int green, int blue);

    /**
     * @brief ID getter
     * @return Color identifier
     * */
    [[nodiscard]] int  getID() const;

    /**
     * @brief Name getter
     * @return Returns name of color
     * */
    [[nodiscard]] std::string getName()const;

    /**
     * @brief Red part getter
     * @return Red part value of color
     * */
    [[nodiscard]] short getR() const;

    /**
     * @brief Green part getter
     * @return Green part value of color
     * */
    [[nodiscard]] short getG()const;

    /**
     * @brief Blue part getter
     * @return Blue  part value of color
     * */
    [[nodiscard]] short getB()const;
};


#endif //SEMESTRALKA_COLOR_H
