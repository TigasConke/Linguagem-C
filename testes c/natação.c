#include<stdio.h>
#include<stdlib.h>

int main (){
int idade;
printf("Digite sua idade:");
scanf("%i",&idade);
if (idade>=5 & idade<8){
    printf("Sua Categoria e Infantil A\n");
    system("PAUSE");}
        else if(idade>=8 & idade<11){
    printf("Sua categoria e Infantil B\n");
    system("PAUSE");}
        else if(idade>=11 & idade<14){
    printf("Sua categoria e Juvenil A\n");
    system("PAUSE");}
        else if(idade>=14 & idade<18){
    printf("Sua categoria e Juvenil B\n");
    system("PAUSE");}
        else if(idade>=18){
    printf("Sua categoria e Senior\n");
    system("PAUSE");}
        else
        printf("Nao tem idade suficiente para se enquadrar.\n");
        system("PAUSE");

 return 0;
}
