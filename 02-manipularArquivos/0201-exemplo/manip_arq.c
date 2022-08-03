#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *procuradorArquivo;
    char nomeArquivo[200];

    system("clear");

    printf("digite o nome do arquivo para abrir:");
    scanf("%s",nomeArquivo);

    procuradorArquivo=fopen(nomeArquivo, "r");

    if(procuradorArquivo == NULL) {
        printf("arquivo nao localizado");
    } else {
        printf("arquivo localizado");
        fclose(procuradorArquivo);
    }

    return 1;
}