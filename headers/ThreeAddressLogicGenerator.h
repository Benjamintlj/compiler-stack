//
// Created by Benjamin Lewis-Jones on 30/10/2022.
//

#ifndef NOM_NOM_THREEADDRESSLOGICGENERATOR_H
#define NOM_NOM_THREEADDRESSLOGICGENERATOR_H

#include "SymbolTable.h"

class ThreeAddressLogicGenerator {
private:
    SymbolTable &symbolTable;
    int numberOfExpressions;
    std::string output;

    void generateTAL();
    std::string TALGenForEachNode(Token* start);

public:
    ThreeAddressLogicGenerator(SymbolTable &symbolTable);

};


#endif //NOM_NOM_THREEADDRESSLOGICGENERATOR_H
