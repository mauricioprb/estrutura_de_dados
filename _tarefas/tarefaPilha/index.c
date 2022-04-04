/*
Fazer um programa em C ou C++ que leia um arquivo com N n° inteiros (um abaixo do outro)
e os popule em uma uma pilha encadeada dinamicamente. Ao final, exiba
quantos elementos há na pilha e seu topo (último valor).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *prox;
} Celula;

Celula *inserir(int valor, Celula *topo){
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    novo->dado = valor;
    novo->prox = topo;
    return novo;
}

int contarNos(Celula *topo){
    int qtd = 0;
    Celula *p;
    for (p = topo; p; p = p->prox){
        qtd++;
    }
    return qtd;
}

int main(){
	Celula *pilha = NULL; 
    Celula *pilhaImpar = NULL;
	FILE *procurador;
	char nomeArquivo[200];
    int valor;

	printf("Nome do arquivo: ");
	scanf("%s", nomeArquivo);

	procurador = fopen(nomeArquivo, "r");

	if (!procurador){
		printf("Arquivo não encontrado\n");
		exit(0);
	}

	while(feof(procurador) == 0){ // 0 = false
		fscanf(procurador, "%d", &valor);
		pilha = inserir(valor, pilha);
	} 

	fclose(procurador);

	printf("\nEndereço do último elemento: %p\n", pilha);
    printf("Valor do último elemento: %d\n", pilha->dado);
    printf("O tamanho da pilha um é: %d\n", contarNos(pilha));

	return 1;
}