#include<stdio.h>
#include<stdlib.h>
int main(){
float H=0;
int N, val=1;
printf("Entre com o valor de N:");
scanf("%d",&N);
while (val <= N){
H = H + val;
val++;
}
printf("O valor de H e: %f\n", H);
return 0;
}
