#include<stdio.h>
#include<stdlib.h>

int main (){
float peso1,massa,peso2,peso3,peso4,peso5,peso6;
    printf("Digite sua massa em gramas:");
        scanf("%f",&massa);
peso1=massa*0.37;
    printf("Seu peso em Mercurio e %.2f gramas\n",peso1);
peso2=massa*0.88;
    printf("Seu peso em Venus e %.2f gramas\n",peso2);
peso3=massa*0.38;
    printf("Seu peso em Marte e %.2f gramas\n",peso3);
peso4=massa*2.64;
    printf("Seu peso em Jupiter e %.2f gramas\n",peso4);
peso5=massa*1.15;
    printf("Seu peso em Saturno e %.2f gramas\n",peso5);
peso6=massa*1.17;
    printf("Seu peso em Urano e %.2f gramas\n",peso6);
    system("PAUSE");

 return 0;
}