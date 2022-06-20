#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
    int fb; // Fator de balanceamento
} Arvore;

typedef struct noString {
    string valor;
    struct noString *esq;
    struct noString *dir;
    int fb; // Fator de balanceamento
} ArvoreString;

int calcularAltura(Arvore *raiz) {
    if(raiz) {
        int altEsq = calcularAltura(raiz->esq); // Avançou completamente para a esquerda da árvore
        int altDir = calcularAltura(raiz->dir); // Avançou completamente para a direita da árvore
        
        // Testou a altura maior e retornou ela + 1
        if(altEsq > altDir) {
            return altEsq + 1;
        } else {
            return altDir + 1;
        }
    } else {
        return 0;
    }
}

int calcularAlturaString(ArvoreString *raiz) {
    if(raiz) {
        int altEsq = calcularAlturaString(raiz->esq); // Avançou completamente para a esquerda da árvore
        int altDir = calcularAlturaString(raiz->dir); // Avançou completamente para a direita da árvore
        
        // Testou a altura maior e retornou ela + 1
        if(altEsq > altDir) {
            return altEsq + 1;
        } else {
            return altDir + 1;
        }
    } else {
        return 0;
    }
}

Arvore *rodaEsquerda(Arvore *r) {
    Arvore *filho, *pai, *tmp;
    pai = r;
    filho = pai->dir;
    tmp = filho->esq;
    r = filho;
    filho->esq = pai;
    pai->dir = tmp;
    return r;
}

Arvore *rodaDireita(Arvore *r) {
    Arvore *filho, *pai, *tmp;
    pai = r;
    filho = pai->esq;
    tmp = filho->dir;
    r = filho;
    filho->dir = pai;
    pai->esq = tmp;
    return r;
}

void atualizarFB(Arvore *raiz) {
    if(raiz) {
        atualizarFB(raiz->esq);
        atualizarFB(raiz->dir);
        raiz->fb = calcularAltura(raiz->esq) - calcularAltura(raiz->dir);
    }
}

Arvore *inserir(int valor, Arvore *raiz) {
    if(raiz) {
        if(valor == raiz->valor) return raiz; // Controle de duplicados

        if (valor < raiz->valor) { // Avançar ou empilhar para a esquerda
            raiz->esq = inserir(valor, raiz->esq);
        } else { // Avançar ou empilhar para a direita
            raiz->dir = inserir(valor, raiz->dir);
        }

        raiz->fb = calcularAltura(raiz->esq) - calcularAltura(raiz->dir);

        // Descobrir se esta ou nao balanceado
        if(raiz->fb == -2) { // Rotacao para esquerda
            // Descobrir se eh rotacao simples
            if (raiz->fb < 0 && raiz->dir->fb < 0) {
                raiz = rodaEsquerda(raiz);
            } else {
                // Rotacao dupla
                // 1 - rodar o filho para direita
                raiz->dir = rodaDireita(raiz->dir);
                // 2 - rodar o pai para a esquerda
                raiz = rodaEsquerda(raiz);
            }
            // Atualizar o fb dos nodos da raiz
            atualizarFB(raiz);
        } else if(raiz->fb == 2) { // Rotacao para direita
            // Descobrir se eh rotacao simples
            if (raiz->fb > 0 && raiz->esq->fb > 0) {
                raiz = rodaDireita(raiz);
            } else {
                // Rotacao dupla
                // 1 - rodar o filho para esquerda
                raiz->esq = rodaEsquerda(raiz->esq);
                // 2 - rodar o pai para a direita
                raiz = rodaDireita(raiz);
            }
            // Atualizar o fb dos nodos da raiz
            atualizarFB(raiz);
        }

        return raiz;

    } else {
        // Se estamos aqui, pq chegamos em um folha e estamos prontos para adicionar o nodo na árvore
        Arvore *novo = (Arvore*)malloc(sizeof(Arvore));
        novo->esq = NULL;
        novo->dir = NULL;
        novo->valor = valor;    
        novo->fb = 0; // Todo nodo inserido, o fb é 0    
        return novo;
    }
}

void exibir(Arvore *raiz, int nivel) {
    if(raiz) {
        exibir(raiz->dir, nivel + 1); // Empilhando tudo para direita, busca-se exibir os maiores primeiro
        
        for(int i = 0; i < nivel; i++) {
            cout << "   ";
        }
        cout << "(" << nivel << ")" << raiz->valor << "->" << raiz->fb << endl; 

        exibir(raiz->esq, nivel + 1); // Empilhando tudo para esquerda, busca-se exibir os menores
    }
}

int localizarNivel(int valor, Arvore *raiz) {
    if(raiz) {
        if(valor == raiz->valor) return 0;
        if(valor < raiz->valor) {
            // Ir para esquerda
            int resposta = localizarNivel(valor, raiz->esq);
            if(resposta == -1) return -1; // Se a volta do empilhamento vem -1, continuamos enviando -1
            return resposta + 1;
        } else {
            // Ir para direita
            int resposta = localizarNivel(valor, raiz->dir);
            if(resposta == -1) return -1; // Se a volta do empilhamento vem -1, continuamos enviando -1
            return resposta + 1;
        }
    } else {
        return -1; // Chegou nas folhas e o valor nao foi localizado
    }
}

Arvore *popularDoArquivo(Arvore *raiz) {
    ifstream procurador;
    char nomeArquivo[200];

    cout << "Informe caminho e nome do arquivo fonte com numeros: ";
    cin >> nomeArquivo;

    procurador.open(nomeArquivo);

    if(!procurador){
        cout << "Arquivo nao localizado!\n";
        return NULL;
    }

    string linha;
    int valor;

    while(getline(procurador, linha)){
        stringstream pegaInteiro(linha);
        pegaInteiro >> valor;
        raiz = inserir(valor, raiz);
    }

    procurador.close();
    return raiz;
}