#include <stdio.h>

void main () {

    char tabuleiro[10][10];
    int i, j, p, k, L, M;

    char NavioA[3] = {'3', '3', '3'}; // Representa um navio
    char NavioB[4] = {'3', '3', '3', '3'}; // Representa outro navio


    // Inicializa o tabuleiro
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = '0'; // Representa água
        }
    }

    
    for (p = 0; p < 3; p++) {
        tabuleiro[1][p + 1] = NavioA[j]; // Coloca o navio A no tabuleiro
    }

    for (k = 0; k < 4; k++) {
        tabuleiro[k + 1][7] = NavioB[k]; // Coloca o navio B no tabuleiro
    } 
    
/* 
    //colocando os navios no tabuleiro
    tabuleiro[1][1] = '3'; // Coloca o navio A no tabuleiro
    tabuleiro[1][2] = '3'; // Coloca o navio A no tabuleiro
    tabuleiro[1][3] = '3'; // Coloca o navio A no tabuleiro

    tabuleiro[1][8] = '3'; // Coloca o navio B no tabuleiro
    tabuleiro[2][8] = '3'; // Coloca o navio B no tabuleiro
    tabuleiro[3][8] = '3'; // Coloca o navio B no tabuleiro
    tabuleiro[4][8] = '3'; // Coloca o navio B no tabuleiro
 */


    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    for (L = 0; L < 10; L++) {
        for (M = 0; M < 10; M++) {
            printf("%c ", tabuleiro[L][M]);
        }
        printf("\n");
    }


}
