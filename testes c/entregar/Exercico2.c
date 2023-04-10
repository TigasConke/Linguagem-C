#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
  int R$;
  printf("Digite um valor(R$) para fatora-lo em notas de 100, 50, 10, 5 e 1:");
  scanf("%d",&R$);

  int cem,cinq,dez,cinco,um;
  int mod;
  cem=R$/100;
  mod=R$%100;

  cinq=mod/50;
  mod=mod%50;

  dez=mod/10;
  mod=mod%10;

  cinco=mod/5;
  mod=mod%5;

  um=mod/1;

  printf("%d notas de 100, %d notas de 50, %d notas de 10, %d notas de 5 e %d notas de 1 real.\n",cem,cinq,dez,cinco,um);
  system("pause");


  return 0;
}