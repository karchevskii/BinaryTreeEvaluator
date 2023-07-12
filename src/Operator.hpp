#ifndef BINARY_TREE_EVALUATOR_OPERATOR_HPP
#define BINARY_TREE_EVALUATOR_OPERATOR_HPP
#include <iostream>
#include <string>
#include "Token.hpp"

class Operator : public Token
{


public:
    Token *left;
    Token *right;

    ///@brief creates a new operator
    ///@param t type of the operator '+', '-', '*' or '/'
    ///@param l left subtree
    ///@param r right subtree
    Operator(char t, Token *l, Token *r)
    {
        m_type = t;
        left = l;
        right = r;
    }

    ///@brief creates a new operator
    ///@param t type of the operator '+', '-', '*' or '/'
    Operator(char t)
    {
        m_type = t;
        left = nullptr;
        right = nullptr;
    }

    ///@brief returns the operator
    ///@return operator
    string getValue() override
    {
        return string(1, m_type);
    }

    ///@brief returns the result of the operation
    ///@return result of the operation
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

    ///@brief returns the prefix notation of the tree
    ///@return prefix notation
    string prefix() override
    {
        string result = string(1, m_type);

        if (left != nullptr)
        {
            result += left->prefix();
            result += " ";
        }

        if (right != nullptr)
        {
            result += right->prefix();
        }

        return result;
    }

    ///@brief returns the infix notation of the tree
    ///@return infix notation
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

    ///@brief returns the postfix notation of the tree
    ///@return postfix notation
    string postfix() override
    {
        string result;

        if (left != nullptr)
        {
            result += left->postfix();
            result += " ";
        }

        if (right != nullptr)
        {
            result += right->postfix();
        }

        result += m_type;

        return result;
    }

    ///@brief returns the number of nodes in the tree
    ///@return number of nodes
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

    ///@brief returns the depth of the node
    ///@return depth
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

    ///@brief returns the left child of the node
    ///@return left child
    Token* getleft() override
    {
        return left;
    }

    ///@brief returns the right child of the node
    ///@return right child
    Token* getright() override
    {
        return right;
    }

};
#endif //LABOR_ALGORITHMS_OPERATOR_HPP
