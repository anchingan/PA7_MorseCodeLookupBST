//
// Created by Ching-An Tsai on 02/04/2018.
//

#ifndef PA7_NODE_H
#define PA7_NODE_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Node {
public:
    Node(char c, const string &str);
    ~Node();

    void setChar(char c);
    void setString(const string &str);
    char getChar();
    string getStr();
    void setLeft(Node *left);
    void setRight(Node *right);
    Node *getLeft();
    Node *getRight();


private:
    char mChar;
    string mStr;
    Node *pLeft;
    Node *pRight;
};


#endif //PA7_NODE_H
