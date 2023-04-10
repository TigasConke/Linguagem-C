#include<stdio.h>
#include<stdlib.h>

int main(){
    int senha,i=1;
    char usuario[10];

    while(i!=2002){
        printf("Usuario:");
        scanf("%s",&usuario);
        system("cls");

        printf("Senha:");
        scanf("%d",&senha);
        system("cls");

        if(senha==2002){
            printf("Acesso permitido!\nSeja muito bem-vindo, %s!\n",usuario);
            i=2002;
        }

        else{
            printf("Combinacao usuario-senha incorreta! Digite novamente.\n");
        } 
    }


 system("pause");
 return 0;
}