#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define CPF 12
#define NAME 50

typedef struct{
    char cpf[CPF];
    char nome[NAME];
    float salario;
    char sit;
} cad;

cad cadFun;
FILE *fp;

void copiar(FILE *fpi, FILE *fpo);
FILE *fileOpen(char *arqName, char *mode);
void clear(char *str, int tamanho);
int validaStr(char *str, int tamanho, int rangeMin, int rangeMax);
int filelen(FILE *fp);
int busca(char *wtdCpf);
int incluir(void);
int alterar(void);
int situacao(void);
int consultar(void);
void listar(char sit);
void cleanTrash(void);

int main(){
    int option;
    fp=fileOpen("cadfun.dad", "ab"); //Cria caso nao exista um arquivo binario para escrita. Se existir apenas abre
    fclose(fp);
    fp=fileOpen("cadfun.dad", "r+b");
    do{
        system("cls");
        printf("1 - Incluir\n2 - Alterar\n3 - Situacao\n4 - Consultar\n5 - Listar\n6 - Lixeira\n7 - Limpar lixeira\n8 - Sair\n\nEscolha uma funcao: ");
        scanf("%d", &option);
        fflush(stdin);
        switch(option){
            case 1: incluir(); break;
            case 2: alterar(); break;
            case 3: situacao(); break;
            case 4: consultar(); break;
            case 5: listar('0'); break;
            case 6: listar('1'); break;
            case 7: cleanTrash(); break;
            default: system("cls");
        }
    } while(option!=8);
    fclose(fp);
}

void copiar(FILE *fpi, FILE *fpo){ //Copia todo o conteudo de fpi para fpo
    int tamArq;
    tamArq=filelen(fpi);
    fseek(fpi, 0, SEEK_SET); //Posiciona o cursor do arquivo no inicio, para poder ler todos os cadastros
    while(ftell(fpi)<tamArq){ //Le todos os cadastros ate chegar ao fim
    	fread(&cadFun, sizeof(cad), 1, fpi);
        if(cadFun.sit=='0'){ //Apenas ira escrever no arquivo temporario os cadastros ativos
            fwrite(&cadFun, sizeof(cad), 1, fpo);
        }
	}
}

FILE *fileOpen(char *arqName, char *mode){
	FILE *fpi;
    fpi=fopen(arqName, mode);
    if(!fpi){
        system("cls");
        printf("Erro ao abrir ou criar arquivo de entrada");
        exit(-1);
    
	}
    return fpi;
}

void clear(char *str, int tamanho){ //Preenche todos os espacos de um vetor com ' '
    for(int i=0; i<tamanho; i++){
        *(str+i)=' ';
    }
}

int validaStr(char *str, int tamanho, int rangeMin, int rangeMax){ //Filtra um string com base no seu tamanho em um range se caracteres permitidos. Retorna -1 em caso de CPF invalido
    clear(str, tamanho); //Preenche a string com espacos vazios, para saber se tem menos caracteres que o parametro tamanho
    fgets(str, tamanho, stdin); //Range do parametro deve incluir o \0
    fflush(stdin);
    for(int i=0; i<(tamanho-1); i++){
        if(!(*(str+i)>=rangeMin && *(str+i)<=rangeMax)){
            return -1;
        }
    }
}

int filelen(FILE *fp){ //Retorna o tamanho do arquivo
	fseek(fp, 0, SEEK_END);
	return ftell(fp);
}

int busca(char *wtdCpf){ //Busca e le o CPF no arquivo. Caso encontre retorna 0, caso nao encontre retorna -1
	char curCpf[CPF];
	int tamArq;
    tamArq=filelen(fp);
    fseek(fp, 0, SEEK_SET); //Posiciona o cursor do arquivo no inicio
    do{
        fread(curCpf, sizeof(cadFun.cpf), 1, fp);
        if(strcmp(wtdCpf, curCpf)==0){ //Strcmp retorna 0 se forem iguais
            fseek(fp, ftell(fp)-sizeof(cadFun.cpf), SEEK_SET); //Seta o cursor do arquivo no inicio de um CPF
            fread(&cadFun, sizeof(cad), 1, fp);
            return ftell(fp)-sizeof(cad);
        }
        else{
            fseek(fp, 60, SEEK_CUR); //Avanca para o proximo CPF
        }
    } while(ftell(fp)<tamArq); //se a posicao atual do cursor do arquivo for maior ou igual ao seu tamanho entao ele encerra a busca
    return -1; //caso nao encontro o cpf procurado retorna -1
}

int incluir(void){ //Inclui os dados do funcionario no arquivo. Retorna -1 em caso de CPF invalido ou duplicado
    system("cls");
    //Leitura do cpf
    printf("Digite o CPF do novo funcionario: ");
    if(validaStr(cadFun.cpf, CPF, 48, 57)==-1){ //48: 0, 57: 9. Assim o CPF tera apenas numeros
        printf("CPF invalido");
        system("pause\n");
        return -1;
    }
    if(busca(cadFun.cpf)!=-1){
        printf("CPF duplicado\n");
        system("pause");
        return -1;
    }
    //Leitura do nome
    clear(cadFun.nome, NAME); //Preenhce todo o nome com espacos vazios, para evitar lixo
    printf("Digite o nome do novo funcionario: ");
    scanf("%49[^\n]", cadFun.nome); //%50[^\n]: le no maximo 49 caracters, [^\n] para de ler quando encontrar o \n (deixa o \n no buffer) 
    fflush(stdin);
    //leitura do salario
    do{
        printf("Digite o salario do novo funcionario: ");
        scanf("%f", &cadFun.salario);
        fflush(stdin);
    } while(cadFun.salario<0); //Caso a pessoa digite um valor negativo o processo repete
    cadFun.sit='0'; //Por padrao o cadastro do funcionario e ativo
    fseek(fp, 0, SEEK_END); //Posiciona o cursor do arquivo no fim
    fwrite(&cadFun, sizeof(cad), 1, fp);
}

