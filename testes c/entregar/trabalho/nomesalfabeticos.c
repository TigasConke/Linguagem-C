#include<stdio.h>
#include<string.h>
const int qtd = 3;
const int tam = 100;
int main()
{
    int i, j, x, menor;
    char a[qtd][tam], aux[qtd];
    for(i = 0; i < qtd; i++)
    {
        printf("Informe o %d nome: ", i + 1);
        gets(a[i]);
    }
        for(i = 0; i < qtd - 1; i++)
        {
                x = 0;
                menor = i;
                for(j = i + 1; j < qtd; j++)
                {
                    x = 0;
                    while(a[menor][x] == a[j][x])
                    {
                            x++;
                    } 
                    if(a[menor][x] > a[j][x])
                    {
                         menor = j;
                    }
                }
                if(menor != i)
                {
                        strcpy(aux, a[menor]);
                        strcpy(a[menor], a[i]);
                        strcpy(a[i], aux);
                }
        }
        for(i = 0; i < qtd; i++)
        {
                printf("%s%c", a[i], 10);
        }
 return 0;
}