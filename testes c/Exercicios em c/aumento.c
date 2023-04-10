#include<stdio.h>
#include<stdlib.h>

int main(){
    float salario,aumento;

    printf("Informe o salario do empregado:\nR$");
    scanf("%f",&salario);
    system("cls");

    if(salario<=1000){
        aumento=salario*20;
        aumento=aumento/100;
        salario=salario+aumento;
        printf("Novo salario: R$%0.2f.\nAumento: R$%0.2f.\nPorcentagem do aumento salarial: 20%%.\n",salario,aumento);
        
    }
    else{
        if(salario>1000 && salario<=3000){
            aumento=salario*15;
            aumento=aumento/100;
            salario=salario+aumento;
            printf("Novo salario.: R$%0.2f\nAumento.: R$%0.2f\nPorcentagem do aumento salarial: 15%%.\n",salario,aumento);
        }
    
        else{
            if(salario>3000 && salario<=8000){
                aumento=salario*10;
                aumento=aumento/100;
                salario=salario+aumento;
                printf("Novo salario: R$%0.2f.\nAumento: R$%0.2f.\nPorcentagem do aumento salarial: 10%%.\n",salario,aumento);
            }
            else{
                aumento=salario*5;
                aumento=aumento/100;
                salario=salario+aumento;
                printf("Novo salario: R$%0.2f.\nAumento: R$%0.2f.\nPorcentagem do aumento salarial: 5%%.\n",salario,aumento);
            
            }
        }
    }

 system("pause");
 return 0;
}