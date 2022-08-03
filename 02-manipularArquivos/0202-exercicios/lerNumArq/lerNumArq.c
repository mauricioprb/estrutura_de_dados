#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *procurador;
    char nomeArquivo[200], linha[200];

    printf("Nome arquivo: ");
    scanf("%s", nomeArquivo);

    procurador = fopen(nomeArquivo, "r");

    if(!procurador) {
        printf("Arquivo não encontrado\n");
        exit(0);
    }

    do {
        fscanf(procurador, "%s", linha);
        printf("%s\n", linha);
    } while(!feof(procurador));

    fclose(procurador);

    return 1;
}