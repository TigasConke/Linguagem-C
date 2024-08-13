#include <stdio.h>

struct pessoa {

    int idade;
    float altura;

};

typedef struct Pessoa; // typedef renomeia "struct pessoa" para somente Pessoa

int main(){

    Pessoa p;
    p.idade = 10;
    p.altura = 1.67;

    printf("Essa pessoa tem %d anos.\n", p.idade);
    printf("Essa pessoa tem %.2f m de altura", p.altura);

    return 0;

}
