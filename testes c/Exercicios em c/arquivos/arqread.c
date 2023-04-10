#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE *file;
    file = fopen("C:\\Users\\roger\\Desktop\\curso programacao\\LInguagem C\\Exercicios em c\\arquivos\\numeros.txt", "r");
    if(file==NULL){
        printf("Nao foi possivel abrir o arquivo.");
        system("pause");
    }
    int x, y, z, s;

    fscanf(file,"%i %i %i", &x, &y, &z);

    s= x + y + z;

    printf("%i %i %i\n", x, y, z);
    printf("A soma dos numeros do arquivo e igual a %d\n", s);

    fclose(file);

    system("pause");
    
 return 0;
}