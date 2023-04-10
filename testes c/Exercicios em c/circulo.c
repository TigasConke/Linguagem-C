#include<stdio.h>
#include<stdlib.h>

int main(){
    float r,area;
    printf("Digite o raio da circunferencia para descobrir a area:\n");
    scanf("%f",&r);

    area=3.14159*(r*r);

    printf("A area da circunferencia e: %0.3f",area);

   return 0;
}