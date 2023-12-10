#ifndef ARVORE_H
#define ARVORE_H
#include "node.h"

class Arvore{
    private:
        Node* R;
    public:
        Arvore();
        ~Arvore();
        //bool inserir(int);
        Node *inserir(Node *, int);
        Node* remover(Node*, int);
        bool estaNaArvore(Node*, int) const;
        bool vazia() const;
        void imprimirElementos(Node*) const;
        Node* getRaiz() const;
};

#endif