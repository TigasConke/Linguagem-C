#include<stdio.h>
#include<stdlib.h>

int acheMaior (float A, float B, float C)
{
  float maior;

  maior = A;

  if (B > maior)
    {
      maior = B;
    }

  if (C > maior)
    {
      maior = C;
    }

  printf("%0.2f",maior);
  return maior;

}

int main(){
acheMaior(3,4,5);


}