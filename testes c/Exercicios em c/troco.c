#include<stdio.h>
#include<stdlib.h>

int main(){
    float preco,recebido,troco,total,total2;
    int qtd,repetir=1;
    while(repetir==1){
        printf("Informe o valor unitario do produto:\n");
        printf("R$");
        scanf("%f",&preco);
        system("cls");

        printf("Informe a quantidade de produtos a serem comprados:\n");
        scanf("%d",&qtd);
        system("cls");

        total=total+preco*qtd;
        total2=total;

        printf("Deseja acrescentar mais algum produto? Digite 1(sim) ou 2(nao).\n");
        scanf("%d",&repetir);
        system("cls");

    }

    printf("Informe o valor em reais recebido:\n");
    printf("R$");
    scanf("%f",&recebido);
    system("cls");


    if(total>recebido){
        total=total-recebido;
        printf("Valor total: R$%0.2f\nO valor em reais recebido e insuficiente para pagar pela compra, favor pagar o valor de R$%0.2f que esta faltando.\n",total2,total);
    }

    else{
      troco=recebido-total;
       printf("Valor total: R$%0.2f\n Troco: R$%0.2f\n",total,troco);
    }

    system("pause");
   return 0; 
}