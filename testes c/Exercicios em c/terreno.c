#include<stdio.h>
#include<stdlib.h>

int main(){
    float larg,comp,valor,a,p;
    printf("Digite a largura do terreno:\n");
    scanf("%f",&larg);
    printf("Digite o comprimento do terreno:\n");
    scanf("%f",&comp);
    printf("Digite o valor do metro quadrado do terreno:\n");
    scanf("%f",&valor);
    a=larg*comp;
    p=a*valor;
    printf("A area do terreno e %2.f metros quadrados.\n",a);
    printf("O valor do terreno e %2.f\n reais.",p);
  return 0;   
}