#ifndef FILA_H
#define FILA_H

#include "node.h" //para podermos definir nossos atributos sendo nós

class Fila{
  private:
    Node* primeiroElemento;
    Node* ultimoElemento;

  public:
  //cria fila = construtor da classe
    Fila();
    ~Fila();
    bool isVazia() const;
    bool isCheia() const {return false;} //sem limite de capacidade em listas encadeadas
    void enfileirar(int);
    int desenfileirar();
    int exibirPrimeiroElemento() const;

};

#endif