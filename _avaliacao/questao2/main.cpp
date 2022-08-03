#include <iostream>
#include <cstdlib>
#include "source.h"

using namespace std;

int main() {
    Arvore *raiz = NULL;

    raiz = popularDoArquivo(raiz);
    
    exibir(raiz, 0);

    cout << "A altura desta arvore eh: " << calcularAltura(raiz) << endl;

    cout << nivelMaiorMenor(raiz) << endl;

    return 1;
}