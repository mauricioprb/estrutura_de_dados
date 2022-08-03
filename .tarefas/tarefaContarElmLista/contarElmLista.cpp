#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

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

// Função para contar os elementos da lista
int contarElementos(Celula *lista){
    int qtd = 0;
    Celula *p;
    for(p = lista; p; p = p->prox){
        qtd++;
    }
    return qtd;
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
    cout << "\nNúmero de elementos no arquivo: " << contarElementos(lista) << endl;
}

Celula *popularDoArquivo(Celula *lista){
    // ifstream -> input ou ler
    // ofstream -> output ou escrever

    ifstream procurador;
    char nomeArquivo[200];

    cout << "Informe caminho e nome do arquivo fonte com números: ";
    cin >> nomeArquivo;

    procurador.open(nomeArquivo);

    if(!procurador){
        cout << "Arquivo não localizado!\n";
        return NULL;
    }

    string linha;
    int valor;

    while(getline(procurador, linha)){
        stringstream pegaInteiro(linha);
        pegaInteiro >> valor;
        lista = inserir(valor, lista); // Inserção ordenada

    }

    procurador.close();
    return lista;
}

int main(){
    Celula *lista = NULL;

    lista = popularDoArquivo(lista);

    exibir(lista);

    return 1;
}