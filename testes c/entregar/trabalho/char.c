#include <stdio.h>
#include <stdlib.h>
int main() {
	FILE *fp;
    int total = 0;
    fp = fopen("qtd.txt", "rt");
	if (fp==NULL) {
		printf("Arquivo nao existe.");
		exit(1);
	}
	while (getc(fp)!=EOF){
		total++;
	}
	printf("%d", total);
	return 0;
}










