#ifndef BINARY_TREE_EVALUATOR_VISUALIZER_HPP
#define BINARY_TREE_EVALUATOR_VISUALIZER_HPP
#include "Token.hpp"
#include <iostream>

class Vis
{
public:

    ///@brief Brunch structure for printing the tree
    struct Branch
    {
        Branch *prev;
        std::string str;

        Branch(Branch *prev, std::string str)
        {
            this->prev = prev;
            this->str = std::move(str);
        }
    };

    ///@brief Prints the branch in a visual form, recursively
    ///@param p The branch to print
    void printBranch(Branch *p)
    {
        if (p == nullptr) {
            return;
        }

        printBranch(p->prev);
        cout << p->str;
    }

    ///@brief Prints the tree in a visual form, recursively
    ///@param root The root of the tree
    ///@param prev The previous branch
    ///@param isLeft Whether the current branch is left
    void printTree(Token* root, Branch *prev, bool isLeft)
    {
        if (root == nullptr) {
            return;
        }

        string prev_str = "    ";
        auto *branch = new Branch(prev, prev_str);

        printTree(root->getright(), branch, true);

        if (!prev) {
            branch->str = "———";
        }
        else if (isLeft)
        {
            branch->str = ".———";
            prev_str = "   │";
        }
        else {
            branch->str = "`———";
            prev->str = prev_str;
        }

        printBranch(branch);
        cout << " " << root->getValue() << endl;

        if (prev) {
            prev->str = prev_str;
        }
        branch->str = "   │";

        printTree(root->getleft(), branch, false);
    }

};

#endif //BINARY_TREE_EVALUATOR_VISUALIZER_HPP
