#include<stdio.h>
#include<stdlib.h>

int main(){
    int a,b,c,d;
    printf("Digite 4 numeros e descubra quias sao os 3 maiores:");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    
    if(a<=0 || b<=0 || c<=0 || d<=0){
        printf("Numeros menores que zero ou zero sao invalidos.\n");
        system("pause"); 
    }

    if(a>d & c>d & b>d & a>0 & b>0 & c>0 & d>0){
        printf("Os mairoes numeros da sequencia sao %d, %d e %d.\n", a, b , c);
    }
    else if(a>c & d>c & b>c & a>0 & b>0 & c>0 & d>0){
        printf("Os mairoes numeros da sequencia sao %d, %d e %d.\n", a, b , d);
    }
    else if(a>b & c>b & d>b & a>0 & b>0 & c>0 & d>0){
        printf("Os mairoes numeros da sequencia sao %d, %d e %d.\n", a, d , c);
    }
    else if(b>a & c>a & d>a & a>0 & b>0 & c>0 & d>0){
        printf("Os mairoes numeros da sequencia sao %d, %d e %d.\n", d, b , c);
    }    
  system("pause");
  return 0;
}