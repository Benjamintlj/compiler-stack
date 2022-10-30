//
// Created by Benjamin Lewis-Jones on 29/10/2022.
//

#include "../headers/ParseTree.h"
#include "../headers/SymbolTable.h"
#include <iostream>

using namespace std;

ParseTree::ParseTree(SymbolTable &symbolTable) : symbolTable(symbolTable) {
    createParseTreeLines();
}

int ParseTree::find(std::vector<Token> line, std::string val) {

    for (int i = 0; i < line.size(); i++) {
        if (line[i].content == val && !line[i].isExpression) {
            return i;
        }
    }
    return 0;
}

void ParseTree::createParseTreeLines() {

    vector<vector<Token>> fullSetOfTokens = symbolTable.getTokenTable();
    vector<Token> output;

    // loop through lines
    for (int i = 0; i < fullSetOfTokens.size(); i++) {

        vector<Token> line = fullSetOfTokens[i];
        int it = 0;

        line.size();

        while (line.size() >= 2) {

            it = find(line, "*");
            if (it == 0)
                it = find(line, "+");

            auto* left = (Token *) malloc(sizeof(Token));
            auto* right = (Token *) malloc(sizeof(Token));

            *left = line[it - 1];
            *right = line[it + 1];

            line[it].left = left;
            line[it].right = right;
            line[it].isExpression = true;

            line.erase(line.begin() + it + 1);
            line.erase(line.begin() + it - 1);
        }

        if (!line.empty())
            output.push_back(line[0]);
    }

    symbolTable.setparseTreeForEachLine(output);
}
