#include<stdio.h>
#include<stdlib.h>

int main (){
float peso,altura,IMC;
printf("Insira seu peso:");
scanf("%f",&peso);
printf("Insira sua altura:");
scanf("%f",&altura);
IMC=peso/pow(altura,2);
if(IMC<20)
    printf("Voce esta abaixo do peso, temo que dar uma engordadinha meu chapa!\n");
        else if(IMC<25){
    printf("Parabens voce esta com o peso normal!\n");
    system("PAUSE");}
        else if(IMC<30){
    printf("Voce esta sobre peso, temo que melhorar isso!\n");
    system("PAUSE");}
        else if(IMC<=40){
    printf("Parabens voce esta obeso, nao pera.\n");
    system("PAUSE");}
        else
        printf("Voce esta obeso morbido, vamo queima essa banha meu cumpadi!!\n");
        system("PAUSE");    

 return 0;   
}
