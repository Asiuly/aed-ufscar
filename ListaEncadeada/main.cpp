#include "fila.h"
#include "node.h"
#include <iostream>

using namespace std;

int main(){
    Fila fila1;

    cout<< "Primeiro elemento: " << fila1.exibirPrimeiroElemento() << endl;
    fila1.desenfileirar();

    for(int i = 1; i<6; i++){
        fila1.enfileirar(i);
    }
    
    cout<< "Primeiro elemento(2): " << fila1.exibirPrimeiroElemento() << endl;
    cout<< "Elemento desempilhado: " <<fila1.desenfileirar() <<endl;
    cout<< "Primeiro elemento(3): " << fila1.exibirPrimeiroElemento() << endl;

    fila1.~Fila();
    return 0;
}