#include<stdio.h>
#include<stdlib.h>

int main (){
 
  int num1 = 0, num2 = 0, soma = 0, i = 1,nu = 0;
 
  printf("Digite o primeiro numero: ");
  scanf("%d", &num1);
 
  printf("Digite o segundo numero: ");
  scanf("%d", &num2);

  while(i<num2)
  {
    if(soma=0){
        soma = num1 + num1;
        }
    else{
    soma = soma + num1;
    }
    i++;
  }

    printf("%d x %d = %d", num1, num2, soma);
  system("pause");
 return 0;
}