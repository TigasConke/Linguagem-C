#include<stdio.h>
#include<stdlib.h>

int main(){
    float idade,media=0,qtd=0;
    int i=1;

    while(i==1){
        printf("Insira uma idade:");
        scanf("%f",&idade);
        system("cls");

        if(idade>0){
            qtd=qtd+1;
            media=media+idade;
        }

        printf("Deseja adicionar mais alguma idade?-1(sim) 2(nao)\n");
        scanf("%d",&i);
        system("cls");
    }

    if(media>0){
        media=media/qtd;
        printf("Media de idades:%0.2f.\n",media);
    }
    else{
        printf("Impossivel calcular.\n");
    }


 system("pause");
 return 0;
}