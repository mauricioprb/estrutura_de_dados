#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

// Struct utilizado tanto pra pilha quanto pra lista
typedef struct no{
    int dado;
    string data;
    string hora;
    struct no *prox;
} Celula;

// Mostra os valores glicemicos do mais recente (topo) ao mais antigo
void exibirPilha(Celula *topo){
    Celula *p;
    for(p = topo; p; p = p->prox){
        cout << p->dado << endl;
    }
}

Celula *inserirPilha(int valor, Celula *topo){
    // Alocar memoria
    Celula *novo = (Celula*)malloc(sizeof(Celula));

    // Depositar valores
    novo->dado = valor;

    // Engatar o ultimo no topo
    novo->prox = topo;

    // Retornar o novo topo
    return novo;
}

// Mostra os valores ordenados, do menor ao maior
void exibirLista(Celula *lista){
    Celula *p;
    for(p = lista; p; p = p->prox){
    cout << p->dado << endl;
    }
}

// Inserir na lista de forma ordenada tendo como chave o dado
Celula *inserirLista(int valor, Celula *lista){
    // Alocar memoria
    Celula *novo = (Celula*)malloc(sizeof(Celula));

    // Depositar valores
    novo->dado = valor;
    novo->prox = NULL;

    // Percorrer para encontrar o local adequado na lista
    // Testar se é a primeira vez
    if (!lista) return novo;

    Celula *p, *pR;
    for(pR = NULL, p = lista; p; pR = p, p = p->prox){
        if (valor < p->dado) break;
    }

    // É o primeiro
    if(p == lista){
        novo->prox = lista;
        return novo;
    }
    // É o último
    if(!p){
        pR->prox = novo;
    } else{ 
        pR->prox = novo;
        novo->prox = p;
    }
    // Retorna o início da lista
    return lista;  
}

Celula *popular(Celula *lista, int n){
    srand(time(NULL));

    for(int i = 0; i < n; i++){
        lista = inserirLista(rand() % 100, lista);
    }
    return lista;
}

// Método que recebe uma lista e retorna a quantidade de elementos da lista de dados glicêmicos
int contarElementosLista(Celula *lista){
    int contador = 0;
    Celula *p;
    for(p = lista; p; p = p->prox){
        contador++;
    }
    return contador;
}

// Calcula a média glicêmica
float mediaDado(Celula *lista){
   int soma = 0;
   Celula *p;
   for(p = lista; p ; p = p->prox){
       soma += p->dado;
   }
   return soma / contarElementosLista(lista);
}

// Calcula a mediana glicêmica
float medianaDado(Celula *lista){
    int quantidadeElementos = contarElementosLista(lista);
    bool par;

    if(quantidadeElementos % 2 == 0){
        par = true;
    }else{
        par = false;
    }

    int i;
    int metade;
    Celula *p;
    if(!par){
        metade = (int)quantidadeElementos/2;
    }else{
        metade = (int)quantidadeElementos/2 - 1;
    }
    for(i = 0, p = lista; i < metade; i++, p = p->prox);

    if(!par) return p->dado;
    
    return (p->dado + p->prox->dado) / 2;
}

int maiorValorDado(Celula *lista){
    int maiorValor = lista->dado;
    while(lista != NULL){
        if(lista->dado > maiorValor){
            maiorValor = lista->dado;
        }
        lista = lista->prox;
    }
    return maiorValor;
}

Celula *excluirLista(int valor, Celula *lista){
    Celula *p, *pR;

    if(!lista){
        cout << "Lista vazia!" << endl;
        return lista;
    }
    for(pR = NULL, p = lista; p; pR = p, p = p->prox){
        if(valor == p->dado){
            // É o primeiro
            if(p == lista){
                lista = lista->prox;
            } else if(!p->prox){
                pR->prox = NULL;
            } else{
                pR->prox = p->prox;
            }
            free(p);
            return lista;
        }
    }
    cout << "Valor não localizado para exclusão!" << endl;
    return lista;
}

Celula *excluirOcorrencia(int valor, Celula *lista){
    Celula *p;

    for(p = lista; p; p = p->prox){
        if(valor == p->dado){
            lista = excluirLista(valor, lista);
        }
    }
    return lista;
}