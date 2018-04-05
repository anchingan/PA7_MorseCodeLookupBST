//
// Created by Ching-An Tsai on 02/04/2018.
//

#ifndef PA7_BST_H
#define PA7_BST_H

#include <fstream>
#include <locale>
#include "Node.h"

using std::fstream;
using std::ifstream;
using std::toupper;


class BST {
public:
    BST();
    ~BST();

    void insert(Node *node);
    bool isEmpty();
    void printTree();
    string search(const char c);
    void convert(string str);
    void convertFile();


private:
    Node *root;
    void triverseBST(Node *node);
    void readTable();



};


#endif //PA7_BST_H
