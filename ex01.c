#include <stdio.h>
#define TAM 5

typedef struct{
    float altura, peso, imc;
}imc;

int main(){
    int i;
    int posicaoMaior = 0;
    
    imc dados[4];
    
    for(i = 0; i<4; i++){
        printf("Peso: ");
        scanf("%f", &dados[i].peso);
        printf("Altura: ");
        scanf("%f", &dados[i].altura);
        
        dados[i].imc = dados[i].peso/(dados[i].altura*dados[i].altura);
        
        printf("IMC: %.2f\n", dados[i].imc);
        
        if(dados[i].imc > dados[posicaoMaior].imc){
            posicaoMaior = i;
        }
    }
    printf("Maior IMC: %.2f\n", dados[posicaoMaior].imc);
    
    return 0;
}