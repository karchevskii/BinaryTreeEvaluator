//
// Created by Dinar Karchevskii on 08.07.23.
//

#ifndef LABOR_ALGORITHMS_NUM_HPP
#define LABOR_ALGORITHMS_NUM_HPP
#include <iostream>
#include <string>
#include "Token.hpp"
class Num : public Token
{

    int number;

public:

    Num() {}

    Num(int i)
    : Token('n')
    , number(i)
    {
    }

    ~Num() {}

    ///@brief returns the number
    int eval() override
    {
        return number;
    }

    ///@brief returns the number as string
    string getValue() override
    {
        return std::to_string(number);
    }

    ///@brief returns the number as string
    string prefix() override
    {
        return std::to_string(number);
    }

    ///@brief returns the number as string
    string infix() override
    {
        return std::to_string(number);
    }

    ///@brief returns the number as string
    string postfix() override
    {
        return std::to_string(number);
    }


};
#endif //LABOR_ALGORITHMS_NUM_HPP
