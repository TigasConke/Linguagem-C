#include<stdio.h>
#include<stdlib.h>

int main(){
  int R$,cem=0,cinq=0,dez=0,cinco=0,um=0;
  printf("Digite um valor(R$) para fatora-lo em notas de 100, 50, 10, 5 e 1 real:");
  scanf("%d",&R$);
  
  while(R$>=100){
    R$=R$-100;
    cem=cem+1;
     }

  while(R$>=50){
   R$=R$-50;
   cinq=cinq+1;
     }

   while(R$>=10){
    R$=R$-10;
    dez=dez+1;
     }

   while(R$>=5){
    R$=R$-5;
    cinco=cinco+1;
     }

   while(R$>=1){
    R$=R$-1;
    um=um+1;
     }

  printf("%d notas de 100, %d notas de 50, %d notas de 10, %d notas de 5 e %d notas de 1 real\n",cem,cinq,dez,cinco,um);
  system("pause");

 return 0;
}