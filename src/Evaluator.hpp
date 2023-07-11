#ifndef BINARY_TREE_EVALUATOR_EVALUATOR_HPP
#define BINARY_TREE_EVALUATOR_EVALUATOR_HPP

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

    ///@brief evaluates the expression
    ///@param exp the expression
    ///@param mode the mode '<': Prefix, '|': Infix, '>': Postfix
    void evaluate(string exp, char mode)
    {

        ///@brief Tokenize the expression
        Tokenizer *t = new Tokenizer(exp);

        ///@brief Construct the tree from the tokens
        Token *e = parse(t->tokenize(), mode);

///@test strings for testing
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
        // Nodes: 9
        // Depth:   4

        ///@brief print the evaluated expression
        cout << "Prefix:  " << e->prefix() << " = " << e->eval() << endl;
        cout << "Infix:   " << e->infix() << " = " << e->eval() << endl;
        cout << "Postfix: " << e->postfix() << " = " << e->eval() << endl;
        cout << "Nodes: " << e->nodes() << endl;
        cout << "Depth: " << e->depth() << endl;

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
    Token *parse(vector<Token *> *tok, char mode)
    {
        vector<Token *>::iterator begin = tok->begin(); // tok is inverted so begin is end
        vector<Token *>::iterator end = tok->end(); // tok is inverted so end is begin

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
            if (dynamic_cast<Num *>(token) != nullptr) // checks if Element is Num
            {
                s->push(token);
            }
            else if (dynamic_cast<Operator *>(token) != nullptr) // checks if Element is Operator
            {
                Token *op2 = s->top(); s->pop();
                Token *op1 = s->top(); s->pop();

                // add new Element to stack with operation and operands
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
        begin--; // begin reduced by 1 to cover whole vector
        for (; begin != end; end--)
        {
            Token *token = *end;
            if (dynamic_cast<Num *>(token) != nullptr) // checks if Element is Num
            {
                s->push(token);
            }
            else if (dynamic_cast<Operator *>(token) != nullptr) // checks if Element is Operator
            {
                Token *op1 = s->top(); s->pop();
                Token *op2 = s->top(); s->pop();
                // add new Element to stack with operation and operands
                Token *BaumElement = new Operator(token->getType(), op2, op1);
                s->push(BaumElement);
            }
        }
        Token *result = s->top();
        s->pop();
        delete s;
        return result;

    }



    ///@brief Parse an infix expression
    ///@param begin Iterator to the first element
    ///@param end Iterator to the last element
    ///@return The root of the tree
    Token* parseInfix(vector<Token*>::iterator begin, vector<Token*>::iterator end)
    {
        stack<Token*> *s = new stack<Token*>();
        end--;
        begin--;

        for (; begin != end; end--)
        {
            Token *token = *end;

            if (dynamic_cast<Num *>(token) != nullptr) // checks if Element is Num
            {
                s->push(token);
            }
            else if (dynamic_cast<Operator *>(token) != nullptr) // checks if Element is Operator
            {
                s->push(token);
            }
            else if (dynamic_cast<Bracket *>(token) != nullptr && token->getValue() == "(") //opening bracket
            {
                s->push(token);
            }
            else if (dynamic_cast<Bracket *>(token) != nullptr && token->getValue() == ")") //closing bracket
            {
                Token *firstNum = s->top(); s->pop();
                Token *op = s->top(); s->pop();
                Token *secondNum = s->top(); s->pop();

                s->pop(); // pop opening bracket

                // add new Element to stack with operation and operands
                Token *BaumElement = new Operator(op->getType(), secondNum, firstNum);
                s->push(BaumElement);
            }
        }

        Token *result = s->top();
        s->pop();
        delete s;
        return result;

    }

};

#endif //BINARY_TREE_EVALUATOR_EVALUATOR_HPP