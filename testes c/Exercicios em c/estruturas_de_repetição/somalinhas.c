#include<stdio.h>
#include<stdlib.h>

int main(){
    int M, N, i=0, j=0;
    float mat[M][N], soma[M];
    
    do{
    	printf("Quantidade de linhas da matriz:\n");
    	scanf("%d",&M);
    	system("cls");

    	printf("Quantidade de colunas da matriz:\n");
    	scanf("%d",&N);
    	system("cls");
	}
    while(M>10 || N>10);  
     
    
    

   
    for(i=0; i<M; i++){
        printf("Insira os elementos da %d linha:\n", i+1);
        for(j=0; j<N; j++){
            scanf("%f",&mat[i][j]);
            
        }
        for(int i=0; i<M; i++){
            soma[i]=0;
            for(int j=0; j<N; j++){
                soma[i]= soma[i] + mat[i] [j];
            }

        }
    }
    
    printf("O vetor gerado da soma dos elementos de cada linha e:\n");
    for(int i=0; i<M; i++){
        
        printf("%0.2f\n",soma[i]);
    }
    







 system("pause");
 return 0;
}