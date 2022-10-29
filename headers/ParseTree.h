//
// Created by Benjamin Lewis-Jones on 29/10/2022.
//

#ifndef NOM_NOM_PARSETREE_H
#define NOM_NOM_PARSETREE_H

#include "SymbolTable.h"


class ParseTree {
private:
    SymbolTable &symbolTable;
    int find(std::vector<Token> line, std::string val);

public:
    explicit ParseTree(SymbolTable &symbolTable);
    void createParseTreeLines();
};


#endif //NOM_NOM_PARSETREE_H
