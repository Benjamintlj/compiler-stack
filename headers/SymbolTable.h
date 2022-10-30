//
// Created by Benjamin Lewis-Jones on 25/10/2022.
//

#ifndef NOM_NOM_SYMBOLTABLE_H
#define NOM_NOM_SYMBOLTABLE_H

#include <vector>
#include <unordered_map>
#include <string>

enum symbolTypes {
//  OPERATOR
    OP_ADD,
    OP_SUB,
    OP_MULT,
    OP_DIV,

//  LITERAL (raw values)
    LIT_INT,

//  PUNCTUATION
    PUNC_LEFT_BRACKET,
    PUNC_RIGHT_BRACKET,
    PUNC_SEMI_COLON,
    PUNC_EQUALS,

//  IDENTIFIER (values stored in a variable)
    ID,

//  ERROR
    UNDEFINED_SYMBOL,
};

struct Token {

    std::string content;
    int type;
    
    Token* left;
    Token* right;

    bool isExpression = false;

} typedef Token;

class SymbolTable {
private:
    std::vector<std::vector<Token>> tokenTable;
    std::vector<Token> parseTreeForEachLine;
public:
    SymbolTable();
    void addNewSymbol(std::vector<std::string> line);
    static int symbolType(const std::string& symbol);
    std::vector<std::vector<Token>> getTokenTable();
    void setparseTreeForEachLine(std::vector<Token> parseTreeVector);
    std::vector<Token> getParseTreeForEachLine();
};


#endif //NOM_NOM_SYMBOLTABLE_H
