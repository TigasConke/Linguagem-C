#include<stdio.h>
#include<stdlib.h>

int main(){
    int x, y;
    while(x!=y){
        
        printf("Informe um numero:\n");
        scanf("%d",&x);
        system("cls");
        printf("Informe um segundo numero:\n");
        scanf("%d",&y);
        
        if(x > y && x != y){
            printf("Decrescente\n");
        }
        else{
            if(x != y){
                printf("Crescente\n");
            }
        }

    }

 system("pause");
 return 0;
}