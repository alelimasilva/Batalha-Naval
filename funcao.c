#include<stdio.h>
#include<stdlib.h>
#include"funcao.h"


void inicializar(int player[N][N]){

    int i,j;

    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            player[i][j] = 1;

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
            if (j == N-1)
                printf(" %d |",player[i][j]);
            else
                printf(" %d ",player[i][j]);
        }
    }
    printf("\n|---------------------------------|");
}