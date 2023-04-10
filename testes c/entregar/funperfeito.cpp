#include <stdio.h>
#include <stdlib.h>

int Perfeito(int n){
    int i, soma = 0;

    for(i = 1; i <= n/2; i++){
        if(n % i == 0)
            soma += i;
    }
    if(soma == n)
        return 1;// perfeito
    else
        return 0;// não perfeito
}
