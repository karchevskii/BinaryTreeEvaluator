#include <iostream>
#include <string>

#include "Evaluator.hpp"

using namespace std;

///@brief function to parse arguments and check if all arguments are given
///@param argc number of arguments
///@param argv array of arguments
int main(int argc, char* argv[])
{
    string exp;

    if (argc > 1) exp = argv[1];
    for (int i = 2; i < argc; i++)
    {
        exp += argv[i];
    }
    if (!exp.length())
        cout << "Arguments needed!" << endl;
    else
    {
        char mode = argv[1][0];
        if (mode == '<' || mode == '|' || mode == '>') { // Prefix, Infix, Postfix
            exp = exp.substr(1);
            cout << "Mode:" << mode << endl;
            cout << "Expression:" << exp << endl;
        }
        else{
            cout << "Mode: Infix" << endl;
            cout << "Expression:" << exp << endl;
            mode = '|'; // Standard: Infix
        }

//        string exp = "10 4 5*+84 12 / 1 -/";
//        char mode = '>';
//        string exp= "/+10*4 5-/84 12 1";
//        char mode = '<';
        Evaluator e;
        e.evaluate(exp, mode);
    }
    return 0;
}