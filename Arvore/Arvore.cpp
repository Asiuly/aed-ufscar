#include "Arvore.h"
#include <iostream>
using namespace std;

Arvore:: Arvore(): R(nullptr) {}

Arvore:: ~Arvore() { }

Node * Arvore::inserir(Node *Raiz, int valor){
    // Caso de parada: Árvore vazia ou ponteiro Raiz (ultimo filho) vazio.
    if(Raiz == nullptr){
        if(R == nullptr){
            R = new Node(valor);
        }
        Raiz = new Node(valor);
        return Raiz;
    }
    else{
        // Caso 2: Valor maior que raíz
        if(Raiz->info < valor){
            Raiz->dir = inserir(Raiz->dir, valor);
        }
        else if(Raiz->info > valor){
            Raiz->esq = inserir(Raiz->esq, valor);
        }
        else{
            return nullptr;
        }
        return Raiz;
    }
}

Node* Arvore:: remover(Node* raiz, int valor){
    if(raiz==nullptr){
        return raiz;
    }
    else{
        if(raiz->info < valor){
            raiz->dir = remover(raiz->dir, valor);
        }
        else if(raiz->info > valor){
            raiz->esq = remover(raiz->esq, valor);
        }
        else{
            Node* aux = raiz;

            if(raiz->esq == nullptr){//zero filhos ou 1
                if (raiz->esq == nullptr) {
                    Node* aux = raiz->dir;
                    delete raiz;
                    return aux;
                }
                else if(raiz->dir == nullptr) {
                    Node* aux = raiz->esq;
                    delete raiz;
                    return aux;
                }
            }
            //Dois filhos
            aux = raiz->dir;
            while (aux->esq != nullptr) {
                aux = aux->esq;
            }

            raiz->info = aux->info;
            raiz->dir = remover(raiz->dir, aux->info);
        }

        return raiz;
    }
}

bool Arvore:: estaNaArvore(Node* atual, int valor) const{
    if(atual==nullptr){
        return false;
    }
    else{ //pode estar
        if(atual->info > valor){
            return estaNaArvore(atual->esq, valor);
        }
        if(atual->info < valor){
            return estaNaArvore(atual->dir, valor);
        }
        else
            return true;
    }
}

bool Arvore:: vazia() const{
    return (R==nullptr);
}

void Arvore::imprimirElementos(Node* atual) const {
    if (atual != nullptr) {
        imprimirElementos(atual->esq);
        cout << atual->info << " ";
        imprimirElementos(atual->dir);
    }
}

 Node* Arvore:: getRaiz() const{
    return R;
}