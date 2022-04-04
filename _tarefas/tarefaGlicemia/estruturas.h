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
    // alocar memomira
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    //depositar valor
    novo->valorGlicemia = valor;
    //engatar o novo no ultimo
    novo->prox = topo;
    //retornar o novo top
    return novo;
}
Celula *inserirLista(int valor, Celula *lista){
    Celula *novo, *p, *pR;

    // alocar memomoria
    novo = (Celula *)malloc(sizeof(Celula));
    // depositar valores
    novo->valorGlicemia = valor;
    novo->prox = NULL;
    // localizar a posicao de inserção
    // testar primeira vez:
    if (!lista)
        return novo;

    for (pR = NULL, p = lista; p; pR = p, p = p->prox){
        if (valor < p->valorGlicemia){ // encontrei a posicao
            break;
        }
    }
    // engatar
    // testar se no inicio
    if (p == lista){
        novo->prox = lista;
        return novo;
    }
    else if (!p){ // testar se no fim
        pR->prox = novo;
    }
    else{ // no meio
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
    // ifstream -> inputar
    // ofstream -> output
    ifstream procurador;
    char nomeArquivo[200];

    cout << "Informe o caminho do arquivo com números: ";
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

        //extrair glicemia
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

int calcularMedia(Celula *lista){
    int soma = 0;
    Celula *p;
     for(p = lista; p; p->prox){
         soma+= p->valorGlicemia;
     }
     return soma / contarElementosLista(lista);
}