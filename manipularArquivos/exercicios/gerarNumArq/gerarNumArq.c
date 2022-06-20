#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *procurador;
    char nomeArquivo[200]; int qtdNumeros;

    printf("Qual o nome do arquivo de saída contendo números? ");
    scanf("%s", nomeArquivo);

    // Verificar se o arquivo já existe. Se sim, encerre o programa, se não, fecha e abre o modo escrita "w"
    procurador = fopen(nomeArquivo, "r");
    if(procurador) {
        printf("Arquivo já existe, programa será finalizado\n");
        fclose(procurador);
        exit(0);
    }
    
    procurador = fopen(nomeArquivo, "w");

    printf("Quantos números quer gerar o arquivo? ");
    scanf("%d", &qtdNumeros);

    int valor;
    srand(time(NULL));
    for(; qtdNumeros > 0; qtdNumeros--) {
        valor = rand() %1000;
        fprintf(procurador, "%d\n", valor);
        fflush(procurador);
    }

    fclose(procurador);

    return 1;
}