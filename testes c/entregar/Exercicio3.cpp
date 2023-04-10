#include<stdio.h>
#include<stdlib.h>

int main(){
  float S,N; 
    printf("Digite um numero e saiba o resultado de S = 1/N + 2/(N-1) + 3/(N-2) + 4/(N-3) + ... + (N-1)/2 + N/1:");
    scanf("%f",&N);
    
    for(int i = 1; N>0; i++){
        S= S + i/N;
        N--;
    }

    printf("S e igual a: %.2f\n",S);
 
  system("pause");
  return 0;    
}