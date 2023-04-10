#include<stdio.h>
#include<stdlib.h>

int main(){ 
  int base, expo, pot=0, i, j, t;
    printf("Digite a base inteira:");
    scanf("%d",&base);

    printf("Digite o expoente:");
    scanf("%d",&expo);

    if(expo == 0){
        if(base == 0){
            printf("\nindeterminacao\n");
            return -1;
        }

        pot = 1;
    }
    else if(expo == 1 || expo == -1)
    pot = base;

    else 
        for(i=0;i<abs(expo>=0 ? expo-1 : expo+1); i++){
            t = pot; 
            for (j=0; j<abs(base); j++)
                if(i==0)
                    pot += base;
                else
                    pot += t;
                if(base < 0)
                pot -= abs(t);
                else
                pot -= t;
         }

         if (expo >=0)
            printf("Resultado:%d",pot);
        else
        printf("Resultado:%d",pot, 1.0/pot);
  return 0;
}