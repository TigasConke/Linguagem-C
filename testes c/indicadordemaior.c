#include<stdio.h>
#include<stdlib.h>

int main(){
 float A,B,C;
    printf("Digite 3 numeros e descubra qual e o maior:");
        scanf("%f %f %f",&A,&B,&C);
  if(A>B & A>C){
    printf("O maior e:%.2f\n",A);
    system("PAUSE");}
  else if(B>C){
    printf("O maior e:%.2f\n",B);
    system("PAUSE");}
  else
    printf("maior e:%.2f\n",C);
    system("PAUSE");

return 0; 
}