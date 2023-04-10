#include<stdio.h>
#include<stdlib.h>

int main(){
    char nome1[15], nome2[15];
    float idade1, idade2, media;
    
    printf("Digite o nome da primeira pessoa:");
        scanf("%s",&nome1);
    printf("Digite a idade da primeira pessoa:");
        scanf("%f",&idade1);
    printf("Digite o nome da segunda pessoa:");
        scanf("%s",&nome2);
    printf("Digite a idade da segunda pessoa:");
        scanf("%f",&idade2);
    
   media=(idade1+idade2)/2;

    printf("A media de idade entre %s e %s e %f", nome1, nome2, media);
    
    return 0;
}