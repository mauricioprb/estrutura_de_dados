#include <iostream>
#include <cstdlib>
#include <time.h>

#define TAM 5

using namespace std;

void popularR(int *vetor, int n) {
    if(n > 0) {
        // Código ao empilhar
        vetor[n - 1] = rand() % 20;
        // Ponto de recursão
        popularR(vetor, n - 1);
        // Código ao desempilhar
    }
}

void exibirCrescenteR(int *vetor, int n) {
    if(n > 0) {
        // Código ao empilhar

        // Ponto de recursão
        exibirCrescenteR(vetor, n - 1);
        // Código ao desempilhar
        cout << vetor[n - 1] << endl;
    }
}

void exibirDecrescenteR(int *vetor, int n) {
    if(n > 0) {
        // Código ao empilhar
        cout << vetor[n - 1] << endl;
        // Ponto de recursão
        exibirDecrescenteR(vetor, n - 1);
        // Código ao desempilhar
    }

}

int somarR(int *vetor, int n) {
    if(n > 0) {
        return vetor[n - 1] + somarR(vetor, n - 1);
    }
    return 0;
}

int maiorR(int *vetor, int n) {
    if(n > 0) {
        int vemDeCima = maiorR(vetor, n - 1);
        if(vemDeCima > vetor[n - 1]) return vemDeCima;
        return vetor[n];
    }
    return vetor[n];
}

int main() {
    int quantidade = TAM;
    int vetor[TAM];
    srand(time(NULL));
    popularR(vetor, TAM); // Void
    exibirCrescenteR(vetor, TAM); // Void
    exibirDecrescenteR(vetor, TAM);  // Void

    // return
    cout << "A soma dos elementos do vetor eh: " << somarR(vetor, TAM) << endl;
    cout << "O maior valor do vetor eh: " << maiorR(vetor, TAM) << endl;

    return 1;
}