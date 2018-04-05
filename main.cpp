#include <iostream>
#include "Node.h"
#include "BST.h"

int main() {
    BST tree;
//    Node a('A', ".-");


//    cout << a << endl;
//    Node b('B', "-...");
//    a.setRight(&b);
//    Node c('C', "-.-.");
//    tree.insert(&b);
//    tree.insert(&a);
//    tree.insert(&c);
//    Node d('D', "-..");
//    tree.insert(&d);
    tree.printTree();
    tree.convertFile();
//    tree.convert("This is a test of the cpts 122");

//    a.setLeft(&c);
//    cout << *(a.getRight()) << endl;
//    cout << *(a.getLeft()) << endl;



    return 0;
}