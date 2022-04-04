#include <iostream>
#include "estruturas.h"

using namespace std;

int main(){
    Celula *pilha = NULL;
    Celula *lista = NULL;

    popularDoArquivo(&pilha, &lista);

    cout << "\nValores originais de glicemia:\n";
    exibirPilha(pilha);

    cout << "\nValores ordenados da glicemia:\n";
    exibirLista(lista);

    cout << "\nQuantidade elementos da lista: " << contarElementosLista(lista) << endl;

    cout << "\nMédia aritimética: " << calcularMedia(lista) << endl;
}