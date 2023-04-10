#include<stdio.h>
#include<stdlib.h>

int main(){
    float dolar, real;
    int escolha;

    printf("Digite 1 se quiser converter de R$-->$ e 2 para converter de $-->R$:\n");
    scanf("%d",&escolha);
    system("cls");

    if(escolha==2){
        printf("Informe o valor em doalares:\n$");
        scanf("%f",&dolar);
        system("cls");

        real=dolar*5.17;

        printf("$%0.2f equivale a R$%0.2f.\n",dolar,real);
    }

    else{
        printf("Informe o valor em Reais:\nR$");
        scanf("%f",&real);
        system("cls");

        dolar=real/5.17;

        printf("R$%0.2f equivale a $%0.2f.\n",real,dolar);
    }

    printf("Deseja converter outro valor monetario?Digite:\n1-Sim\n2-Nao\n");
    scanf("%d",&escolha);
    system("cls");

    while(escolha==1){
        printf("Digite 1 se quiser converter de R$-->$ e 2 para converter de $-->R$:\n");
        scanf("%d",&escolha);
        system("cls");

        if(escolha==2){
            printf("Informe o valor em doalares:\n$");
            scanf("%f",&dolar);
            system("cls");

            real=dolar*5.17;

            printf("$%0.2f equivale a R$%0.2f.\n",dolar,real);
        }

        else{
            printf("Informe o valor em Reais:\nR$");
            scanf("%f",&real);
            system("cls");

            dolar=real/5.17;

            printf("R$%0.2f equivale a $%0.2f.\n",real,dolar);
        }
        printf("Deseja converter outro valor monetario?Digite:\n1-Sim\n2-Nao\n");
        scanf("%d",&escolha);
        system("cls");
    }
    system("pause");
 return 0;
}