#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void plural();

void plural(){
    printf("s");
}

int main(){
    char palavra[10];
    printf("Digite uma palavra no singular:\n");
    scanf("%s",&palavra);

    printf("%s",palavra);
    plural();
 return 0;
}