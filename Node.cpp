//
// Created by Ching-An Tsai on 02/04/2018.
//

#include "Node.h"

Node::Node(char c, const string &str) {
    mChar = c;
    mStr = str;
    pLeft = nullptr;
    pRight = nullptr;
}

Node::~Node() {

}

void Node::setChar(char c) {
    mChar = c;
}

void Node::setString(const string &str) {
    mStr = str;
}

char Node::getChar() const{
    return mChar;
}

string Node::getStr() const{
    return mStr;
}

void Node::setLeft(Node *left) {
    pLeft = left;
}

void Node::setRight(Node *right) {
    pRight = right;
}

Node *Node::getLeft(){
    return pLeft;
}
Node *Node::getRight(){
    return pRight;
}

ostream &operator << (ostream &out, const Node &node) {
    out << node.getChar() << ":" << node.getStr() << endl;
    return out;
}
