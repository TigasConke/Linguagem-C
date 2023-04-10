#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int main(){
 float base, altura, area, p, d;
   printf("Digite a altura do retangulo:");
   scanf("%f",&altura);
   printf("Digite a base do retangulo:");
   scanf("%f",&base);

    area= base * altura;
    p= base+ base + altura + altura;
    d= sqrt((altura* altura) + (base * base));

    printf("A area do retangulo e:%f\n",area);
    printf("O perimetro do retangulo e:%f\n",p);
    printf("A diagonal do retangulo e:%f\n",d);


    return 0;
}