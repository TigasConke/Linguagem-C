#include<stdio.h>
#include<stdlib.h>

int main(){
 //Plano básico de celular que dá direito a 100 min(custando R$50,00), se o cliente excerder a franquia deverá pagar R$2,00 por minuto após os 100 min.//
    
    int mgastos,minutos=100;
    float total=50;
    
    printf("Insira a quantidade de minutos consumidas:");
    scanf("%d",&mgastos);

    while(minutos<mgastos){
        total=total+2;
        minutos=minutos+1;
    }

    printf("Valor a pagar: R$%0.2f\n",total);

  
 system("pause");
 return 0;
}