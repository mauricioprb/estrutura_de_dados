#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Struct utilizado tanto pra pilha quanto pra lista
typedef struct no{
    int valorGlicemia;
    string data;
    string hora;
    struct no *prox;
} Celula;

// Mostra os valores glicemicos do mais recente (topo) ao mais antigo
void exibirPilha(Celula *topo){
    Celula *p;
    for (p = topo; p; p = p->prox){
        cout << p->valorGlicemia << endl;
    }
}

Celula *inserirPilha(int valor, Celula *topo){
    // Alocar memoria
    Celula *novo = (Celula*)malloc(sizeof(Celula));

    // Depositar valores
    novo->valorGlicemia = valor;

    // Engatar o ultimo no topo
    novo->prox = topo;

    // Retornar o novo topo
    return novo;
}

// Mostra os valores ordenados, do menor ao maior
void exibirLista(Celula *lista){
    Celula *p;
    for (p = lista; p; p = p->prox){
    cout << p->valorGlicemia << endl;
    }
}

// Inserir na lista de forma ordenada tendo como chave o valorGlicemia
Celula *inserirLista(int valor, Celula *lista){
    // Alocar memoria
    Celula *novo = (Celula*)malloc(sizeof(Celula));

    // Depositar valores
    novo->valorGlicemia = valor;
    novo->prox = NULL;

    // Percorrer para encontrar o local adequado na lista
    // Testar se é a primeira vez
    if (!lista) return novo;

    Celula *p, *pR;
    for (pR = NULL, p = lista; p; pR = p, p = p->prox){
        if (valor < p->valorGlicemia) break;
    }

    // É o primeiro
    if (p == lista){
        novo->prox = lista;
        return novo;
    }
    // É o último
    if (!p){
        pR->prox = novo;
    } else{ 
        pR->prox = novo;
        novo->prox = p;
    }
    // Retorna o início da lista
    return lista;  
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

// Método que recebe uma lista e retorna a quantidade de elementos da lista de dados glicêmicos
int contarElementosLista(Celula *lista){
    int contador = 0;
    Celula *p;
    for (p = lista; p; p = p->prox){
        contador++;
    }
    return contador;
}

// Calcula a média glicêmica
float mediaGlicemia(Celula *lista){
   int soma = 0;
   Celula *p;
   for (p = lista; p ; p = p->prox){
       soma += p->valorGlicemia;
   }
   return soma / contarElementosLista(lista);
}

// Calcula a mediana glicêmica
float medianaGlicemia(Celula *lista){
    int quantidadeElementos = contarElementosLista(lista);
    bool par;

    if (quantidadeElementos % 2 == 0){
        par = true;
    }else{
        par = false;
    }

    int i;
    int metade;
    Celula *p;
    if (!par){
        metade = (int)quantidadeElementos/2;
    }else{
        metade = (int)quantidadeElementos/2 - 1;
    }
    for(i = 0, p = lista; i < metade; i++, p = p->prox);

    if(!par) return p->valorGlicemia;
    
    return (p->valorGlicemia + p->prox->valorGlicemia) / 2;
}

// Menor valor glicêmico
int menorValorGlicemico(Celula *topo){
    return 
}