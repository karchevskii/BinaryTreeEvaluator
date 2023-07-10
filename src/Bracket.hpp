//
// Created by Dinar Karchevskii on 08.07.23.
//

#ifndef LABOR_ALGORITHMS_BRACKET_HPP
#define LABOR_ALGORITHMS_BRACKET_HPP
#include <iostream>
#include <string>
#include "Token.hpp"

///@brief Baumknoten und Token zur Darstellung einer Klammer.
class Bracket : public Token
{

public:

    ///@brief Erzeugt eine neue Klammer.
    Bracket(char t) { m_type = t; /* cout << "Bracket added: " << t << endl; */}

    ///@brief Dummy-Methode, tut nichts.
    ///@return 0
    int eval() override { return 0; }

    string getValue() override
    {
        return string(1, m_type);
    }


    ///@brief Dummy-Methode, tut nichts.
    ///@return leerer String
    string prefix() override { return ""; }

    /*
     * Dummy-Methode, tut nichts.
     *
     * Return: leerer String
     */
    string infix() override { return ""; }

    ///@brief Dummy-Methode, tut nichts.
    ///@return leerer String
    string postfix() override { return ""; }

};
#endif //LABOR_ALGORITHMS_BRACKET_HPP
