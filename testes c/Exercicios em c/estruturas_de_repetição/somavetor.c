#include<stdio.h>
#include<stdlib.h>

int main(){
    int x,i=0;
    float notas[x], soma, media;
    
    printf("Quantas notas voce ira digitar\n");
    scanf("%d",&x);

    for(i=0; i < x; i++){
        printf("digite uma nota:\n");
        scanf("%f",&notas[i]);
    }

    for(i=0; i < x; i++){
        if(i==0){
            soma = notas[i];
        }
        else{
            soma= soma + notas[i];
        }
        
    }

    media = soma/x;
    printf("Soma = %0.2f\n", soma);
    printf("Media = %0.2f\n", media);
 

 system("pause");
 return 0;
}