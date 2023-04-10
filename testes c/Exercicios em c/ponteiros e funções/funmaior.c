#include<stdio.h>
#include<stdlib.h>

float maior(float A, float B, float C);

int main(){
    float a, b, c;

    printf("Digite o primeiro numero para descubrir o maior:");
    scanf("%f",&a);

    printf("Digite o segundo numero para descubrir o maior:");
    scanf("%f",&b);

    printf("Digite o terceiro numero para descubrir o maior:");
    scanf("%f",&c);

    maior(a, b, c);

    printf("O numero maior e: %0.2f",maior(a, b, c));

 return 0;
}

float maior(float A, float B, float C){
    if(A>=B && A>=C){
        return A;
    }
    else{
        if(B>=A && B>=C){
            return B;
        }
        else{
            return C;
        }
    }

}