#include<stdio.h>
#include<stdlib.h>

int main(){
    int N,i;

    printf("Quantos numeros voce quer digitar?");
    scanf("%d",&N);

    int vet[N];

    for(i=0;i<N;i++){
        printf("Digite um numero:");
        scanf("%d",&vet[i]);
    }

     printf("Os numeros informados por voce sao:\n");

    for(i=0;i<N;i++){
        printf("%d\n",vet[i]);   
    }

 return 0;
}

