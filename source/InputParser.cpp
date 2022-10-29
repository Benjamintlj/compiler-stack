//
// Created by Benjamin Lewis-Jones on 24/10/2022.
//

#include "../headers/InputParser.h"
#include <string>
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

InputParser::InputParser() {
    inputCodeLocation = "../input/inputCode.txt";
}

void InputParser::readInput() {
    std::ifstream file;
    file.open(inputCodeLocation);

    string line;
    if (file.is_open()) {
        while(getline(file, line)) {
            getInputText(line);
        }
    } else {
        cout << "failed to open file" << endl;
    }

    file.close();
    file.clear();
}

void InputParser::getInputText(std::string line) {

    std::smatch m;
    std::regex e (R"((([A-z]|[0-9]){1,}|[-!$%^&*()_+|~=`{}\[\]:";'<>?,.\/]{1}))");

    std::vector<std::string> newLine;

    while (std::regex_search (line,m,e)) {
        newLine.push_back(m[0]);
        line = m.suffix().str();
    }

    lexemes.push_back(newLine);
}

std::vector<std::vector<std::string>> InputParser::getLexmes() {
    return lexemes;
}

void InputParser::displayLexemes() {
    for (const auto& line:lexemes)
        for (const auto& lexeme:line)
            std::cout << lexeme << std::endl;
}
