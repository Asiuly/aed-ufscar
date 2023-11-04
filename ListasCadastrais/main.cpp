#include "cadastro.h"
#include "node.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Início do programa" << endl;
    Cadastro listaCadastro;
    bool OK;

    listaCadastro.insere(10, OK);
    listaCadastro.insere(20, OK);
    listaCadastro.insere(30, OK);
    listaCadastro.insere(40, OK);

    cout << "Meio do programa" <<endl;

    return 0;
}
