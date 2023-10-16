#include <stdio.h>

typedef struct{
    int elementos[12];
    int primeiro;
    int ultimo;
    int nroElementos;
}fila;

bool vazia(fila *f){
    return (f->nroElementos == 0 && f->primeiro == f->ultimo);
}

bool cheia(fila *f){
    return (f->nroElementos == 12 && f->primeiro == f->ultimo);
}

void cria(fila *f){
    f->nroElementos = 0;
    f->primeiro = 0;
    f->ultimo = 0;
}

bool insere(fila *f, int elemento){
    if (cheia(f)==true) {
        return false;
    }

    f->elementos[f->ultimo] = elemento;
    f->ultimo++;

    if (f->ultimo == 12) {
        f->ultimo = 0;
    }

    f->nroElementos++;
    return true;
}

bool retira(fila *f, int *elemento){    
    if (vazia(f)) {
        return false; 
    }

    *elemento = f->elementos[f->primeiro];
    f->primeiro++;
    if (f->primeiro == 12) {
        f->primeiro = 0;
    }

    f->nroElementos--;
    return true;
}
