#include <iostream>
#include "source.h"

using namespace std;

int main(){
    Celula *lista = NULL;
    int qtdNumerosLista = 10; 

    lista = popular(lista, qtdNumerosLista);
    cout << "Lista inicial:" << endl;
    exibirLista(lista);

    int numero;
    cout << "Qual número eseja apagar da lista? ";
    cin >> numero;

    lista = excluirOcorrencia(numero, lista);
    cout << "\nLista após a exclusão:" << endl;
    exibirLista(lista);

    lista = excluirPrimeiroUltimo(lista);

    cout << "\nLista após a poda:" << endl;
    exibirLista(lista);

    return 1;
}