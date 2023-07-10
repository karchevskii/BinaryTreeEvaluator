//
// Created by Dinar Karchevskii on 08.07.23.
//

#ifndef LABOR_ALGORITHMS_OPERATOR_HPP
#define LABOR_ALGORITHMS_OPERATOR_HPP
#include <iostream>
#include <string>
#include "Token.hpp"

/*
 * Baumknoten und Token zur Darstellung eines Operators.
 */
class Operator : public Token
{


public:
    Token *left;
    Token *right;

    /*
     * Erzeugt einen neuen Operator-Knoten.
     *
     * Parameter: t der Typ des Knotens: '+', '-', '*' oder '/'
     * Parameter: l der linke Unterbaum
     * Parameter: r der rechte Unterbaum
     */
    Operator(char t, Token *l, Token *r)
    {
        m_type = t;
        left = l;
        right = r;
    }

    /*
     * Erzeugt einen neuen Operator-Token.
     *
     * Parameter: t der Typ des Tokens: '+', '-', '*' oder '/'
     */
    Operator(char t)
    {
        m_type = t;
        left = nullptr;
        right = nullptr;
    }

    string getValue() override
    {
        return string(1, m_type);
    }

    int eval() override
    {
        int result = 0;

        if (m_type == '+')
        {
            result = left->eval() + right->eval();
        }
        else if (m_type == '-')
        {
            result = left->eval() - right->eval();
        }
        else if (m_type == '*')
        {
            result = left->eval() * right->eval();
        }
        else if (m_type == '/')
        {
            result = left->eval() / right->eval();
        }

        return result;
    }


    string prefix() override
    {
        string result = string(1, m_type); // Convert the operator to a string

        if (left != nullptr)
        {
            result += left->prefix();
        }

        if (right != nullptr)
        {
            result += right->prefix();
        }

        return result;
    }

    string infix() override
    {
        string result;

        if (left != nullptr)
        {
            result += "(" + left->infix();
        }

        result += m_type;

        if (right != nullptr)
        {
            result += right->infix() + ")";
        }

        return result;
    }

    string postfix() override
    {
        string result;

        if (left != nullptr)
        {
            result += left->postfix();
        }

        if (right != nullptr)
        {
            result += right->postfix();
        }

        result += m_type;

        return result;
    }


    int nodes() override
    {
        int result = 1;

        if(left != nullptr)
        {
            result += left->nodes();
        }

        if(right != nullptr)
        {
            result += right->nodes();
        }

        return result;
    }

    int depth() override
    {
        int left_depth = 0;
        int right_depth = 0;

        if(left != nullptr)
        {
            left_depth = left->depth();
        }

        if(right != nullptr)
        {
            right_depth = right->depth();
        }

        return 1 + std::max(left_depth, right_depth);
    }

    /*
     * Nummeriert den Baum ausgehend vom aktuellen Knoten unter Verwendung eines Zaehlers
	 * in Infix-Reihenfolge durch (wichtig fuer die Visualisierung).
     *
     * Parameter: o der Zaehler
     */
//    void order(Order *o)
//    {
//        left->order(o);
//        setOrd(++o->counter);
//        right->order(o);
//    }

    Token* getleft() override
    {
        return left;
    }

    Token* getright() override
    {
        return right;
    }

};
#endif //LABOR_ALGORITHMS_OPERATOR_HPP
