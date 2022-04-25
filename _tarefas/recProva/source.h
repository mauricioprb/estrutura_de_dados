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

Celula *inserirListaControleDuplicados(int valor, Celula *lista){
  // Alocar memoria
  Celula *novo = (Celula*)malloc(sizeof(Celula));

  // Depositar valores
  novo->dado = valor;
  novo->prox = NULL;

  // Percorrer para encontrar o local adequado na lista
  // Testar se é a primeira vez
  if(!lista) return novo;

  Celula *p, *pR;
  for(pR = NULL, p = lista; p; pR = p, p = p->prox){
    if(valor < p->dado) break;

    if(valor == p->dado) return lista; // Valor já cadastrado, logo retorna a lista sem alteração
  }

  // É o primeiro
  if(p == lista){
    novo->prox = lista;
    return novo;
  }
  // É o último
  if (!p){
    pR->prox = novo;
  } else{ // Está no meio de duas celulas
    pR->prox = novo;
    novo->prox = p;
  }
  // Retorna o inicio da lista
  return lista;  
}

Celula *inserirListaSemControleDuplicados(int valor, Celula *lista){
  // Alocar memória
  Celula *novo = (Celula*)malloc(sizeof(Celula));

  //depositar valores
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

Celula *excluirOcorrenciasLista(int valor, Celula *lista) {
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

  cout << "O total de excluidos foi: " << contaExcluidos << endl;
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

void verificarPresenca(Celula *lista1, Celula* lista2){
  if(!lista1 || !lista2){
    cout << "Operação não realizada, pois ambas não existem ou uma delas também não existe!" << endl;
    return ;
  }

  Celula *p1, *p2;

  for(p1 = lista1; p1; p1 = p1->prox){
    for(p2 = lista2; p2; p2 = p2->prox){
      if(p1->dado == p2->dado){
        cout << "Este dado ocorre nas 2 listas: " << p1->dado << endl;
      }
    }
  }  
}

Celula *unirListas(Celula *lista1, Celula *lista2){
  if(!lista1 || !lista2){
    cout << "Operação não realizada, pois ambas não existem ou uma delas também não existe!" << endl;
    return NULL;
  }

  Celula *p;
  
  for(p = lista1; p->prox; p = p->prox);

  p->prox = lista2;

  return lista1;
}