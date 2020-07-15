#include<stdio.h>
#include<stdlib.h>
#include"funcao.h"

int main(){

    int cont_player1= 0, cont_player2 = 0;

    inicializar(player1);
    add_barco1x1(player1,1);
    inicializar(player2);
    add_barco1x1(player2,2);

    for(;;){
        if(game(player2,1) == 1){
            cont_player1++;
            if (cont_player1 == 5){
                printf("PLAYER 1 VENCEU O JOGO!!!!\n");
                system("pause");
                break;
            }
        }
        if(game(player1,2) == 1){
            cont_player2++;
            if (cont_player2 == 5){
                printf("PLAYER 2 VENCEU O JOGO!!!!\n");
                system("pause");
                break;
            }
        }
    }
    return 0;
}


// 0 = agua (~)
// 1 = barco escondido(~)
// 2 = tiro no barco (X)
// 3 = tiro na agua (*)
