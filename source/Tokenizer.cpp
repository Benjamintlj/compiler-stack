//
// Created by Benjamin Lewis-Jones on 25/10/2022.
//

#include "../headers/Tokenizer.h"

using namespace std;

void Tokenizer::readInput() {
    inputParser.readInput();
    lexemes = inputParser.getLexmes();
}

Tokenizer::Tokenizer(SymbolTable &symbolTable) : symbolTable(symbolTable) {
    readInput();
    generateTokenTable();
}

void Tokenizer::generateTokenTable() {

    for (auto line:lexemes) {
        symbolTable.addNewSymbol(line);
    }

}

