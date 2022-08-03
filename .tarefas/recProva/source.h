#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Struct utilizado tanto pra pilha quanto pra lista
typedef struct no{
  int dado;
  struct no *prox;
} Celula;

// Mostra os valores ordenados, do menor ao maior
void exibirLista(Celula *lista){
  Celula *p;
  for(p = lista; p; p = p->prox){
    cout << p->dado << endl;
  }
}

Celula *inserirLista(int valor, Celula *lista){
  // Alocar memória

  Celula *novo = (Celula*)malloc(sizeof(Celula));

  if(valor % 2 == 0){
    return lista;
  }

  // Depositar valores
  novo->dado = valor;
  novo->prox = NULL;

  // Percorrer para encontrar o local adequado na lista
  // Testar se é a primeira vez
  if(!lista) return novo;

  Celula *p, *pR;
  for(pR = NULL, p = lista; p; pR = p, p = p->prox){
    if(valor < p->dado) break;
  }

  // É o primeiro
  if(p == lista){
    novo->prox = lista;
    return novo;
  }
  // É o último
  if(!p){
    pR->prox = novo;
  } else { // Está no meio de duas celulas
    pR->prox = novo;
    novo->prox = p;
  }
  // Retorna o início da lista
  return lista;  
}

// Método que receba um valor, o localiza na lista e o remove da estrutura
Celula *excluirLista(int valor, Celula *lista) {
  Celula *p, *pR;

  if(!lista){
    cout << "Lista vazia. Operação cancelada!" << endl;
    return lista;
  }

  for(pR = NULL, p = lista; p; pR = p, p = p->prox){
    if(valor == p->dado){
      // É o primeiro
      if(p == lista){
        lista = lista->prox;
      } else if(!p->prox){ // É o ultimo
        pR->prox = NULL;
      } else{ // Está entre celulas
        pR->prox = p->prox;
      }
      free(p);
      return lista;
    }
  }
  cout << "Valor não localizado para exclusão!" << endl;
  return lista;
}

Celula *excluirOcorrenciasLista(int valor, Celula *lista){
  Celula *p, *pR;
  int contaExcluidos = 0;

  if(!lista){
    cout << "Lista vazia. Operação cancelada!" << endl;
    return lista;
  }

  bool houveExclusao;
  do{
    houveExclusao = false;
    for(pR = NULL, p = lista; p; pR = p, p = p->prox){
      if(valor == p->dado){
        contaExcluidos++; // Toda vez que localiza, prepara para excluir, mas antes conta
        // É o primeiro
        if (p == lista){
          lista = lista->prox;
        } else if (!p->prox){ // É o ultimo
          pR->prox = NULL;
        } else{ // Está entre celulas
          pR->prox = p->prox;
        }
        free(p);
        houveExclusao = true;
        break;
      }
    }   
  } while(houveExclusao);

  cout << "O total de excluídos foi: " << contaExcluidos << endl;
  return lista;
}

// Método que recebe uma lista e retorna a quantidade de elementos
int contarElementos(Celula *lista){
  int contador = 0;
  Celula *p;
  for(p = lista; p ; p = p->prox){
    contador++;
  }
  return contador;
}

Celula *popular(Celula *lista, int n){
  srand(time(NULL));
  
  for(int i = 0; i < n; i++){
    lista = inserirLista(rand() % 100, lista);
  }
  return lista;
}

// Exerícios recuperação

Celula *excluirPares(Celula *lista){
  Celula *p;

  for(p = lista; p;){
      if(p->dado % 2 == 0){
          if(p == lista){
              lista = lista->prox;
              break;
          }
          lista = excluirLista(p->dado, lista);
          p = lista;
      }
      else{
        p = p->prox;
      }
  }
  return lista;
}

float mediaPrimeiroUltimoValor(Celula *lista){
  Celula *p;

  int primeiroValor = lista->dado;
  int ultimoValor = 0;

  if(!lista || !lista->prox) {
    cout << "A lista tem menos de dois valores!" << endl;
  }

  for(p = lista; p->prox; p = p->prox);

  ultimoValor = p->dado;

  float media = ((primeiroValor + ultimoValor) / 2);

  return media;
}

void exibirMetadeLista(Celula *lista) {
  if (!lista) return;

  int i = 0;
  Celula *p;
  int qtdElm = contarElementos(lista);

  if(qtdElm == 1 || qtdElm == 2){
      cout << lista->dado << endl;
  }

  qtdElm = (int)qtdElm / 2;

  for(p = lista; i < qtdElm; i++, p = p->prox){
      cout << p->dado << endl;
  }
}