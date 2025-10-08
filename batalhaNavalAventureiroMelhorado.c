#include <stdio.h>

// Função para iniciar o tabuleiro com água ('0')
void iniciarTabuleiro(char tabuleiro[10][10]) {

    // Inicializa o tabuleiro
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = '0'; // Representa água
        }
    }

}

// Posiciona o NavioA horizontalmente na primeira linha
void funcaoNavioA(char tabuleiro[10][10], char NavioA[3]) {
    // Função para posicionar o NavioA no tabuleiro
    // NavioA: começa na linha 0, coluna 0, tamanho 3
    if (0 + 3 > 10) {
        printf("NavioA fora dos limites!\n");
    } else {
        // Coloca o navioA no tabuleiro
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[0][i] == '0')// Verifica se a posição está livre
            {
                tabuleiro[0][i] = NavioA[i]; // Coloca o navio A no tabuleiro
            }else{
                printf("O NavioA não pode ser posicionado pois iria sobrepor outro navio!\n");
                break; // Sai do loop
                
            }
            
        }
    }
}

// Posiciona o NavioB verticalmente na terceira coluna
void funcaoNavioB(char tabuleiro[10][10], char NavioB[3]) {
    // Função para posicionar o NavioB no tabuleiro
    // NavioB: começa na linha 2, coluna 0, tamanho 3
    if (2 + 3 > 10) {
        printf("NavioB fora dos limites!\n");
    } else {
        // Coloca o navioB no tabuleiro
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[i + 2][0] == '0') // Verifica se a posição está livre
            {
                tabuleiro[i + 2][0] = NavioB[i]; // Coloca o navio B no tabuleiro
            }else{
                printf("O NavioB não pode ser posicionado pois iria sobrepor outro navio!\n");
                break; // Sai do loop
            }
            
        }
    }

}

// Posiciona o NavioC na diagonal principal (de cima para baixo)
void funcaoNavioC(char tabuleiro[10][10], char NavioC[3]) {

    // NavioC: começa em (2,2), tamanho 3
    if (2 + 3 > 10 || 2 + 3 > 10) {
        printf("NavioC fora dos limites!\n");
    } else {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[i + 2][i + 2] == '0') // Verifica se a posição está livre
            {
                tabuleiro[i + 2][i + 2] = NavioC[i]; // Coloca o navio C no tabuleiro
            }else{
                printf("O NavioC não pode ser posicionado pois iria sobrepor outro navio!\n");
                break; // Sai do loop
            }
        }
    }

}

// Posiciona o NavioD na diagonal secundária (de baixo para cima)
void funcaoNavioD(char tabuleiro[10][10], char NavioD[3]) {

    // NavioD: começa em (9,4), termina em (7,6), tamanho 3
    if (9 - 3 < -1 || 4 + 3 > 10) {
        printf("NavioD fora dos limites!\n");
    } else {
        int auxiliar = 4;// Variável auxiliar para controlar a coluna
        for (int i = 9; i > 6; i--){
            if (tabuleiro[i][auxiliar] == '0') // Verifica se a posição está livre
            {
                tabuleiro[i][auxiliar] = NavioD[9- i]; // Coloca o navio D no tabuleiro
                auxiliar++;
            }else{
                printf("O NavioD não pode ser posicionado pois iria sobrepor outro navio!\n");
                break; // Sai do loop
            }
            
        }
    }

}


int main () {

    // Declaração do tabuleiro 10x10 e variáveis auxiliares
    char tabuleiro[10][10];
    

    char NavioA[3] = {'3', '3', '3'}; // Representa um navio
    char NavioB[3] = {'3', '3', '3'}; // Representa mais um navio
    char NavioC[3] = {'3', '3', '3'}; // Representa mais um navio
    char NavioD[3] = {'3', '3', '3'}; // Representa mais um navio

    iniciarTabuleiro(tabuleiro);

    funcaoNavioA(tabuleiro, NavioA);
    funcaoNavioB(tabuleiro, NavioB);
    funcaoNavioC(tabuleiro, NavioC);
    funcaoNavioD(tabuleiro, NavioD);

    // Imprime o tabuleiro
    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

 return 0;
}


