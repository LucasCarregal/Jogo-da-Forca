#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>

FILE *dados;
int erros = 0, cont = 0;
char palavra[30], tentativa[30], categoria[10], letrasErradas[30];
char head=' ', corpo=' ',braco1=' ', braco2=' ', perna1=' ',perna2=' ';
bool rodada=false;

char menu();
int escolha_aleatoria();
void buscar_string(int num);
void formato();
void palpite();
bool confere();
void restart();

int main(){
    char op;

    printf("\n           *****   *****   *****   ******  ******\n"); Sleep(750);
    printf("           **     **   **  **  **  **      **  **\n"); Sleep(750);
    printf("           ****   **   **  ****    **      ******\n"); Sleep(750);
    printf("           **     **   **  ** **   **      **  **\n"); Sleep(750);
    printf("           **      *****   **  **  ******  **  **\n"); Sleep(1500);


    do{

    x:

    system("cls");

    op = menu();

    printf("\n");

    switch (op){

    case 'C':
        dados = fopen("cores.txt","r");
        categoria[0] = 'C';
        categoria[1] = 'O';
        categoria[2] = 'R';
        categoria[3] = 'E';
        categoria[4] = 'S';
        categoria[5] = '\0';
        break;

    case 'F':
        dados = fopen("frutas.txt","r");
        categoria[0] = 'F';
        categoria[1] = 'R';
        categoria[2] = 'U';
        categoria[3] = 'T';
        categoria[4] = 'A';
        categoria[5] = 'S';
        categoria[6] = '\0';
        break;

    case 'P':
        dados = fopen("paises.txt","r");
        categoria[0] = 'P';
        categoria[1] = 'A';
        categoria[2] = 'I';
        categoria[3] = 'S';
        categoria[4] = 'E';
        categoria[5] = 'S';
        categoria[6] = '\0';
        break;

    case 'M':
        dados = fopen("marcas.txt","r");
        categoria[0] = 'M';
        categoria[1] = 'A';
        categoria[2] = 'R';
        categoria[3] = 'C';
        categoria[4] = 'A';
        categoria[5] = 'S';
        categoria[6] = '\0';
        break;

    case 'E':
        dados = fopen("esportes.txt","r");
        categoria[0] = 'E';
        categoria[1] = 'S';
        categoria[2] = 'P';
        categoria[3] = 'O';
        categoria[4] = 'R';
        categoria[5] = 'T';
        categoria[6] = 'E';
        categoria[7] = 'S';
        categoria[8] = '\0';
        break;

    case 'S':
        system("cls");
        printf("******************************\n");
        printf("*                            *\n");
        printf("*    Obrigado por jogar      *\n");
        printf("*                            *\n");
        printf("******************************\n");
        Sleep(2000);
        exit(0);

    default:
        system("cls");
        printf("\7******************************\n");
        printf("*                            *\n");
        printf("*   CATEGORIA INDISPONIVEL   *\n");
        printf("*    escolha outra opcao     *\n");
        printf("*                            *\n");
        printf("******************************\n");
        Sleep(1500);
        goto x;
    }

    buscar_string(escolha_aleatoria());

    for(int i=0; i<strlen(palavra); i++)
        tentativa[i] = '-';

    system("cls");

    do{
        formato();
        palpite();
        confere();
    }
    while(rodada == false);
        system("cls");

    restart();

    }while(1);

return 0;
}

char menu(){
    printf("*************** Bem Vindo ao Jogo da forca! ***************\n");
    printf("\nQual categoria de palavra voce deseja jogar?\n\n");
    printf("(C)ores\n");
    printf("(F)rutas\n");
    printf("(P)aises\n");
    printf("(M)arcas\n");
    printf("(E)sportes\n");
    printf("(S)air\n");
    printf(">");
    return toupper(getche());
}

int escolha_aleatoria(){
    srand((unsigned)time(NULL));
    return rand()%10;
}


void buscar_string(int num){
    int p;
    char buf[50], *pal;

    fgets(buf, 50, dados);

    while(!feof(dados)){
        p = atoi(strtok(buf,"|"));
        pal = strtok(NULL,"|\n");

        strncpy(palavra, pal, 30);

        if(num == p){
            break;
        }
        else{
            fgets(buf, 50, dados);
        }
    }
}

void formato(){
    system("cls");
    switch (erros){
        case 1:
            head = 'O';
            break;

        case 2:
            corpo = '|';
            break;

        case 3:
            braco1 = '/';
            break;

        case 4:
            braco2 = '\\';
            break;

        case 5:
            perna1 = '/';
            break;

        case 6:
            perna2 = '\\';
    }
    printf("CATEGORIA: %s\n\n", categoria);
    printf(" +--------+     \n");
    printf(" |        |     \n");
    printf(" |        %c    \n", head);
    printf(" |       %c%c%c \n",braco1,corpo,braco2);
    printf(" |        %c    \n",corpo);
    printf(" |       %c %c  \n",perna1,perna2);
    printf(" |\n");
    printf(" |\n");
    printf("       %s\n\n",tentativa);
    printf(" %s\n\n",letrasErradas);
}

void palpite(){
    char letra;
    bool achou = false;

    printf(">");
    letra = toupper(getche());
    printf("\n");

    for(int i=0; i<strlen(palavra); i++){
        if(letra == palavra[i]){
            tentativa[i] = palavra[i];
            achou = true;
        }
    }
    if(achou == false){
        erros++;
        printf("\7\n A PALAVRA NAO POSSUI ESSA LETRA\n");

        letrasErradas[cont] = letra;
        letrasErradas[cont+1] = ' ';
        cont++;
        cont++;

        Sleep(500);
    }
}

bool confere(){
    if(strcmp(tentativa, palavra) == 0){
        system("cls");
    printf("CATEGORIA: %s\n\n", categoria);
    printf(" +--------+     \n");
    printf(" |        |     \n");
    printf(" |        %c    \n", head);
    printf(" |       %c%c%c \n",braco1,corpo,braco2);
    printf(" |        %c    \n",corpo);
    printf(" |       %c %c  \n",perna1,perna2);
    printf(" |\n");
    printf(" |\n");
    printf("       %s\n",palavra);
    printf(" %s\n\n",letrasErradas);
        printf("\n************************");
        printf("\n*                      *");
        printf("\n* PARABENS VOCE GANHOU *");
        printf("\n*                      *");
        printf("\n************************\n");
        rodada = true;
        system("pause");
    }
    if(erros == 7){
        printf("\n A PALAVRA ERA: %s\n", palavra);
        printf("\n************************");
        printf("\n*                      *");
        printf("\n*      GAME OVER       *");
        printf("\n*                      *");
        printf("\n************************\n");
        rodada = true;
        system("pause");
    }
}

void restart(){
    erros = 0;
    cont = 0;
    for(int i = 0; i<30; i++){
        palavra[i]='\0';
        tentativa[i]='\0';
        letrasErradas[i]=' ';
    }
    head = ' ';
    corpo=' ';
    braco1=' ';
    braco2=' ';
    perna1=' ';
    perna2=' ';
    rodada=false;
}
