#include<stdio.h>
#include<stdlib.h>

int main(){
    int C, V, M1, M2;
    printf("Digite um numero:");
    scanf("%d",&V);

    M1=V;
    
    for(C == 2; C<= 10; C++){
        scanf("%d", &V);
        if(V>M1){
            M2=M1;
            M1=V;
        }
            else{ 
            if(V > M2 || C==2){
                M2=V;
            }
            }
        
    }

    printf("%d %d",M1, M2);
    system("pause");
 
 return 0;
}