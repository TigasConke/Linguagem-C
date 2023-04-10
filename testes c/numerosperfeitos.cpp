#include<stdio.h>
#include<stdlib.h>
int main(){
 int N,soma,i;
 printf("Digite um numero ai cumpadi:");
 scanf("%d",&N);
 if(N<=0)
 printf("Numero invalido");
 else{
 	i=N-1;
 	while(i>0){
 	 if(N%i==0)
 	 soma+=i;
 	 i--;
 	 }
	 
 }	
	if(soma==N)
	printf("Esse numero e perfeito.");
	else
	printf("Esse numero nao e perfeito.");
	
	return 0;
}
