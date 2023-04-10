#include<stdio.h>
#include<stdlib.h>

int main(){
    int A, B, C , N , cont;
    printf("Digite quantos numeros da seqeuncia de Fibonacci voce quer seber:");
    scanf("%d",&N);
    A=1;
    B=1;
    cont=2;
    printf("1 1 ");
    while(cont<N){
        C= A + B;
        cont= cont + 1;
        A=B;
        B=C;
        printf(" %d ",C);

    }

    return 0;
}