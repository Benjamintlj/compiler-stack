//
// Created by Benjamin Lewis-Jones on 25/10/2022.
//

#ifndef NOM_NOM_TOKENIZER_H
#define NOM_NOM_TOKENIZER_H


#include "InputParser.h"
#include "SymbolTable.h"

class Tokenizer {
private:
    InputParser inputParser = InputParser();
    std::vector<std::vector<std::string>> lexemes;
    SymbolTable &symbolTable;

    void readInput();

public:
    Tokenizer(SymbolTable &symbolTable);
    void generateTokenTable();
};


#endif //NOM_NOM_TOKENIZER_H
