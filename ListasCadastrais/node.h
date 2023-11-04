#ifndef NODE_H
#define NODE_H

class Node{
  private:
    int info;
    Node* next;

  public:
    Node(int valor): info{valor}, next{nullptr} { }
    friend class Cadastro;
};

#endif