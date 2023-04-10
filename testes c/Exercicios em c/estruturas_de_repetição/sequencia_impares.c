#include<stdio.h>
#include<stdlib.h>

int main(){
    int x,i=1;
    
    printf("Digite o valor de x e descubra todos os impares de 1 ate x:");
    scanf("%d",&x);

    for(i;i<x;i++){
        if(i%2!=0){
            printf("%d\n",i);
        }

    }

 system("pause");
 return 0;
}