//
// Created by Dinar Karchevskii on 08.07.23.
//

#ifndef LABOR_ALGORITHMS_EVALUATOR_HPP
#define LABOR_ALGORITHMS_EVALUATOR_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <stack>

#include "Token.hpp"
#include "Tokenizer.hpp"
#include "Visualizer.hpp"
#include "Num.hpp"

using namespace std;

class Evaluator
{

public:

    ///@brief Evaluates the expression
    ///@param exp the expression
    ///@param mode the mode '<': Prefix, '|': Infix, '>': Postfix
    void evaluate(string exp, char mode)
    {

        ///@brief Tokenize the expression
        Tokenizer *t = new Tokenizer(exp);

        ///@brief Construct the tree from the tokens
        Token *e = parse(t->tokenize(), mode);


//        e = new Operator('+',
//                   new Operator('*',
//                          new Num(2),
//                          new Num(3)),
//                   new Operator('-',
//                          new Operator('/',
//                                 new Num(6),
//                                 new Num(2)),
//                          new Num(1)));


        // Prefix:  + * 2 3 - / 6 2 1 = 8
        // Infix:   ((2 * 3) + ((6 / 2) - 1)) = 8
        // Postfix: 2 3 * 6 2 / 1 - + = 8
        // #Knoten: 9
        // Tiefe:   4

        ///@brief print the evaluated expression
        cout << "Prefix:  " << e->prefix() << " = " << e->eval() << endl;
        cout << "Infix:   " << e->infix() << " = " << e->eval() << endl;
        cout << "Postfix: " << e->postfix() << " = " << e->eval() << endl;
        cout << "Knoten: " << e->nodes() << endl;
        cout << "Tiefe: " << e->depth() << endl;

        ///@brief Visualize the tree
        Vis *v = new Vis();
        ///@param e The root of the tree
        v->printTree(e, nullptr, false);

    }

private:

    ///@brief Parse the expression
    ///@param tok The tokenized expression
    ///@param mode The mode of the expression '<': Prefix, '|': Infix, '>': Postfix
    ///@return The root of the tree
    Token *parse(vector<Token *> *tok, char mode) {



        vector<Token *>::iterator begin = tok->begin();
        vector<Token *>::iterator end = tok->end();
        switch (mode) {
            case '<': return parsePrefix(begin, end);
            case '>': return parsePostfix(begin, end);
            case '|': return parseInfix(begin, end);
        }

        return nullptr;
    }


    ///@brief Parse a prefix expression
    ///@param begin Iterator to the first element
    ///@param end Iterator to the last element
    ///@return The root of the tree
    Token *parsePrefix(vector<Token*>::iterator begin, vector<Token*>::iterator end)
    {
        stack<Token*> *s = new stack<Token*>();
        for(; begin != end; begin++)
        {
            Token* token = *begin;
            if (dynamic_cast<Num *>(token) != nullptr)
            {
                s->push(token);
            }
            else if (dynamic_cast<Operator *>(token) != nullptr)
            {
                Token *op2 = s->top();
                s->pop();
                Token *op1 = s->top();
                s->pop();
                Token *BaumElement = new Operator(token->getType(), op2, op1);
                s->push(BaumElement);
            }
        }
        Token *result = s->top();
        s->pop();
        delete s;
        return result;

    }



    ///@brief Parse a postfix expression
    ///@param begin Iterator to the first element
    ///@param end Iterator to the last element
    ///@return The root of the tree
    Token *parsePostfix(vector<Token *>::iterator begin, vector<Token *>::iterator end) {

        stack<Token *> *s = new stack<Token *>();
        begin--;
        for (; begin != end; end--) {
            Token *token = *end;
            if (dynamic_cast<Num *>(token) != nullptr) {
                s->push(token);
            } else if (dynamic_cast<Operator *>(token) != nullptr) {
                Token *op1 = s->top();
                s->pop();
                Token *op2 = s->top();
                s->pop();
                Token *BaumElement = new Operator(token->getType(), op2, op1);
                s->push(BaumElement);
            }
        }
        Token *result = s->top();
        s->pop();
        delete s;
        return result;

    }



    ///@todo
    Token* parseInfix(vector<Token*>::iterator i, vector<Token*>::iterator end)
    {
        stack<Token*> *s = new stack<Token*>();

        Token *result = s->top();
        s->pop();
        delete s;
        return result;

    }

};

#endif //LABOR_ALGORITHMS_EVALUATOR_HPP