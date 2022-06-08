#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct no {
    int dado;
    struct no *prox;
} Celula;

Celula *inserirR(int valor, Celula *lista) {
    if(lista && valor > lista->dado) {
        // Avançar até o final ou até a posição correta
        lista->prox = inserirR(valor, lista->prox);
        return lista;
    } else {
        Celula *novo = (Celula*)malloc(sizeof(Celula));
        novo->dado = valor;
        novo->prox = lista; // Atenção neste ponto
        return novo;
    }
}

void exibirR(Celula *lista) {
    if(lista) {
        // Exibir
        cout << lista->dado << endl;
        exibirR(lista->prox);
    }
}

int contarNosR(Celula *lista) {
	if(lista) {
		return 1 + contarNosR(lista->prox);
	}
	return 0; // Passei por toda lista
	
}

int somaR(Celula *lista) {
	if(lista) {
		return lista->dado + somaR(lista->prox);
	}
	return 0; // Passei por toda lista
}

int contarParesR(Celula *lista) {
	if(lista) {
		if(lista->dado % 2 == 0) {
			return 1 + contarParesR(lista->prox); // Empilho contando 1 par
		}
		return 0 + contarParesR(lista->prox);// Empilho contando 0
	}
	return 0; // Passei por toda lista
}

int somarParesR(Celula *lista) {
	if(lista) {
		if(lista->dado % 2 == 0) {
			return lista->dado + somarParesR(lista->prox);
		}
		return 0 + somarParesR(lista->prox);
	}
	return 0; // Passei por toda lista
}

int main() {
    Celula *lista = NULL;

    lista = inserirR(45, lista);
    lista = inserirR(5, lista);
    lista = inserirR(4, lista);
    lista = inserirR(12, lista);
	lista = inserirR(12, lista);
    exibirR(lista);

	cout << "Numero de nós: " << contarNosR(lista) << endl;
	cout << "Soma dos elementos: " << somaR(lista) << endl;
	cout << "Numero de pares: " << contarParesR(lista) << endl;
	cout <<"Somar pares: " << somarParesR(lista) << endl;
	
    return 1;
}