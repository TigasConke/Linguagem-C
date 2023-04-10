#include<stdio.h>
#include<stdlib.h>

int main(){
    int escolhap,escolhas,escolhab,calorias=0;
    system("cls");
        printf("Pratos \n1-Vegetariano \n2-Peixe \n3-Frango \n4-Carne \nEscolha um prato:");
            scanf("%i",&escolhap);
            system("cls");
        printf("Sobremesas \n1-Abacaxi \n2-Sorvete diet \n3-Mouse diet \n4-Mouse de chocolate \nEscolha uma sobremesa:");
            scanf("%i",&escolhas);
            system("cls");
        printf("Bebidas \n1-Cha \n2-Suco de Laranja \n3-Suco de melao \n4-Refrigerante diet \nEscolha uma bebida: ");
            scanf("%i",&escolhab);
            system("cls");


    switch(escolhap){
        case 1:
         calorias += 180;
        break;
        case 2:
         calorias += 230;
        break;
        case 3:
         calorias += 250;
        break;
        case 4:
         calorias += 350;
        break;
        default :
         printf("Prato invalido!\n");
    }


    switch(escolhas){
        case 1:
         calorias += 75;
        break;
        case 2:
         calorias += 110;
        break;
        case 3:
         calorias += 170;
        break;
        case 4:
         calorias += 200;
        break;
        default :
         printf("Sobremesa invalida!\n");
    }


    switch(escolhab){
        case 1:
         calorias += 20;
        break;
        case 2:
         calorias += 70;
        break;
        case 3:
         calorias += 100;
        break;
        case 4:
         calorias += 65;
        break;
        default :
         printf("Bebida invalida!\n");
    }


    printf("O total de calorias da sua refeicao sao: %i cal\n",calorias);
     system("pause");
return 0;
}