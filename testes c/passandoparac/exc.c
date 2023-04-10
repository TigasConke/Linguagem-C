#include<stdio.h>
#include<stdlib.h>

int main(){
 int A,B,C=1,X;
 printf("Digite dois numeros:");
 scanf("%d %d",&A,&B);
 

 while(C<=A && C<=B){
    if(A%C==0 && B%C==0){
        X=C;
    }
    C=C+1;
 }
 printf("%d\n",X);
 
 system("pause");
 
 return 0;
}