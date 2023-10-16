    #include "fila.h"
    #include <iostream>
    #include <string>

    using namespace std;

    // VERIFICADORES //
    void verRetira(fila *f, int *elemento){
        bool deuCerto;
        deuCerto = retira(f, elemento);
        if(!deuCerto){
            cout << "Erro ao retirar elemento " << *elemento << endl;
        }
    }

    void verInsere(fila *f, int elemento) {
        bool deuCerto;
        deuCerto = insere(f, elemento);
        if (!deuCerto) {
            cout << "Erro ao inserir elemento " << elemento << endl;
        }
    }

    // VERIFICADORES //

    // prototipos //
    void imprime(fila*);
    int nroElementos(fila*);
    //prototipos //

    int main(){
        fila f1;
        int elemf1;
        cria(&f1);

        for (int i = 0; i < 6; i++) {
            verInsere(&f1, i);
        }

        fila f2;
        int elemf2;
        cria(&f2);

        for(int i = 6; i > 0; i--){
            verInsere(&f2, i);
        }

        imprime(&f1);
        imprime(&f2);
        elemf1 = nroElementos(&f1);
        elemf2 = nroElementos(&f2);

        cout << "f1 contém " << elemf1 << " elementos!" << endl;
        cout << "f2 contém " << elemf2 << " elementos!" << endl;

        if(elemf1 == elemf2){
            cout << "f1 e f2 contém o mesmo número de elementos!" << endl;
        }
        else{
            cout << "f1 e f2 não contém o mesmo número de elementos!" << endl;
        }

        return 0;
    }

    void imprime(fila *f){
        int elemento;
        fila auxiliar;
        cria(&auxiliar);

        while(vazia(f) == false) {
            verRetira(f, &elemento);
            cout << elemento << " ";
            verInsere(&auxiliar, elemento);
        }

        while(vazia(&auxiliar) == false){
            verRetira(&auxiliar, &elemento);

            verInsere(f, elemento);
        }
        cout << endl;
        return;
    }

    int nroElementos(fila *f){
        int count = 0;
        int elemento;

        fila auxiliar;
        cria(&auxiliar);

        while(vazia(f) == false){
            verRetira(f, &elemento);
            verInsere(&auxiliar, elemento);
            count++;
        }

        while(vazia(&auxiliar) == false){
            verRetira(&auxiliar, &elemento);
            verInsere(f, elemento);
        }
        return count;
    }

