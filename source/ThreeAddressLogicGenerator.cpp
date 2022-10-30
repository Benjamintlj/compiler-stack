//
// Created by Benjamin Lewis-Jones on 30/10/2022.
//

#include "../headers/ThreeAddressLogicGenerator.h"
#include "../headers/SymbolTable.h"
#include <iostream>

using namespace std;

ThreeAddressLogicGenerator::ThreeAddressLogicGenerator(SymbolTable &symbolTable) : symbolTable(symbolTable) {
    numberOfExpressions = 0;

    generateTAL();
}

void ThreeAddressLogicGenerator::generateTAL() {

    std::vector<Token> parseTreeForEachLine = symbolTable.getParseTreeForEachLine();

    for (auto line:parseTreeForEachLine) {
        TALGenForEachNode(&line);
    }

    cout << output << endl;
}

std::string ThreeAddressLogicGenerator::TALGenForEachNode(Token * start) {

    std::string leftValue;
    std::string rightValue;

    if (start->left->isExpression)
        leftValue = TALGenForEachNode(start->left);
    else
        leftValue = start->left->content;

    if (start->right->isExpression)
        rightValue = TALGenForEachNode(start->right);
    else
        rightValue = start->right->content;

    numberOfExpressions += 1;

    std::string termValue = "t";
    termValue.append(std::to_string(numberOfExpressions));

    output.append(termValue);
    output.append(" = ");
    output.append(leftValue);
    output.append(" ");
    output.append(start->content);
    output.append(" ");
    output.append(rightValue);
    output.append("\n");

    return termValue;
}
