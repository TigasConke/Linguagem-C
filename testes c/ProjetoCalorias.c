#include <stdio.h>
#include <stdlib.h>

int main()
{
	int caloriasPrato, caloriasSobremesa, caloriasBebidas;
	
	printf("Escolha o prato desejado:\n 1)Vegetariano \n 2)Peixe \n 3)Frango \n 4)Carne \n");
	printf("Qual sera a sua escolha? ");
	
	int escolhaPrato;
	scanf("%d", &escolhaPrato);
	while(escolhaPrato < 1 || escolhaPrato > 4) //Esse while faz o printf e o scanf repetir sempre que a opcao inserida nao esteja dentro das opcoes dadas
	{ 
		printf("Opcao nao encontrada, insira a opcao novamente: ");
		scanf("%d", &escolhaPrato);
	}
	printf("Escolha do prato registrada com sucesso! \n \n");
	
	switch(escolhaPrato)
	{
		case 1: 
		caloriasPrato = 180;
		break; 
		
		case 2: 
		caloriasPrato = 230;
		break; 
		
		case 3: 
		caloriasPrato = 250;
		break; 
		
		case 4: 
		caloriasPrato = 350;
		break; 	
	}
	
	//-------------------------------------------------------------------------------------------------------------------------------------------------------//
	
	printf("Escolha a sobremesa desejada:\n 1)Abacaxi \n 2)Sorvete diet \n 3)Mouse diet \n 4)Mouse chocolate \n");
	printf("Qual sera a sua escolha? ");
	
	int escolhaSobremesa;
	scanf("%d", &escolhaSobremesa);
	while(escolhaSobremesa < 1 || escolhaSobremesa > 4) //Esse while faz o printf e o scanf repetir sempre que a opcao inserida nao esteja dentro das opcoes dadas
	{
		printf("Opcao nao encontrada, insira a opcao novamente: ");
		scanf("%d", &escolhaSobremesa);
	}
	printf("Escolha da sobremesa registrada com sucesso! \n \n");
	
	switch(escolhaSobremesa)
	{
		case 1: 
		caloriasSobremesa = 75;
		break; 
		
		case 2: 
		caloriasSobremesa = 110;
		break; 
		
		case 3: 
		caloriasSobremesa = 170;
		break; 
		
		case 4: 
		caloriasSobremesa = 200;
		break; 	
	}
	
	//-------------------------------------------------------------------------------------------------------------------------------------------------------//
	
	printf("Escolha a bebida desejada:\n 1)Cha \n 2)Suco de laranja \n 3)Suco de melao \n 4)Refrigerante diet \n");
	printf("Qual sera a sua escolha? ");
	
	int escolhaBebida;
	scanf("%d", &escolhaBebida);
	while(escolhaBebida < 1 || escolhaBebida > 4) //Esse while faz o printf e o scanf repetir sempre que a opcao inserida nao esteja dentro das opcoes dadas
	{
		printf("Opcao nao encontrada, insira a opcao novamente: ");
		scanf("%d", &escolhaBebida);
	}
	printf("Escolha da bebida registrada com sucesso! \n \n");
	
	switch(escolhaBebida)
	{
		case 1: 
		caloriasBebidas = 20;
		break; 
		
		case 2: 
		caloriasBebidas = 70;
		break; 
		
		case 3: 
		caloriasBebidas = 100;
		break; 
		
		case 4: 
		caloriasBebidas = 65;
		break; 	
	}
	
	int caloriasTotais = caloriasPrato + caloriasSobremesa + caloriasBebidas;
	printf("O prato final ficou com um total de: %dcal \n", caloriasTotais);

	//-------------------------------------------------------------------------------------------------------------------------------------------------------//
	system("pause");
	return 0;
}