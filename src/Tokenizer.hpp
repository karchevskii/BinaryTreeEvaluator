#ifndef BINARY_TREE_EVALUATOR_TOKENIZER_HPP
#define BINARY_TREE_EVALUATOR_TOKENIZER_HPP
#include <string>
#include <vector>

#include "Num.hpp"
#include "Bracket.hpp"
#include "Operator.hpp"


using namespace std;

class Tokenizer
{

    string src;

public:
    Tokenizer(string s)
    {
        src = s + " "; //empty space to avoid running over the string border
    }

    ///@brief Tokenize the expression
    vector<Token*>* tokenize()
    {
        vector<Token*>* tokens = new vector<Token*>();
        vector<Token*>::iterator i = tokens->begin();

        for(int j = 0; j < src.length(); j++)
        {
            char c = src[j];
            if(c == ' ')
                continue;
            if(c == '(' || c == ')') // case Bracket
            {
                i = tokens->insert(i, new Bracket(c));
                continue;
            }
            if(c == '+' || c == '-' || c == '*' || c == '/') // case Operator
            {
                i = tokens->insert(i, new Operator(c));
                continue;
            }

            if(c >= '0' && c <= '9') // case Num
            {
                // read the whole number instead of just one digit
                int num = 0;
                while(c >= '0' && c <= '9')
                {
                    num = num * 10 + (c - '0');
                    c = src[++j];
                }
                i = tokens->insert(i, new Num(num));
                j--;
                continue;
            }
        }

        return tokens;

    }

};
#endif //BINARY_TREE_EVALUATOR_TOKENIZER_HPP
