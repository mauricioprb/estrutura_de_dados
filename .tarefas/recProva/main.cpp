#include <iostream>
#include <ctime>
#include "source.h"

using namespace std;

int main(){
  Celula *lista = NULL;

  lista = popular(lista, 20);

  cout << "Lista:" << endl;
  exibirLista(lista);

  cout << "\nMédia do primeiro com o último valor da lista: " << mediaPrimeiroUltimoValor(lista) << endl;

  int numero;
  cout << "\nQual o número que você deseja apagar da lista? ";
  cin >> numero;
  
  lista = excluirOcorrenciasLista(numero, lista);
  
  cout << "\nLista após exclusão:" << endl;
  exibirLista(lista);

  cout << "\nLista pela metade:" << endl;
  exibirMetadeLista(lista);

  return 1;
}