#include "cadastro.h"
#include <iostream>

using namespace std;

//cria o cadastro
Cadastro:: Cadastro(): primeiro{nullptr}, atual{nullptr} { }

Cadastro::~Cadastro() {
    while (primeiro != nullptr) {
        Node* temp = primeiro;
        primeiro = primeiro->next;
        delete temp; // libera a memória do nó
    }
}

//versao simplificada do procuraX passando apenas o parametro de valor pra procurar
bool Cadastro:: estaNaLista(int valor) const{
    Node* anterior;
    Node* proximo;
    proximo=primeiro;
    anterior=nullptr;
    bool achouX;

    achouX = procuraX(valor, proximo, anterior);
    if(achouX == true)
        return true;
    else
        return false;

}

void Cadastro:: insere(int valor, bool &OK){
    //Lista ordenada, devemos inserir o valor no local correto!

    Node* anterior;
    Node* proximo;
    bool achouX = procuraX(valor, anterior, proximo);

    if(achouX == true){
        OK = false;
    }
    else{
        Node* novoNode = new Node(valor);

        if(proximo == primeiro){ //esse caso pode ocorrer se VALOR for o menor da lista e o ponteiro atual não conseguiu
                                //percorrer nada já parando no primeiro elemento, ou se primeiro aponta para null
                                //e nao existe nenhum elemento na lista, em ambos os casos VALOR entra como 1º

            novoNode->next = proximo; //fazendo o elemento/null que estava maior que VALOR ser apontado por ele
            primeiro = novoNode; //ele agora é o primeiro

            novoNode = nullptr; //já o alocamos e fizemos ser apontado, sem utilidade para esse auxiliar
            anterior = nullptr;
            proximo = nullptr;
            OK = true;
        }
        else if (proximo != primeiro){ //significa que na função procura, não foi encontrado um valor maior que VALOR ou, no
                                     // minimo, valor é maior que o primeiro elemento, já que a função primeiro para de 
                                     //percorrer o ponteiro ao encontrar um valor maior que valor, ou seja, valor será
                                     //inserido no meio ou final da fila.

            anterior->next = novoNode; //menor valor antes do valor maior que VALOR ou ultimo elemento da lista 
                                       //valor anterior de VALOR na lista então apontará para ele

            novoNode->next = proximo; //ATUAL está apontando para nulo ou para o elemento maior que VALOR mais próximo
            
            OK = true;

            proximo = nullptr;
            anterior = nullptr;
            novoNode = nullptr; //podemos tirar o ponteiro auxiliar, o nó já está inserido e apontado pelo anterior

        }
    }
}

void Cadastro:: retira(int valor, bool &OK){
    Node* anterior;
    Node* proximo;

    bool achouX = procuraX(valor, proximo, anterior);

    if(achouX == false){
        OK = false; //lista vazia ou elemento nao encontrado para retirada
    }
    else if(proximo == primeiro){ // se VALOR estiver no primeiro elemento, apenas passar para o proximo e deletar
        primeiro = primeiro->next;
        delete proximo;
        proximo = nullptr;
        OK = true;
    }
    else{
        anterior->next = proximo->next; //faz o anterior apontar para o postreior para sumir com o VALOR (no meio)

        delete proximo;
        proximo = nullptr;
        anterior = nullptr;
        OK = true;
    }
}

bool Cadastro:: vazia() const{
    return (primeiro ==nullptr);
}

bool Cadastro:: cheia() const{
    return false; //listas encadeadas nao enchem
}

bool Cadastro:: pegaPrimeiro(int &primeiroElemento){
    atual = primeiro; //atualizando o ponteiro de chamada para o atual primeiro
    bool temElemento;

    if(atual != nullptr){
        primeiroElemento = atual->info; //retorna por parametro para ser atribuido o valor do primeiro elemento
        temElemento = true;
    }
    else{
        temElemento = false;
    }

    return temElemento;
}

bool Cadastro:: pegaProximo(int &proximoElemento){
    bool temElemento;

    if(atual != nullptr){ //se atual ter sido modificado para apontar para um elemento, tenta passar para o proximo
        atual = atual->next;
    }

    if(atual == nullptr){//se tinha um atual, ele avançou, mas foi parar no null, não tem próximo
        temElemento = false;
    }
    else{
        proximoElemento = atual->info;
        temElemento = true;
    }

    //no final, atual ficará apontando para o proximo elemento depois do ultimo a qual ela estava apontando

    return temElemento;
}

bool Cadastro:: procuraX(int valor, Node* &proximo, Node* &anterior) const{
    proximo = primeiro; //colocando proximo no valor que ficaria na frente de VALOR se ele fosse o menor
    anterior = nullptr;
    
    while ((proximo!= nullptr) && (proximo->info < valor)){ //passa para o proximo caso VALOR for maior e nao for o fim 
                                                            //da lista
        anterior = proximo;
        proximo = proximo->next;
    }

    if((proximo!=nullptr) && (proximo->info == valor)){ //se a info de onde o proximo parou é o VALOR, ele parou pois o 
                                                        //valor ja existe
        return true;
    }
    else{ //se psasou todos os elementos/até achar um maior que VALOR e ele nao foi encontrado, nao esta na lista
        return false;
    }
    //no fim, proximo fica organizado como apontando para o maior numero mais proximo de VALOR e anterior 
    //aponta para o numero mais proximo de VALOR sendo menor que ele
}