int alterar(void){ //Altera os dados do funcionario. Retorna -1 em caso de CPF invalido
    char wtdCpf[CPF];
    int option, curPos;
    system("cls");
    //Leitura do CPF
    printf("Digite o CPF do funcionario que deseja alterar alguma informacao: ");
    if(validaStr(wtdCpf, CPF, 48, 57)==-1){
        printf("CPF invalido\n");
        system("pause");
        return -1;
    }
    curPos=busca(wtdCpf);
    if(curPos==-1){
        printf("CPF nao encontrado\n");
        system("pause");
    }
    else{
        if(cadFun.sit=='1'){ //Caso o cadastro esteja inativo nao sera possivel o alterar
            printf("Cadastro inativo\n");
            system("pause");
        }
        else{
            printf("\n1 - CPF\n2 - Nome\n3 - Salario\n\nEscolha o que deseja alterar: ");
            scanf("%d", &option);
            fflush(stdin);
            switch(option){
                case 1:
                    printf("\nDigite o novo CPF: ");
                    if(validaStr(cadFun.cpf, CPF, 48, 57)==-1){
                        printf("CPF invalido");
                        system("pause");
                        return -1;
                    }
                    break;
                case 2:
                    printf("Digite o novo nome: ");
                    scanf("%49[^\n]", cadFun.nome);
                    fflush(stdin);
                    break;
                case 3:
                    do{
                        printf("Digite o novo salario: ");
                        scanf("%f", &cadFun.salario);
                        fflush(stdin);
                    } while(cadFun.salario<0);
                    break;
                default: 
                    printf("Escolha invalida\n");
                    system("pause");
            }
            fseek(fp, curPos, SEEK_SET);
            fwrite(&cadFun, sizeof(cad), 1, fp); //Sobresscreve os dados, so funciona se for r+b
        }
    }
}

int situacao(void){ //Comuta a situacao do funcionario. Retorna -1 em caso de CPF invalido
    char wtdCpf[CPF];
    int curPos;
    system("cls");
    printf("Digite o CPF do funcionario: ");
    if(validaStr(wtdCpf, CPF, 48, 57)==-1){
        printf("CPF invalido\n");
        system("pause");
        return -1;
    }
    curPos=busca(wtdCpf);
    if(curPos==-1){
        printf("CPF nao encontrado\n");
        system("pause");
    }
    else{
        cadFun.sit=='0'?cadFun.sit='1':cadFun.sit='0'; //operador ternario: condicao?verdadeiro:falso
        fseek(fp, curPos, SEEK_SET);
        fwrite(&cadFun, sizeof(cad), 1, fp);
        printf("Agora a situacao de %s esta %s\n", cadFun.nome, cadFun.sit=='0'?"ativa":"inativa");
        system("pause");
    }
}

int consultar(void){ //Exibe os dados do funcionario. Nao exibe caso o funcionario esteja inativo. Retorna -1 em caso de CPF invalido
    char wtdCpf[CPF];
    system("cls");
    printf("Digite o CPF do funcionario: ");
    if(validaStr(wtdCpf, CPF, 48, 57)==-1){
        printf("CPF invalido\n");
        system("pause");
        return -1;
    }
    if(busca(wtdCpf)==-1){
        printf("CPF nao encontrado\n");
        system("pause");
    }
    else{
        if(cadFun.sit=='1'){
            printf("Cadastro inativo\n");
            system("pause");
        }
        else{
            printf("\nCPF: %s\nNome: %s\nSalario: %.2f\nSituacao: %s\n", cadFun.cpf, cadFun.nome, cadFun.salario, cadFun.sit=='0'?"Ativo":"Inativo");
            system("pause");
        }
    }
}

void listar(char sit){ //Lista os cadastros ativos de sit for 1 ou os inativos se sit for 0
    int tamArq;
    tamArq=filelen(fp);
    fseek(fp, 0, SEEK_SET);
    system("cls");
    printf("|___CPF___| |______________________NOME______________________| |_SALARIO_| |_SIT_|\n");
    do{
        fread(&cadFun, sizeof(cad), 1, fp);
        if(cadFun.sit==sit){
            printf("%s %-50s %9.2f %5c\n", cadFun.cpf, cadFun.nome, cadFun.salario, cadFun.sit);
        }
    } while(ftell(fp)<tamArq);
    printf("\n");
    system("pause");
}

void cleanTrash(void){ //Apaga todos os cadastros inativos
    FILE *fpt; //Cria um ponteiro para um arquivo temporario
    fpt=fileOpen("temp.dad", "a+b"); 
    copiar(fp, fpt); //Copia os cadastros ativos do arquivo para um temporario
    fclose(fp);
    fp=fileOpen("cadfun.dad", "w+b"); //Reabre o arquivo em branco (w+b)
    copiar(fpt, fp); //Copia o conteudo do arquivo temporario para o arquivo
    fclose(fpt);
    if(remove("temp.dad")==-1){ //Apaga o arquivo temporario
        system("cls");
        printf("Erro ao apagar arquivo temporario");
        exit(-1);
    }
    fclose(fp); //Fecha fp para poder reabri com r+b
    fp=fileOpen("cadfun.dad", "r+b");
}