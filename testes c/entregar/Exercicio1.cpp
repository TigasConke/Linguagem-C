#include<stdio.h>
#include<stdlib.h>

int main(){
 int N;
 float X=1,S=1;
  printf("Digite um numero N e saiba o resultado de S = 1/1 + 1/2 + 1/3 + 1/4 + .... + 1/N :");
  scanf("%d",&N);
  while(X<N){
   X=X+1;
   S=S+1/X;
  }
    printf("S e igual a: %.2f\n",S);
    system("pause");
  return 0;
}