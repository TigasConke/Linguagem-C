#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main () {
float nota1,nota2,nota3,Media;
printf("Digite as notas para descobrir a media e o status:");
scanf("%f %f %f",&nota1,&nota2,&nota3);
Media=(nota1+nota2+nota3)/3;
printf("Media= %5.2f\n",Media);
if(Media>=7){
printf("Aprovado\n");
system("PAUSE");} 
else if(Media<7)
printf("Reprovado");
system("PAUSE");

return 0;
}
