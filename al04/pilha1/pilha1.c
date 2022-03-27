#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *prox; // Ponteiro para o próximo elemento
} Celula;

Celula *inserir(int valor, Celula *topo){
    // Alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    // Depositar valor
    novo->dado = valor;

    // Engatar o novo no último
    novo->prox = topo;

    // Retornar o novo topo
    return novo;
}

Celula *remover(Celula *topo){
    // Testar se pilha vazia
    if(!topo){
        printf("Pilha vazia. Operação não realizada\n");
        return topo;
    }
    // Ponteiro lixo aponta para o topo/último
    Celula *lixo = topo;

    // Topo avança
    topo = topo->prox;

    // Liberar lixo
    free(lixo);

    // Retornar novo topo
    return topo;
}

int contarNos(Celula *topo){
    int qtd = 0;
    Celula *p;

    for(p = topo; p; p = p->prox){
        qtd++;
    }
    return qtd;
}

void exibir(Celula *topo){
    if(!topo){
        printf("Pilha vazia\n");
        return;
    }
    Celula *p;
    for(p = topo; p; p = p->prox){
        printf("%d\t", p->dado);
    }
    printf("\n");
}

int localizado(int valor, Celula *topo){
    Celula *p;
    if(!topo) return 0; // Pilha vazia, logo não encontrado

    for(p = topo; p; p = p->prox){
        if(valor == p->dado) return 1;
    }
    return 0; // Passou por toda a pilha e não encontrou o valor
}

int main(){
    Celula *pilha1 = NULL; // pilha1 é um ponteiro de Celula que vai apontar para o último elemneto inserido

    pilha1 = inserir(15, pilha1);
    pilha1 = inserir(10, pilha1);
    pilha1 = inserir(5, pilha1);
    pilha1 = inserir(25, pilha1);
    pilha1 = inserir(100, pilha1);

    pilha1 = remover(pilha1);

    printf("Endereço do último elemento: %p\n", pilha1);
    printf("Valor do último elemento: %d\n", pilha1->dado);

    printf("O tamanho da pilha é: %d\n", contarNos(pilha1));
    exibir(pilha1);

    printf("O número 25 está ou não na pilha? %d\n", localizado(25, pilha1));

    return 1;
}