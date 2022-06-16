#include <iostream>
#include <cstdlib>
using namespace std;

// Estrutura de dados
typedef struct no{
    int dado;
    struct no *prox;
} Celula;

Celula *inserir(int valor, Celula *lista){
    Celula *novo, *p, *pR;
    // Alocar memória
    novo = (Celula *)malloc(sizeof(Celula));

    // Depositar valores
    novo->dado = valor;
    novo->prox = NULL;

    // Localizar a posição de inserção
    // Testar para primeira vez
    if(!lista) return novo;

    for(pR = NULL, p = lista; p; pR = p, p = p->prox){
        if(valor < p->dado){ // Encontrei a posição        
            break;
        }
    }
    // Fim

    // Engatar
    // Testar se no início
    if(p == lista){
        novo->prox = lista; // novo->prox = p;
        return novo;
    } else if(!p){ // Testar se no fim
        pR->prox = novo;
        return lista;
    } else{ // No meio
        pR->prox = novo;
        novo->prox = p;
    }

    // Retornar o início da lista
    return lista;
}

void exibir(Celula *lista){
    if(!lista){
        cout << "Lista vazia\n";
        return;
    }
    Celula *p;
    for(p = lista; p; p = p->prox){
        cout << p->dado << endl;
    }
}

int main(){
    Celula *lista = NULL;

    lista = inserir(2, lista);
    lista = inserir(1, lista);
    lista = inserir(10, lista);
    lista = inserir(4, lista);

    exibir(lista);

    return 1;
}