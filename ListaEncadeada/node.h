#ifndef NODE_H
#define NODE_H

class Node{
  private	: 
    int info;
    Node* next; //next é um ponteiro que vai apontar para o próximo nó da fila
  
  public:
    Node(int valor);
    friend class Fila; //fila consegue acessar os métodos privados de node

};

#endif