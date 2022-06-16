#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct no {
    int dado;
    struct no *prox;
} Celula;

typedef struct {
    Celula *inicio;
    Celula *fim;
} Fila;

void inicializar(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void inserir(int valor, Fila *f) {
    // Alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    // Depositar valores
    novo->dado = valor;
    novo->prox = NULL;

    // Engatar no fim
    if(!f->fim) { // Testar se é primeira vez. se sim, a celula vai ser o primeiro e o último ao mesmo tempo
        f->inicio = novo;
        f->fim = novo;
        return;
    }

    f->fim->prox = novo;

    // Atualizar o fim
    f->fim = novo;
}

int remover(Fila *f) {
    // Testar se fila vazia
    if (!f->inicio) {
        return -27;
    }    

    // Isolar o início em lixo
    Celula *lixo = f->inicio;

    int valor = f->inicio->dado;

    // Avançar o início
    f->inicio = f->inicio->prox;

    // Liberar lixo
    free(lixo);

    // Quando fila completamente esvaziada
    if(!f->inicio) {
        f->fim= NULL;
    }

    return valor;
}