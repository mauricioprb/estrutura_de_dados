#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *procurador, *procuradorSaida;
    char nomeArquivo[200]; int x, y; int qtdParticulas = 0; int conta1q = 0, conta2q = 0, conta3q = 0 , conta4q = 0, contaOrigem = 0;

    // Abrir um arquivo de entrada
    printf("Nome de arquivo de entrada de partículas: ");
    scanf("%s", nomeArquivo); //gets(nomeArquivo);
    procurador = fopen(nomeArquivo, "r");

    if(!procurador) {
        printf("Arquivo com partículas não localizado\n");
    }

    // Percorrer o arquivo/procurador extraindo de cada linha x e y
    do {
        fscanf(procurador, "%d, %d", &x, &y);

        if(x > 0 && y > 0){
            conta1q++;
        } else if(x < 0 && y > 0){
            conta2q++;
        } else if(x < 0 && y < 0){
            conta3q++;
        } else if(x > 0 && y < 0){
            conta4q++;
        } else {
            contaOrigem++;
        }

    } while(!feof(procurador));

    procuradorSaida = fopen("relatorio.txt", "w");
    fprintf(procuradorSaida, "Foram analisadas %d partículas\n", qtdParticulas);
    fprintf(procuradorSaida, "1° Quadrante: %d\n", conta1q);
    fprintf(procuradorSaida, "2° Quadrante: %d\n", conta2q);
    fprintf(procuradorSaida, "3° Quadrante: %d\n", conta3q);
    fprintf(procuradorSaida, "4° Quadrante: %d\n", conta4q);
    fprintf(procuradorSaida, "Origem: %d\n", contaOrigem);


    fclose(procuradorSaida);
    fclose(procurador);

    return 1;
}