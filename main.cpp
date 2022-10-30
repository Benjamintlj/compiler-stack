#include <iostream>
#include "headers/Tokenizer.h"
#include "headers/SymbolTable.h"
#include "headers/ParseTree.h"
#include "headers/ThreeAddressLogicGenerator.h"

using namespace std;

int main() {

    try {

        SymbolTable symbolTable = SymbolTable();
        Tokenizer tokenizer = Tokenizer(symbolTable);
        ParseTree parseTree = ParseTree(symbolTable);
        ThreeAddressLogicGenerator threeAddressLogicGenerator = ThreeAddressLogicGenerator(symbolTable);

    } catch (std::exception& e) {
        cerr << e.what() << endl;
        return -1;
    }


    return 0;
}
