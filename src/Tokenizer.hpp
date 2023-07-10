//
// Created by Dinar Karchevskii on 08.07.23.
//

#ifndef LABOR_ALGORITHMS_TOKENIZER_HPP
#define LABOR_ALGORITHMS_TOKENIZER_HPP
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
        src = s + " "; // Das Leerzeichen dient dazu, beim Lesen von Zahlen nicht
        // ueber die String-Grenze zu laufen
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
            if(c == '(' || c == ')')
            {
                i = tokens->insert(i, new Bracket(c));
                continue;
            }
            if(c == '+' || c == '-' || c == '*' || c == '/')
            {
                i = tokens->insert(i, new Operator(c));
                continue;
            }
            if(c >= '0' && c <= '9')
            {
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
#endif //LABOR_ALGORITHMS_TOKENIZER_HPP
