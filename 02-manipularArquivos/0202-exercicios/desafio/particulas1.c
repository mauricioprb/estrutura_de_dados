#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *procurador;
    char nomeArquivo[200]; 
    int x, y; 
    int qtdParticulas;

    // Abrir um arquivo de saída
    printf("Nome de arquivo de saída de partículas: ");
    scanf("%s", nomeArquivo); //gets(nomeArquivo);
    procurador = fopen(nomeArquivo, "w");

    // qtd de particulas x,y
    printf("Quantas partículas quer gerar: ");
    scanf("%d", &qtdParticulas);

    // Arquivo com qtdParticulas x, y
    srand(time(NULL));
    for(; qtdParticulas > 0; qtdParticulas--) {
        x = 100 - rand() % 200;
        y = 100 - rand() % 200;
        fprintf(procurador, "%d, %d\n", x, y);
        fflush(procurador);
    }
    
    fclose(procurador);

    return 1;
}