#include<stdio.h>
#include<stdlib.h>

float multiplica(float a,float b);
int main(){
    float num1, num2;
    printf("Digite o primeiro numero:\n");
    scanf("%f",&num1);

    printf("\nDigite o segundo numero:\n");
    scanf("%f",&num2);    
    multiplica(num1,num2);


 return 0;
}

float multiplica(float a, float b){
    float operacao;

    operacao=a*b;

    printf("%f x %f = %f",a,b,operacao);

}