#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i=1,resultado=0,d=1;
    
    while(d<=1){
        printf("Digite a tabauada de que numero voce quer ver:");
        scanf("%d",&n);

        for(i=1;i<=10;i++){
            resultado=n*i;
            printf("%d x %d = %d\n",n,i,resultado);

        }
        
        printf("Deseja ver alguma outra tabuada? Digite (1)sim e (2)nao.\n");
        scanf("%d",&d);
        system("cls");
    }

 system("pause");
 return 0;
}