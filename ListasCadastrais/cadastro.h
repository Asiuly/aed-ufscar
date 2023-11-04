#ifndef CADASTRO_H
#define CADASTRO_H
#include "node.h"

class Cadastro{
  private:
    Node* primeiro; //"L" Aponta ao primeiro do cadastro
    Node* atual;

  public:
    Cadastro();
    ~Cadastro();
    bool estaNaLista(int) const;
    void insere(int, bool&);
    void retira(int, bool&);
    bool vazia() const;
    bool cheia() const;
    bool pegaPrimeiro(int &);
    bool pegaProximo(int &);
    bool procuraX(int, Node* &, Node* &) const;

};

#endif