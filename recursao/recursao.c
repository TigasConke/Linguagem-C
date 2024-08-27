#include <stdio.h>
#include <stdlib.h>

int potencia(int base, int expoente){

    if(expoente == 1){

        return base;

    }
    return base * potencia(base,expoente-1);

}

int main(){

    int res = potencia(2,3);
    printf("%d",res);

    return 0;

}
