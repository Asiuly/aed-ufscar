#include "Arvore.h"
#include <iostream>

using namespace std;
int main() {
    Arvore minhaArvore;

    Node *aux = minhaArvore.getRaiz();
    minhaArvore.inserir(minhaArvore.getRaiz(), 50);
    minhaArvore.inserir(minhaArvore.getRaiz(), 30);
    minhaArvore.inserir(minhaArvore.getRaiz(), 70);
    minhaArvore.inserir(minhaArvore.getRaiz(), 20);
    minhaArvore.inserir(minhaArvore.getRaiz(), 40);
    minhaArvore.inserir(minhaArvore.getRaiz(), 60);
    minhaArvore.inserir(minhaArvore.getRaiz(), 80);

    cout << "Elementos na arvore: ";
    minhaArvore.imprimirElementos(minhaArvore.getRaiz());
    cout << endl;

    int valorProcurado = 40;
    if (minhaArvore.estaNaArvore(minhaArvore.getRaiz(), valorProcurado)) {
        cout << valorProcurado << " esta na arvore." << endl;
    } else {
        cout << valorProcurado << " nao esta na arvore." << endl;
    }

    int valorRemover = 30;
    if (minhaArvore.remover(minhaArvore.getRaiz(), valorRemover)) {
        cout << valorRemover << " removido da arvore." << endl;
    } else {
        cout << valorRemover << " nao encontrado na arvore." << endl;
    }

    cout << "Elementos na arvore apos a remocao: ";
    minhaArvore.imprimirElementos(minhaArvore.getRaiz());
    cout << endl;

    return 0;
}
