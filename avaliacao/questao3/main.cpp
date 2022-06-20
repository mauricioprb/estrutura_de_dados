#include <iostream>
#include <cstdlib>
#include "source.h"

using namespace std;

int main() {
    Arvore *raiz = NULL;

    raiz = inserir(15, raiz);
    raiz = inserir(100, raiz);
    raiz = inserir(15, raiz);
    raiz = inserir(50, raiz);
    raiz = inserir(15, raiz);
    raiz = inserir(100, raiz);

    exibir(raiz, 0);

    cout << "A altura desta arvore eh: " << calcularAltura(raiz) << endl;

    cout << verificarFolha(raiz, 10);

    return 1;
}