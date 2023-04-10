#include<stdio.h>
#include<stdlib.h>

int main(){
    float chico= 1.5, juca=1.1, anos=0;
    while(chico>juca){
        chico=chico+0.02;
        juca=juca+0.03;
        anos=anos+1;
    }
    printf("%2.f anos.",anos);
   return 0;
}