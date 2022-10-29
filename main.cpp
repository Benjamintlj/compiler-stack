#include <iostream>
#include "headers/Tokenizer.h"
#include "headers/SymbolTable.h"
#include "headers/ParseTree.h"

using namespace std;

int main() {

    try {

        SymbolTable symbolTable = SymbolTable();
        Tokenizer tokenizer = Tokenizer(symbolTable);
        ParseTree parseTree = ParseTree(symbolTable);

    } catch (std::exception& e) {
        cerr << e.what() << endl;
        return -1;
    }


    return 0;
}
