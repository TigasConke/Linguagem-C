#include<stdio.h>
#include<stdlib.h>

void tabuada(int Num);

int main(){
    int numero;

    printf("Digite a tabuada que deseja ver:");
    scanf("%d",&numero);
    
    tabuada(numero);

 return 0;
}

void tabuada(int Num){
    int num2=0,resultado;

    while(num2<=10){
        resultado=Num*num2;
        printf("%d x %d = %d\n",Num,num2,resultado);
        num2++;
    }
}