#ifndef BINARY_TREE_EVALUATOR_TOKEN_HPP
#define BINARY_TREE_EVALUATOR_TOKEN_HPP

#include <string>

using namespace std;

class Token
{

public:

    ///@brief type of token
    char m_type;

    Token() {}

    Token(char type)
    : m_type(type)
    {
    }

    Token(char type, Token *l, Token *r)
    : m_type(type)
    {
    }

    virtual ~Token() {}

    ///@brief getter type of token
    ///@return char: type of token
    char getType(){
        return m_type;
    }

    ///@brief evaluate the expression
    virtual int eval() = 0;

    ///@brief prefix notation
    virtual string prefix() = 0;

    ///@brief infix notation
    virtual string infix() = 0;

    ///@brief postfix notation
    virtual string postfix() = 0;

    ///@brief left subtree
    virtual Token* left() {
        return NULL;
    }

    ///@brief right subtree
    virtual Token* right() {
        return NULL;
    }

    ///@brief getter left subtree
    ///@return Token*: the left subtree
    virtual Token* getleft() {
        return NULL;
    }

    ///@brief getter right subtree
    ///@return Token*: the right subtree
    virtual Token* getright() {
        return NULL;
    }

    ///@brief getter value of the token
    virtual string getValue() = 0;



    ///@brief number of nodes in the tree
    virtual int nodes()
    {
        return 1;
    }


    ///@brief depth of the tree
    virtual int depth()
    {
        return 1;
    }

};


#endif //BINARY_TREE_EVALUATOR_TOKEN_HPP
