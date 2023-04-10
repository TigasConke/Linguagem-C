//Escreve em um arquivo txt

#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE *file;
    file = fopen("C:\\Users\\roger\\Desktop\\curso programacao\\LInguagem C\\Exercicios em c\\arquivos\\arq.txt", "w");
    fprintf(file, "Tiago Conke");
    fclose(file);

 return 0;
}
