#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct no {
    int ficha;
    struct no *prox;
} Celula;

typedef struct {
    Celula *inicio; // Onde são realizadas as remoções
    Celula *fim;    // Onde são realizadas as inserções
} Fila;

void inicializar(Fila *fila) {
    fila->inicio = NULL; // Ponteiro que coordena o primeiro elemento inserido, logo o que vai ser removido
    fila->fim = NULL;    // Ponteiro que coordena o último elemento inserido
}

void inserir(int ficha, Fila *fila) {
    // Alocar memoria
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    // Depositar valores
    novo->ficha = ficha;
    novo->prox = NULL;

    // engatar no fim
    if(!fila->fim) { // Testar se é primeira vez. se sim, a celula vai ser o primeiro e o último ao mesmo tempo
        fila->inicio = novo;
        fila->fim = novo;
        return;
    }

    fila->fim->prox = novo; // O ultimo da fila conhece o novo

    // Atualizar o fim
    fila->fim = novo; // O novo passa a ser o último da fila
}

void exibir(Fila fila) {
    if(!fila.inicio) {
        cout << "Vazia!\n";
        return;
    }
    Celula *p;
    for(p = fila.inicio; p; p = p->prox) {
        cout << p->ficha << "\n";
    }
}

int excluir(Fila *fila){
    // Testar se fila vazia
    if(!fila->inicio) {
        return -27;
    }    

    // Isolar o início em lixo
    Celula *lixo = fila->inicio;

    int valor = fila->inicio->ficha;

    // Avançar o início
    fila->inicio = fila->inicio->prox;

    // Liberar lixo
    free(lixo);

    // Quando fila completamente esvaziada
    if(!fila->inicio) {
        fila->fim= NULL;
    }

    return valor;
}