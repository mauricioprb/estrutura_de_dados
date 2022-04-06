#include <iostream>
#include "source.h"

using namespace std;

int main(){
    Celula *pilha = NULL;
    Celula *lista = NULL;

    popularDoArquivo(&pilha, &lista);

    cout << "Valores originais de glicemia do mais recente ao mais antigo" << endl;
    exibirPilha(pilha);

    cout << "Valores ordenados de glicemia do mais baixo ao mais alto" << endl;
    exibirLista(lista);

    cout << "\nForam carregados: " << contarElementosLista(lista) << " dados glicêmicos." << endl;

    cout << "\nMédia glicêmica é: " << mediaGlicemia(lista) << endl;

    cout << "\nMediana glicêmica é: " << medianaGlicemia(lista) << endl;
}