#include<stdio.h>
#include<stdlib.h>

int main(){
    float tent1,tent2,tent3;

    printf("Insira a primeira distancia obtida pelo(a) atleta em metros:\n");
    scanf("%f",&tent1);
    system("cls");

    printf("Insira a segunda distancia obtida pelo(a) atleta em em metros:\n");
    scanf("%f",&tent2);
    system("cls");

    printf("Insira a terceira distancia obtida pelo(a) atleta em metros:\n");
    scanf("%f",&tent3);
    system("cls");

    if(tent1>tent2 && tent1>tent3){
        printf("A maior distancia foi %0.2fm.\n",tent1);
    }
    else{
        if(tent2>tent1&& tent2>tent3){
            printf("A maior distancia foi %0.2fm.\n",tent2);
        }
        else{
            printf("A maior distancia foi %0.2fm.\n",tent3);
        }
    }






















 return 0;
}