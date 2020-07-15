#include<stdio.h>
#include<stdlib.h>
#include"funcao.h"

void inicializar(int player[N][N]){

    int i,j;

    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            player[i][j] = 0;

}


void print_campo(int player[N][N], int num_player){

    int i,j,k;

    printf("\n|---------------------------------|");
    printf("\n|             PLAYER %d            |",num_player);
    printf("\n|---------------------------------|");
    printf("\n|       ");
    for(k=1;k<=N;k++)
        if (k==N)
           printf("%d |",k);
        else 
            printf("%d  ",k);
    printf("\n|---------------------------------|");
    for(i=0; i<N; i++){
        printf("\n");
        printf("|%d -- |",i+1);
        for(j=0; j<N; j++){
            if (player[i][j] == 0 || player[i][j] == 1){ // agua ou barco escondido
                if (j == N-1)
                    printf(" ~ |");
                else
                    printf(" ~ ");
            }
            if (player[i][j] == 2){ // tiro no barco
                if (j == N-1)
                    printf(" X |");
                else
                    printf(" X ");
            }
            if (player[i][j] == 3){ // tiro na agua
                if (j == N-1)
                    printf(" * |");
                else
                    printf(" * ");
            }                      
        }
    }
    printf("\n|---------------------------------|");
}


void add_barco1x1(int player[N][N], int num_player){

    int linha, coluna;
    int flag_addbarco =0;
    system("cls");
    while(flag_addbarco != 5){
        print_campo(player,num_player);
        printf("\nAdicionando barco para o PLAYER %d\n",num_player);
        printf("Digite a linha e a coluna do %d%c barco. \n",flag_addbarco+1,167);
        printf("Linha: ");
        scanf("%d",&linha);
        printf("Coluna: ");
        scanf("%d",&coluna);
        if (linha>N || linha<1 || coluna>N || coluna<1){
            printf("LINHA OU COLUNA INVALIDA!!!\nDIGITE NOVAMENTE.\n");
            system("pause");
            system("cls");
        }
        else if(player[linha-1][coluna-1] == 1){
            printf("JA EXISTE UM BARCO NESTE LOCAL!!!\nDIGITE NOVAMENTE.\n");
            system("pause");
            system("cls");
        }
        else{
            player[linha-1][coluna-1] = 1;
            flag_addbarco++;
            printf("Barco adicionado com sucesso!\n");
            system("pause");
            system("cls");
        }
    }
}


int game (int player[N][N],int num_player){

    int tiro;
    int linha, coluna;
    int flag = 0;

        printf("Vez do PLAYER %d\n",num_player);
        print_campo(player,num_player);
        printf("\nDIGITE A LINHA E A COLUNA DO TIRO\n");
        printf("Linha: ");
        scanf("%d",&linha);
        printf("Coluna: ");
        scanf("%d",&coluna);
        if (linha>N || linha<1 || coluna>N || coluna<1){
            printf("LINHA OU COLUNA INVALIDA!!!\nDIGITE NOVAMENTE.\n");
            system("pause");
            system("cls");
            game(player,num_player);
        }
        if(player[linha-1][coluna-1] == 2 || player[linha-1][coluna-1] == 3){
            printf("Perdeu a vez!!!!\n");
            system("pause");
            system("cls");
            return 0;
        }   
        if(player[linha-1][coluna-1] == 0){
            printf("Tiro na agua!!!!\n");
            player[linha-1][coluna-1] = 3;
            system("pause");
            system("cls");
            return 0;
        }
        if(player[linha-1][coluna-1] == 1){
            printf("Acertou um barco!!!!\n");
            player[linha-1][coluna-1] = 2;
            system("pause");
            system("cls");
            return 1;
        }
}