// Construir um programa que receba uma altura e peso de um possivel atleta

// função  recebe altura e peso e devolve esporte

//  se altura < 1.80 e peso < 70
// retornar atletismo

// se altura > 1.80 e peso < 70
// retornar volei ou basquete se não retornar futebol

#include <stdio.h>

int esporte(){
  char atletismo, volei, basquete, futebol;
  float altura, peso;

  printf("Altura: ");
  scanf("%f", &altura);
  printf("Peso: ");
  scanf("%f", &peso);

  if(altura < 1.80 && peso < 70){
    return atletismo;
  }
  if(altura < 1.80 && peso < 70){
    return volei;
    return basquete;
  }
  else{
    return futebol;
  }
}
int main(){
  esporte();
  
  return 0;
}