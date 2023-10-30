#include "fila.h"
#include <iostream>

using namespace std;

  //cria fila = construtor da classe
Fila:: Fila(): primeiroElemento(nullptr), ultimoElemento(nullptr) { } 

Fila:: ~Fila(){
    while (!isVazia()) {
        desenfileirar();
    }
}

bool Fila:: isVazia() const{
    return (primeiroElemento == nullptr);
}

void Fila:: enfileirar(int valor){
    Node* no1 = new Node(valor);

    if(isVazia()){
        primeiroElemento = no1;
        ultimoElemento = primeiroElemento;
    }
    else{
        ultimoElemento->next = no1; //fazendo com que o penultimo(que estava em ultimo) aponte para o atual ultimo
        ultimoElemento = no1; //substituindo o atual penultimo pelo atual ultimo no nosso ponteiro que aponta para o ultimo atual
    }                           //OBS: a info de no1 ja esta setada como valor na criação do nó
}

int Fila:: desenfileirar(){
    if(isVazia()){
        cout << "Fila vazia, sem elementos para desenfileirar" << endl;
        return 0;
    }

    int valor = primeiroElemento->info; //valor recebe o dado do primeiro elemento (que vai sair)
    Node* temp = primeiroElemento; //deixando um ponteiro apontado para o ponteiro primeiro elemento
                                    //para que ele nao se perca nas atribuições

    if(primeiroElemento == ultimoElemento){
        primeiroElemento = nullptr;
        ultimoElemento = nullptr;
    }
    else{
        primeiroElemento = primeiroElemento->next; //ponteiro primeiro elemento agora aponta para o proximo da fila
    }

    delete temp;
    return valor;
}

int Fila:: exibirPrimeiroElemento() const{
    if(isVazia()){
        cout << "Fila vazia, nada para exibir" << endl;
        return 0;
    }

    return primeiroElemento->info;
}