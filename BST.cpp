//
// Created by Ching-An Tsai on 02/04/2018.
//

#include "BST.h"

BST::BST() {
    root = nullptr;
    readTable();
}

BST::~BST() {}

void BST::insert(Node *node) {
    if (node != nullptr) {
        if (isEmpty())
            root = node;
        else {
            Node *preNode = nullptr, *currentNode = root;
            char nodeChar = node->getChar();
            while (currentNode != nullptr){
                preNode = currentNode;
                if (nodeChar >= currentNode->getChar())
                    currentNode = currentNode->getRight();
                else
                    currentNode = currentNode->getLeft();
            }
            if (nodeChar >= preNode->getChar())
                preNode->setRight(node);
            else
                preNode->setLeft(node);
        }
    }
}

bool BST::isEmpty() {
    if (root == nullptr)
        return true;
    return false;
}

void BST::printTree() {
    if(!isEmpty())
        triverseBST(root);
}

void BST::triverseBST(Node *node) {
    if (node != nullptr) {
        triverseBST(node->getLeft());
        cout << *node ;
        triverseBST(node->getRight());
    }
}

void BST::readTable() {
    fstream inStream;
    inStream.open("/Users/chingan/Documents/Cpts122/PA7/MorseTable1.txt");
    string str, delimiter = ",", token;
    const char *c;
    size_t pos = 0;

    while (getline(inStream, str)) {
        if ((pos = str.find("\"")) != std::string::npos) {
            delimiter = "\"";
            str.erase(0, pos + delimiter.length());
            pos = str.find("\"");
            token = str.substr(0, pos);
            c = token.c_str();
            str.erase(0, pos + delimiter.length());
            delimiter = ",";
            pos = str.find(delimiter);
            str.erase(0, pos + delimiter.length());
        }
        else if ((pos = str.find(delimiter)) != std::string::npos) {
            token = str.substr(0, pos);
            c = token.c_str();
            str.erase(0, pos + delimiter.length());
            if (!str.empty() && str[str.size() - 1] == '\r')
                str.erase(str.size() - 1);
//            delimiter = "\r";
//            pos = str.find(delimiter);
//            str = str.substr(0, pos);
        }
        insert(new Node(*c,str));
    }

//    for (int i = 0; i < 15; i++){
//        getline(inStream, str);
//        if ((pos = str.find(delimiter)) != std::string::npos) {
//            token = str.substr(0, pos);
//            c = token.c_str();
//            str.erase(0, pos + delimiter.length());
//        }
//        insert(new Node(*c,str));
//    }
    inStream.close();
}

string BST::search(const char c) {
    char target = c;
    target = toupper(target);
    string result = "";
//    int i = 0; //
    bool found = false;
    if (!isEmpty()){
        Node *current = root, *prevNode;
        char charOfNode;
        while (current != nullptr){
//            i++;//
//            cout << "search time: " << i << endl; //
            prevNode = current;
            charOfNode = current->getChar();
            if (target == charOfNode) {
                found = true;
                break;
            }
            else if (target > charOfNode)
                current = current->getRight();
            else
                current = current->getLeft();
        }
        if (found){
            result = current->getStr();
        }
    }
    return result;
}

void BST::convert(string str) {
    string result = "", tmp;
    char *cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());
    for (int i = 0; i < str.length() + 1; i++){
        if (cstr[i] == ' ')
            result.append("   ");
        else {
            tmp = search(cstr[i]);
            result.append(tmp);
            result.append(" ");
        }
    }
    cout << result << endl;
}

void BST::convertFile() {
    fstream inputFile;
    inputFile.open("/Users/chingan/Documents/Cpts122/PA7/convert.txt");
    string str;
    while(getline(inputFile, str)) {
        convert(str);
    }
    inputFile.close();

}


