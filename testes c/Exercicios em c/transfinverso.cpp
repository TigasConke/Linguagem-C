#include <iostream>

int main(){

	int A[10], B[10];
	
	for(int i=0;i<10;i++){
		
		printf("Digite um numero:");
		scanf("%d", &A[i]);
		
	}
	
	 for(int i = 0; i < 10; i++){
        B[i] = A[9 - i];
    }
			
	
	
	for(int i=0; i<10;i++){
		
		printf("%d\n", B[i]);
		
	}
	
	
}
