#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char tam_palavra,palavra[25],letra[25],lacuna[25]="_";
    int vida=6,x,i,pontos=0;

    printf("\n\nType a word:\n\n");
    gets(palavra);
    system("cls");

    for(i=0;i<strlen(palavra);i++)
        lacuna[i]='-';
        tam_palavra=strlen(palavra);
        system("cls");

        while(vida>0)
    {   
    x=0;
    printf("\n %s \n",lacuna);
    printf("\n Type a letter: ");
    gets(letra);
    system("cls");


    for(i=0;i<strlen(palavra);i++)
    {
        if(letra[0]==palavra[i])
        {
            lacuna[i]=palavra[i];
            pontos++;
            x++;
            system("cls");
        }
    }
    if(x==0) {
                vida=vida-1;
                system("cls");

                if(vida==0) {
                                printf("\n\n GAME OVER!!");
                                printf("\n The word was: %s",palavra);
                                break;
                            }

                else
                printf("\n YOU MISSED! YOU HAVE %d MORE LIVE(S)",vida); }

    else{
        if(pontos==tam_palavra) {
            printf("\n\n YOU WON! CONGRATS!!");
            printf("\n THE WORD IS: %s",palavra);
            break;}

        else {
            printf("\n CORRECT!");
        }
    }
    } 
    printf("\n\n");
    system("pause");
 return 0; }