#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>

typedef struct{
	char Name[50];
	char cpf[12];
	float salario;
	int sit;
}funcionario;
// ponteiro global
FILE *fp;
// prototipos da funções necessarias
int busca(char*);
int cadastra();
int consulta();
int altera();
int deleta();
void listagem(int);
int recuperar();
int validarCPF();
int main(){
	int option;
	// Menu principal onde é realizado a abertura do arquivo ou a criação caso nao exista
	fp=fopen("cadastros.dad", "rb+");
	if(fp==NULL) fp=fopen("cadastros.dad", "wb+");

	do{
		system("cls");
		printf("1-Novo Cadastro\n2-Alterar algum dado\n3-Consultar algum funcionario\n4-Lista com os Funcionarios ativos\n5-Excluir algum funcionario\n6-Recuperar algum Funcionario\n7-Lixeira\n0-Sair\nInsira a opcao desejada: ");
		scanf("%d", &option);
		switch(option){
			case 1: cadastra(); break; 
			case 2: altera(); break;
			case 3: consulta(); break;
			case 4: listagem(0); break;//possui parametro 0 para indicar cadastros ativos
			case 5: deleta(); break;
			case 6: recuperar();break;
			case 7: listagem(1);//possui parametro 1 para indicar cadastros excluidos
			default: break;
		}
	}while(option!=0);
	fclose(fp);
}
// função que busca pela string cpf no arquivo e me retorna o indice da posição
int busca(char* cpf){
	int i=0;
	funcionario RF;
	fseek(fp, 0, SEEK_SET);
	while(!feof(fp)){
		fread(&RF, sizeof(funcionario), 1, fp);
		if(strcmp(RF.cpf, cpf)==0) return i;
		i++;
	}	
	return -1;
}
//valida o cpf-retornando 1 ou invalida-retornando 0
int validarCPF(char *CPF)
{
    int i, j, digito1 = 0, digito2 = 0, t,s;
    if(strlen(CPF) != 11)
        return 0;
    else if((strcmp(CPF,"00000000000") == 0) || (strcmp(CPF,"11111111111") == 0) || (strcmp(CPF,"22222222222") == 0) ||
            (strcmp(CPF,"33333333333") == 0) || (strcmp(CPF,"44444444444") == 0) || (strcmp(CPF,"55555555555") == 0) ||
            (strcmp(CPF,"66666666666") == 0) || (strcmp(CPF,"77777777777") == 0) || (strcmp(CPF,"88888888888") == 0) ||
            (strcmp(CPF,"99999999999") == 0))
        return 0; ///se o CPF tiver todos os números iguais ele é inválido.
    else
    {
    char c;//armazena cada caractere digitado pelo usuário
    int t=0;//variável para controlar o índice do vetor de caracteres
    int numero=0;//variável para armazenar a conversão do que foi digitado pelo usuário
    
    do
    {
       c=getch();//captura o caractere digitado pelo usuário
       if (isdigit(c)!=0)//se for um número
       {
          CPF[i] = c;//armazena no vetor de caracteres
          i++;//incrementa o índice do vetor de caracteres
       }
	   
    }while(c!=13);//o loop vai ser executado até que a tecla pressionada seja o ENTER (código 13 na tabela ASCII)
    
	CPF[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
    numero = atoi(CPF);//a variável numero recebe o valor do vetor de caracteres convertido para inteiro
    
}
}
//Essa função realiza o cadastro, primeiro ela busca pela função se o cpf ja existe, caso nao exista ela aceita o cadastro e o grava no arquivo

int cadastra(){
	char CPF[12], NOME[50];
	funcionario RF;
	int ind,i,indi;
	float Nsal;
	system("cls");
	fflush(stdin);
	printf("Insira o cpf a ser cadastrado: ");
	gets(CPF);
	
	indi=validarCPF(CPF);
	if(indi==0){
		printf("O CPF informado e invalido.\n");
		Sleep(2000);
		return 0;
	}


	ind=busca(CPF);
	if(ind!=-1){
		printf("\nO CPF inserido ja foi cadastrado\n");
		Sleep(2000);
		return 0;
	}
	printf("\nInsira o nome do funcionario: ");
	fflush(stdin);
	gets(NOME);
	printf("\n Insira o salario: ");
	fflush(stdin);
	scanf("%f", &Nsal);
	strcpy(RF.cpf, CPF);
	strcpy(RF.Name, NOME);
	RF.salario=Nsal;
	RF.sit=0;
	fwrite(&RF, sizeof(funcionario), 1, fp);
}
//função que recebe um inteiro para indicar ativo ou inativo e imprime os respectivos cadastros na tal situação
void listagem(int N){
	funcionario RF;
	int B,i;
	system("cls");
	fseek(fp,0,SEEK_END);
	B=ftell(fp);// função que retorna a quantidade de bytes do arquivo para usar no loop for, resolve um erro do while duplicar o ultimo cadastro;
	fseek(fp,0,SEEK_SET);
	printf("CPF        		NOME				SALARIO\n");
	for(i=0;i<B/sizeof(funcionario);i++){
		fread(&RF, sizeof(funcionario), 1, fp);
		if(RF.sit==N) printf("%s		%-20s		R$%.2f\n", RF.cpf, RF.Name, RF.salario);
	}
	system("pause");
}
// pergunta por um cpf e em seguida permite alterar dados como nome e salario respectivamente
int altera(){
	funcionario RF;
	char CPF[12], NOME[50];
	int ind,option;
	float NewSal;
	system("cls");
	printf("Digite o CPF que deseja alterar algum dado: ");
	fflush(stdin);
	gets(CPF);
	ind=busca(CPF);
	if(ind==-1){
		printf("\nO CPF informado nao foi encontrado\n");
		Sleep(2000);
	}else{
		fseek(fp, ind*sizeof(funcionario), SEEK_SET);
		fread(&RF, sizeof(funcionario), 1, fp);
		if(RF.sit==1){
			printf("\nCadastro foi excluido ou esta na lixeira.");
			Sleep(2000);
			return 0;
		}
		printf("CPF: %s		NOME: %-20s		SALARIO: R$%.2f\n", RF.cpf, RF.Name, RF.salario);
		printf("Qual dado deseja alterar\n1-Nome\n2-salario\n");
		fflush(stdin);
		scanf("%d", &option);
		switch(option){
			case 1: fflush(stdin); gets(NOME); strcpy(RF.Name, NOME); fseek(fp, ind*sizeof(funcionario), SEEK_SET);fwrite(&RF, sizeof(funcionario), 1, fp); break;
			case 2: fflush(stdin); scanf("%f", &NewSal); RF.salario=NewSal; fseek(fp, ind*sizeof(funcionario), SEEK_SET);fwrite(&RF, sizeof(funcionario), 1, fp);
			default: return 0;
		}
		system("pause");
	}
}//função de listagem individual
int consulta(){
	funcionario RF;
	char CPF[12];
	int ind;
	system("cls");
	printf("Digite o cpf a ser consultado: ");
	fflush(stdin);
	gets(CPF);
	ind=busca(CPF);
	if(ind==-1){
		printf("\n O CPF informado nao foi encontrado\n");
		Sleep(2000);
	}else{
		fseek(fp, ind*sizeof(funcionario), SEEK_SET);
		fread(&RF, sizeof(funcionario), 1, fp);
		if(RF.sit==1){
			printf("\nCadastro excluido ou na lixeira.");
			Sleep(2000);
			return 0;
		}
		printf("CPF: %s		NOME: %-20s		SALARIO: R$%.2f\n", RF.cpf, RF.Name, RF.salario);
		system("pause");
	}
	
}//função que muda a validade do cadastro de 0 para 1 para indicar exclusao logica
int deleta(){
	funcionario RF;
	char CPF[12];
	int ind, confirm;
	system("cls");
	printf("Digite o cpf que deseja apagar: ");
	fflush(stdin);
	gets(CPF);
	ind=busca(CPF);
	if(ind==-1){
		printf("\nCPF nao encontrado\n");
		Sleep(2000);
	}else{
		fseek(fp, ind*sizeof(funcionario), SEEK_SET);
		fread(&RF, sizeof(funcionario), 1, fp);
		printf("O CPF %s pertence a %s\n exclua-o com 1 ou anule com 0: ", RF.cpf, RF.Name);
		fflush(stdin);
		scanf("%d", &confirm);
		switch(confirm){
			case 1: RF.sit=1;fseek(fp, ind*sizeof(funcionario), SEEK_SET);fwrite(&RF, sizeof(funcionario), 1, fp);
			default: return 0;
		}
	}}// reverso da função deleta
int recuperar(){
	funcionario RF;
	char CPF[12];
	int ind, confirm;
	system("cls");
	printf("Digite o CPF a ser recuperarado: ");
	fflush(stdin);
	gets(CPF);
	ind=busca(CPF);
	if(ind==-1){
		printf("\nO CPF inserido nao foi encontrado.\n");
		Sleep(2000);
	}else{
		fseek(fp, ind*sizeof(funcionario), SEEK_SET);
		fread(&RF, sizeof(funcionario), 1, fp);
		printf("O CPF: %s pertence a %s\n recupere-o com 1 ou anule com 0: ", RF.cpf, RF.Name);
		fflush(stdin);
		scanf("%d", &confirm);
		switch(confirm){
			case 1: RF.sit=0;fseek(fp, ind*sizeof(funcionario), SEEK_SET);fwrite(&RF, sizeof(funcionario), 1, fp);
			default: return 0;
		}
	}}