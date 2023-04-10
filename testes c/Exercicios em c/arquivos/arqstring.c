#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    FILE *file;
    file = fopen("string.txt","r");
    
    if(file == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        getchar();
        exit(0);
    }
    
    char frase[100];

    while(fgets(frase, 100, file) != NULL){
        printf("%s",frase);
    }

    fclose(file);
















 return 0;
}
