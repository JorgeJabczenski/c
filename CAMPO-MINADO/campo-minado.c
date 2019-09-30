#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CLEAR_SCREEN  printf("\033[H\033[J")
#define TAM_TABULEIRO 10
#define QNT_MINAS     10

int inicializa_tabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int tam){
    
    int i,j;
    for (i = 0; i < tam; i++)
        for (j = 0; j < tam; j++)
            tabuleiro[i][j] = 0;

    return 0;
}

int imprimir_tabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int tam){
    
   // CLEAR_SCREEN;
    
    int i,j;

    for (i = 0; i < tam; i++){ 
        for (j = 0; j < tam; j++)
            printf("%d ",tabuleiro[i][j]);
        printf("\n");
    }
    return 0;
}

int coloca_minas(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int tam, int minas){
    while(minas){
        int linha  = rand() % tam;
        int coluna = rand() % tam;
        if (tabuleiro[linha][coluna] == 0){
             tabuleiro[linha][coluna] = 9;
             minas--;
        }
    }
    return 0;
}

int conta_minas(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int tam){
    int i, j;
    for (i = 0; i < tam; i++){ 
        for (j = 0; j < tam; j++){
            if (tabuleiro[i][j] != 9){
            int minas = 0;
            if(i == 0){
                if (j == 0){
                    if (tabuleiro[i+1][j]   == 9)  minas++;
                    if (tabuleiro[i+1][j+1] == 9)  minas++;
                    if (tabuleiro[i][j+1]   == 9)  minas++;           

                } else {
                    if (tabuleiro[i+1][j-1] == 9)  minas++;
                    if (tabuleiro[i][j-1]   == 9)  minas++;
                    if (tabuleiro[i+1][j]   == 9)  minas++;
                    if (tabuleiro[i+1][j+1] == 9)  minas++;
                    if (tabuleiro[i][j+1]   == 9)  minas++;
                      
                }
            } else if (i == tam-1){
                if (j == 0){
                    if (tabuleiro[i-1][j]   == 9)  minas++;
                    if (tabuleiro[i-1][j+1] == 9)  minas++;
                    if (tabuleiro[i][j+1]   == 9)  minas++;
                } else {
                    if (tabuleiro[i-1][j-1] == 9)  minas++;
                    if (tabuleiro[i-1][j]   == 9)  minas++;
                    if (tabuleiro[i-1][j+1] == 9)  minas++;
                    if (tabuleiro[i][j-1]   == 9)  minas++;
                    if (tabuleiro[i][j+1]   == 9)  minas++;
                }
            } else {
                if (j == 0){
                    if (tabuleiro[i-1][j+1] == 9)  minas++;
                    if (tabuleiro[i-1][j]   == 9)  minas++;
                    if (tabuleiro[i+1][j]   == 9)  minas++; 
                    if (tabuleiro[i+1][j+1] == 9)  minas++;
                    if (tabuleiro[i][j+1]   == 9)  minas++;
                       
                } else {
                    if (tabuleiro[i-1][j-1] == 9)  minas++;
                    if (tabuleiro[i-1][j]   == 9)  minas++;
                    if (tabuleiro[i-1][j+1] == 9)  minas++;
                    if (tabuleiro[i][j-1]   == 9)  minas++;
                    if (tabuleiro[i][j+1]   == 9)  minas++;
                    if (tabuleiro[i+1][j-1] == 9)  minas++;
                    if (tabuleiro[i+1][j]   == 9)  minas++;
                    if (tabuleiro[i+1][j+1] == 9)  minas++;
                }
            }
            tabuleiro[i][j] = minas;
            }
        }
    }   

    return 0;
}

int jogada(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int tam){

    return 0;
}

int checagem(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int tam){

    return 0;
}

int main(){

    srand(time(NULL));
    
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    inicializa_tabuleiro (tabuleiro, TAM_TABULEIRO);
    coloca_minas         (tabuleiro, TAM_TABULEIRO, QNT_MINAS);
    imprimir_tabuleiro   (tabuleiro, TAM_TABULEIRO);
    printf("\n\n");
    conta_minas          (tabuleiro, TAM_TABULEIRO);
    imprimir_tabuleiro   (tabuleiro, TAM_TABULEIRO);


    return 0;
}
