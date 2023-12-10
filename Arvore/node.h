#ifndef NODE_H
#define NODE_H

class Node{
    private: 
        int info;
        Node* esq;
        Node* dir;
    public:
        Node(int valor): info(valor), esq(nullptr), dir(nullptr) {}
        ~Node(){}
        friend class Arvore;
};

#endif