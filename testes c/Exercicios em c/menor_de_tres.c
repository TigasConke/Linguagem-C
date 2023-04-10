#include<stdio.h>
#include<stdlib.h>

int main(){
    int a,b,c;
    printf("Digite 3 numeros para saber qual e o menor:");
    scanf("%d %d %d",&a,&b,&c);

    if(a<=b && a<=c){
        printf("O menor numero e %d",a);
        
    }

    else{
        if(b<=a && b<=c){
            printf("O menor numero e o %d",b);
        }

        else
        printf("O menor numero e o %d",c);
    }

    system("pause");
  return 0;
}