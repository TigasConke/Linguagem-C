#include<stdio.h>
#include<stdlib.h>

int main(){
    float glicose;

    printf("Digite a medida da glicose em mg/dl:\n");
    scanf("%f",&glicose);
    system("cls");

    if(glicose<=100){
        printf("Normal.\n");
    }
    else{
        if(glicose>100 && glicose<=140){
            printf("Elevado.\n");
        }
        else{
            printf("Diabetes.\n");
        }
    }

 system("pause");
 return 0;
}