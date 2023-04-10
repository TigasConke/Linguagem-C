#include<stdio.h>
#include<stdlib.h>

int main(){
    char name[20],lastname[20];
    float ph,pagamento;
    int horas;

    printf("Digite o primeiro nome seguido do ultimo nome do empregado:");
    scanf("%s %s",&name,&lastname);

    printf("Digite quanto esse empregado ganha por hora:\nR$");
    scanf("%f",&ph);

    printf("Digite quantas horas esse empregado trabalhou:");
    scanf("%d",&horas);

    pagamento=ph*horas;

    printf("O pagamento para %s %s deve ser R$%0.2f",name,lastname,pagamento);

 return 0;
 }