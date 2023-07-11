#ifndef LABOR_ALGORITHMS_BRACKET_HPP
#define LABOR_ALGORITHMS_BRACKET_HPP
#include <iostream>
#include <string>
#include "Token.hpp"

class Bracket : public Token
{

public:

    ///@brief creates a new bracket
    Bracket(char t) { m_type = t;}

    ///@brief dummy method
    ///@return 0
    int eval() override { return 0; }

    ///@brief returns the bracket as string
    string getValue() override
    {
        return string(1, m_type);
    }


    ///@brief dummy method
    ///@return empty string
    string prefix() override { return ""; }

    ///
    string infix() override { return ""; }

    ///@brief dummy method
    ///@return empty string
    string postfix() override { return ""; }

};
#endif //LABOR_ALGORITHMS_BRACKET_HPP
