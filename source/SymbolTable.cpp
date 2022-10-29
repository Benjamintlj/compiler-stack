//
// Created by Benjamin Lewis-Jones on 25/10/2022.
//

#include <regex>
#include <iostream>

#include "../headers/SymbolTable.h"

SymbolTable::SymbolTable() {
    return;
}

void SymbolTable::addNewSymbol(std::vector<std::string> line) {
    std::vector<Token> lineToBePushed;

    for (int i = 0; i < line.size(); i++) {
        Token newSymbol;

        newSymbol.content = line[i];
        newSymbol.type = symbolType(line[i]);

        lineToBePushed.push_back(newSymbol);
    }

    tokenTable.push_back(lineToBePushed);
}



std::vector<std::vector<Token>> SymbolTable::getTokenTable() {
    return tokenTable;
}

int SymbolTable::symbolType(const std::string& symbol) {

    // OPERATORS
    if (std::regex_match(symbol, std::regex("\\+"))) {
        return OP_ADD;
    }

    if (std::regex_match(symbol, std::regex("\\-"))) {
        return OP_SUB;
    }

    if (std::regex_match(symbol, std::regex("\\*"))) {
        return OP_MULT;
    }

    if (std::regex_match(symbol, std::regex("\\/"))) {
        return OP_DIV;
    }

    // LITERAL
    if (std::regex_match(symbol, std::regex("[0-9]{0,}"))) {
        return LIT_INT;
    }

    // PUNCTUATION
    if (std::regex_match(symbol, std::regex("\\("))) {
        return PUNC_LEFT_BRACKET;
    }

    if (std::regex_match(symbol, std::regex("\\)"))) {
        return PUNC_RIGHT_BRACKET;
    }

    if (std::regex_match(symbol, std::regex(";"))) {
        return PUNC_SEMI_COLON;
    }

    if (std::regex_match(symbol, std::regex("="))) {
        return PUNC_EQUALS;
    }

    // IDENTIFIER
    if (std::regex_match(symbol, std::regex("[A-Z|a-z]{0,}"))) {
        return ID;
    }

    std::string errorDescription = "ERROR Unknown Symbol: ";
    errorDescription.append(symbol);
    throw std::invalid_argument(errorDescription);
}
