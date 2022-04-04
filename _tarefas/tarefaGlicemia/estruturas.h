#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

typedef struct no{
    int valorGlicemia;
    string data;
    string hora;
    struct no *prox;
}Celula;

Celula *inserirPilha(int valor, Celula *topo){
    // Alocar memórira
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    // Depositar valor
    novo->valorGlicemia = valor;
    // Engatar o novo no ultimo
    novo->prox = topo;
    // Retornar o novo top
    return novo;
}

Celula *inserirLista(int valor, Celula *lista){
    Celula *novo, *p, *pR;

    // Alocar memória
    novo = (Celula *)malloc(sizeof(Celula));
    // Depositar valores
    novo->valorGlicemia = valor;
    novo->prox = NULL;
    // Localizar a posição de inserção
    // Testar primeira vez:
    if (!lista) return novo;

    for (pR = NULL, p = lista; p; pR = p, p = p->prox){
        if (valor < p->valorGlicemia){ // Encontrei a posição
            break;
        }
    }
    // Engatar
    // Testar se no inicio
    if (p == lista){
        novo->prox = lista;
        return novo;
    }
    else if (!p){ // Testar se no fim
        pR->prox = novo;
    }
    else{ // No meio
        pR->prox = novo;
        novo->prox = p;
    }
    return lista;
}

void exibirPilha(Celula *topo) {
    if (!topo){
        cout << "Pilha vazia!\n";
        return;
    }
    Celula *p;
    for (p = topo; p ; p = p->prox){
        cout << p->valorGlicemia << endl;
    } 
}

void exibirLista(Celula *lista){
    if (!lista){
        cout << "Lista vazia!\n";
        return;
    }
    Celula *p;
    for (p = lista; p; p = p->prox){
        cout << p->valorGlicemia << endl;
    }
}

void popularDoArquivo(Celula **topo, Celula **lista){
    // ifstream -> input
    // ofstream -> output
    ifstream procurador;
    string nomeArquivo;

    cout << "Informe o nome do arquivo com os dados da glicemia: ";
    cin >> nomeArquivo;

    procurador.open(nomeArquivo);

    if (!procurador){
        cout << "Arquivo não localizado!\n";
        return;
    }
    
    int valor;

    string linha;
    string valorGlicemia;

    int posicaoEspaco = 0;
    while (getline(procurador, linha)){
        posicaoEspaco = linha.find(" ");

        // Extrair glicemia
        valorGlicemia = linha.substr(0,posicaoEspaco);
        *topo = inserirPilha(stoi(valorGlicemia), *topo);
        *lista = inserirLista(stoi(valorGlicemia), *lista);
    }

    procurador.close();
}

int contarElementosLista(Celula *lista){
    int qtd = 0;
    Celula *p;
    for(p = lista; p; p = p->prox){
        qtd++;
    }
    return qtd;
}

float calcularMedia(Celula *lista){
    int soma = 0;
    Celula *p;
    for(p = lista; p; p->prox){
        soma += p->valorGlicemia;
    }

    float media = soma / contarElementosLista(lista);
    return media ;
}