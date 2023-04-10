#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Para o srand
#include <windows.h> //Para o Sleep

#define TAMANHO_TABULEIRO 2
#define CODIGO_ASCII_A 65
#define POSICAO_MENOR_CARTA 11
#define TAMANHO_INT sizeof(int)
#define TAMANHO_CHAR sizeof(char)

int tabuleiroCartas[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]; //Inicializa tudo com zero
int tabuleiroPosicoes[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
char nomeJogadorAtual[11];
FILE *arquivoInformacoesPartida;

int exibirMenuPrincipal(void);
int jogarJogoMemoria(void);
void identificarJogador(void);
void criarArquivoJogador(void);
void exibirRank(void);
void organizarRank(void);
void escolherNivelJogo(void);
void inicializarTabuleiroCartas(void);
void inicializarTabuleiroPosicoes(void);
void zerarTabuleiros(void);
void exibirTabuleiro(void);
int gerarSimboloValido(void);
int gerarSimboloAleatorio(void);
int calcularQuantidadeSimbolos();
int gerarNumeroAleatorio(int menorNumeroAleatorio, int maiorNumeroAleatorio);
int contarRepeticoesTabuleiro(int simboloProcurado);
int contarZerosTabuleiro(void);
void escolherCarta(void);
void exibirCartasEscolhidas(int primeiraCartaEscolhida, int segundaCartaEscolhida);
int calcularLinhaEscolhida(int posicaoEscolhida);
int calcularColunaEscolhida(int posicaoEscolhida);
int verificarCartasEscolhidas(int primeiraCartaEscolhida, int segundaCartaEscolhida);
int calcularQuantidadeRegistros(FILE *fp);
void escreverArquivosPontuacao(int pontuacaoJogador);
void bubble_sort(int arr[], int n) {
  int i, j, temp;
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}




int main(void){
    srand(time(NULL));
    while(exibirMenuPrincipal()==1);
    return 0;
}

int exibirMenuPrincipal(void){
    int opcaoMenuJogador;
    system("cls");
    printf("1 - Jogar\n2 - Nivel\n3 - Continuar\n4 - Rank\n5 - Sair\nEscolha uma opcao: ");
    scanf("%d", &opcaoMenuJogador);
    fflush(stdin);
    switch(opcaoMenuJogador){
        case 1:
            escreverArquivosPontuacao(jogarJogoMemoria());
            break;
        case 2:
            escolherNivelJogo();
            break;
        case 3:
            break;
        case 4:
            exibirRank();
            break;
        case 5:
            return 0;
            break;
        default: 
            printf("Escolha invalida");
            system("pause");
            break;
    }
    return 1;
}

void escreverArquivosPontuacao(int pontuacaoJogador){
    FILE *rankPontuacaoJogadores=fopen("pontuacaoJogadores.txt", "a+b");
    if(rankPontuacaoJogadores==NULL){
        exit(1);
    } 
    fwrite(&pontuacaoJogador, TAMANHO_INT, 1, rankPontuacaoJogadores);
    fwrite(nomeJogadorAtual, TAMANHO_CHAR, 11, rankPontuacaoJogadores);
    fclose(rankPontuacaoJogadores);
}

int jogarJogoMemoria(){
    int tentativasJogador=0;
    identificarJogador();
    criarArquivoJogador();
    zerarTabuleiros();
    inicializarTabuleiroPosicoes();
    inicializarTabuleiroCartas();
    while(contarZerosTabuleiro()<(TAMANHO_TABULEIRO*TAMANHO_TABULEIRO)){
        escolherCarta();
        tentativasJogador++;
    }
    printf("Tentativas: %d\n", tentativasJogador);
    system("pause");
    return tentativasJogador;
}

void identificarJogador(void){
    system("cls");
    printf("Informe seu nickname: ");
    scanf("%s", nomeJogadorAtual);
    fflush(stdin);
}

void criarArquivoJogador(void){
    arquivoInformacoesPartida=fopen(nomeJogadorAtual, "a+b");
    if(arquivoInformacoesPartida==NULL){
        exit(1);
    }
    fclose(arquivoInformacoesPartida);
}

void zerarTabuleiros(void){
    int i, j;
    for(i=0; i<TAMANHO_TABULEIRO; i++){
        for(j=0; j<TAMANHO_TABULEIRO; j++){
            tabuleiroCartas[i][j]=0;
            tabuleiroPosicoes[i][j]=0;
        }
    }
}

void inicializarTabuleiroPosicoes(){
    int i, j;
    for(i=0; i<TAMANHO_TABULEIRO; i++){
        for(j=0; j<TAMANHO_TABULEIRO; j++){
            tabuleiroPosicoes[i][j]=((i+1)*10)+(j+1);
        }
    }
}

void inicializarTabuleiroCartas(){
    int i, j;
    for(i=0; i<TAMANHO_TABULEIRO; i++){
        for(j=0; j<TAMANHO_TABULEIRO; j++){
            tabuleiroCartas[i][j]=gerarSimboloValido();
        }
    }
}

int gerarSimboloValido(){
    int simboloAleatorio;
    do{
        simboloAleatorio=gerarSimboloAleatorio();
    }while(contarRepeticoesTabuleiro(simboloAleatorio)>=2); //2 � a quantidade de vezes que um numero deve se repetir
    return simboloAleatorio;
}

int gerarSimboloAleatorio(){
    int quantidadeSimbolosDiferentes=calcularQuantidadeSimbolos();
    return gerarNumeroAleatorio(CODIGO_ASCII_A, CODIGO_ASCII_A+quantidadeSimbolosDiferentes-1); //-1 pois o A tamb�m entra na contagem
}

int calcularQuantidadeSimbolos(){
    return (TAMANHO_TABULEIRO*TAMANHO_TABULEIRO)/2;
}

int gerarNumeroAleatorio(int menorNumeroAleatorio, int maiorNumeroAleatorio){
    return menorNumeroAleatorio+rand()%(maiorNumeroAleatorio-menorNumeroAleatorio+1);
}

int contarRepeticoesTabuleiro(int simboloProcurado){
    int count=0;
    int i, j;
    for(i=0; i<TAMANHO_TABULEIRO; i++){
        for(j=0; j<TAMANHO_TABULEIRO; j++){
            if(tabuleiroCartas[i][j]==simboloProcurado){
                count++;
            }
        }
    }
    return count;
}

int contarZerosTabuleiro(){
    int count=0;
    int i, j;
    for(i=0; i<TAMANHO_TABULEIRO; i++){
        for(j=0; j<TAMANHO_TABULEIRO; j++){
            if(tabuleiroPosicoes[i][j]==0){
                count++;
            }
        }
    }
    return count;
}

void escolherCarta(){
    int primeiraCartaEscolhida;
    int segundaCartaEscolhida;
    do{
        system("cls");
        exibirTabuleiro();
        printf("Escolha a primeira carta: ");
        scanf("%d", &primeiraCartaEscolhida);
        printf("Escolha a segunda carta: ");
        scanf("%d", &segundaCartaEscolhida);
    }while(verificarCartasEscolhidas(primeiraCartaEscolhida, segundaCartaEscolhida)==0);
    system("cls");
    exibirCartasEscolhidas(primeiraCartaEscolhida, segundaCartaEscolhida);
    Sleep(1000);
}

void exibirCartasEscolhidas(int primeiraCartaEscolhida, int segundaCartaEscolhida){
    int i, j;
    for(i=0; i<TAMANHO_TABULEIRO; i++){
        for(j=0; j<TAMANHO_TABULEIRO; j++){
            if(tabuleiroPosicoes[i][j]==primeiraCartaEscolhida || tabuleiroPosicoes[i][j]==segundaCartaEscolhida || tabuleiroPosicoes[i][j]==0){
                printf("%5c", tabuleiroCartas[i][j]);
            }
            else{
                printf("%5d", tabuleiroPosicoes[i][j]);
            }
        }
        printf("\n");
    }
}

void exibirTabuleiro(){
    int i, j;
    for(i=0; i<TAMANHO_TABULEIRO; i++){
        for(j=0; j<TAMANHO_TABULEIRO; j++){
            if(tabuleiroPosicoes[i][j]==0){
                printf("%5c", tabuleiroCartas[i][j]);
            }
            else{
                printf("%5d", tabuleiroPosicoes[i][j]);
            }
        }
        printf("\n");
    }
}

int verificarCartasEscolhidas(int primeiraCartaEscolhida, int segundaCartaEscolhida){
    int linhaPrimeiraCartaEscolhida=calcularLinhaEscolhida(primeiraCartaEscolhida);
    int colunaPrimeiraCartaEscolhida=calcularColunaEscolhida(primeiraCartaEscolhida);
    int linhaSegundaCartaEscolhida=calcularLinhaEscolhida(segundaCartaEscolhida);
    int colunaSegundaCartaEscolhida=calcularColunaEscolhida(segundaCartaEscolhida);
    if(primeiraCartaEscolhida==segundaCartaEscolhida){
        printf("A mesma carta foi escolhida duas vezes\n");
    }
    else if(primeiraCartaEscolhida<POSICAO_MENOR_CARTA || segundaCartaEscolhida<POSICAO_MENOR_CARTA){
        printf("Essa carta nao existe\n");
    }
    else if(linhaPrimeiraCartaEscolhida>=TAMANHO_TABULEIRO || colunaPrimeiraCartaEscolhida>=TAMANHO_TABULEIRO || linhaSegundaCartaEscolhida>=TAMANHO_TABULEIRO || colunaSegundaCartaEscolhida>=TAMANHO_TABULEIRO){
        printf("Essa carta nao existe\n");
    }
    else if(tabuleiroPosicoes[linhaPrimeiraCartaEscolhida][colunaPrimeiraCartaEscolhida]==0 || tabuleiroPosicoes[linhaSegundaCartaEscolhida][colunaSegundaCartaEscolhida]==0){
        printf("Essa carta ja foi revelada\n");        
    }
    else if(tabuleiroCartas[linhaPrimeiraCartaEscolhida][colunaPrimeiraCartaEscolhida]==tabuleiroCartas[linhaSegundaCartaEscolhida][colunaSegundaCartaEscolhida]){
        tabuleiroPosicoes[linhaPrimeiraCartaEscolhida][colunaPrimeiraCartaEscolhida]=0;
        tabuleiroPosicoes[linhaSegundaCartaEscolhida][colunaSegundaCartaEscolhida]=0;
        return 1; //Em caso de acerto
    }
    else{
        return 1; //Em caso de erro
    }
    system("pause");
    return 0; //Entrada de cartas invalidas
}

int calcularLinhaEscolhida(int posicaoEscolhida){
    return (posicaoEscolhida/10)-1; //Mesmo que a divis�o seja um n�mero decimal, apenas a parte inteira retorna por ser int. -1 pois a matriz come�a em 0
}

int calcularColunaEscolhida(int posicaoEscolhida){
    return (posicaoEscolhida-((posicaoEscolhida/10)*10))-1; //Ex.: 34/10=3 (po ser int a parte decimal � descartada). 3*10=30. 34-30=4. -1 pois a matriz come�a em 0
}

void escolherNivelJogo(void){
    int opcaoNivelJogador;
    system("cls");
    printf("1 - Facil\n2 - Medio\n3 - Dificil\nEscolha um nivel: ");
    scanf("%d", &opcaoNivelJogador);
    fflush(stdin);
}

void exibirRank(void){
    bubble_sort(int arr[], int n);
    system("cls");
    int pontuacaoJogador;
    char nomeJogador[11];
    int i;
    FILE *rankPontuacaoJogadores=fopen("pontuacaoJogadores.txt", "a+b");
    if(rankPontuacaoJogadores==NULL){
        exit(1);
    } 
    int quantidadeRegistrosJogadores=calcularQuantidadeRegistros(rankPontuacaoJogadores);
    fseek(rankPontuacaoJogadores, 0, SEEK_SET);
    for(i=0; i<quantidadeRegistrosJogadores; i++){
        fread(&pontuacaoJogador, TAMANHO_INT, 1, rankPontuacaoJogadores);
        fread(nomeJogador, TAMANHO_CHAR, 11, rankPontuacaoJogadores);
        printf("Pontos: %-5d", pontuacaoJogador);
        printf("Nome: %10s\n", nomeJogador);
    }
    system("pause");
    fclose(rankPontuacaoJogadores);
}



int calcularQuantidadeRegistros(FILE *fp){
    fseek(fp, 0, SEEK_END);
    return ftell(fp)/((TAMANHO_CHAR*11)+TAMANHO_INT);
}
