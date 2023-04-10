#include<stdio.h>
#include<stdlib.h>

main(){
  float A,B,C;
    printf("Digite tres valores e descubra se e um triangulo e o tipo:");
        scanf("%f %f %f",&A,&B,&C);
        system("cls");
  if(A+B>C & A+C>B & B+C>A){
        printf("Triangulo ");
        if(A==B & C==B)
            printf("equilatero\n");
                else if(A==B || A==C || B==C)
                    printf("isoceles\n");
                else if(A!=B & A!=C & C!=B) 
                    printf("escaleno\n");
                    system("PAUSE");}
 else{
    printf("Nao e um triagulo.\n");
    system("PAUSE");}
}