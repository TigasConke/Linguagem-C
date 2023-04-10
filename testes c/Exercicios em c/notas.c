#include<stdio.h>
#include<stdlib.h>

int main(){
    float nota1,nota2,media;

    printf("Informe a nota do primeiro semestre do aluno:\n");
    scanf("%f",&nota1);

    printf("Informe a nota do segundo semestre do aluno\n");
    scanf("%f",&nota2);

    media=(nota1+nota2)/2;
    
    if(media>=60){
        printf("A media anual do aluno foi:\n%0.2f\n",media);
        printf("O aluno esta aprovado\n");
    }
    else{
        printf("A media anual do aluno foi:\n%0.2f\n",media);
        printf("O aluno esta reprovado");
    }
    









 return 0;
}