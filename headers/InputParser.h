//
// Created by Benjamin Lewis-Jones on 24/10/2022.
//

#ifndef NOM_NOM_INPUTPARSER_H
#define NOM_NOM_INPUTPARSER_H

#include <iostream>
#include <vector>

class InputParser {
private:
    std::string inputCodeLocation;
    std::vector<std::vector<std::string>> lexemes;

    void getInputText(std::string line);

public:
    InputParser();
    void readInput();
    std::vector<std::vector<std::string>> getLexmes();
    void displayLexemes();
};


#endif //NOM_NOM_INPUTPARSER_H
