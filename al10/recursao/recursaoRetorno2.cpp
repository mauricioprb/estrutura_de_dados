#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct no {
    int dado;
    struct no *prox;
} Celula;

Celula *inserirR(int valor, Celula *lista) {
    if(lista && valor > lista->dado) {
        // Avançar até o final ou até a posição correta
        lista->prox = inserirR(valor, lista->prox);
        return lista;
    } else {
        Celula *novo = (Celula*)malloc(sizeof(Celula));
        novo->dado = valor;
        novo->prox = lista; // Atenção neste ponto
        return novo;
    }
}

void exibirR(Celula *lista) {
    if(lista) {
        // Exibir
        cout << lista->dado << endl;
        exibirR(lista->prox);
    }
}

int main() {
    Celula *lista = NULL;

    lista = inserirR(45, lista);
    lista = inserirR(5, lista);
    lista = inserirR(4, lista);
    lista = inserirR(12, lista);
    exibirR(lista);

    return 1;
}