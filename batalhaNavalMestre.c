#include <stdio.h>
#include <stdlib.h>

#define LINHAS 10
#define COLUNAS 10
#define HAB_SIZE 5   // tamanho das matrizes de habilidade (5x5)
#define HAB_MARK '5' // caractere para marcar área afetada

// Inicia o tabuleiro com '0' (água)
void iniciarTabuleiro(char tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++)
        for (int j = 0; j < COLUNAS; j++)
            tabuleiro[i][j] = '0';
}

// Posiciona navios (mantive suas funções para clareza)
void funcaoNavioA(char tabuleiro[LINHAS][COLUNAS], char NavioA[3]) {
    if (0 + 3 > LINHAS) {
        printf("NavioA fora dos limites!\n");
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == '0') tabuleiro[0][i] = NavioA[i];
        else { printf("O NavioA não pode ser posicionado pois iria sobrepor outro navio!\n"); break; }
    }
}

void funcaoNavioB(char tabuleiro[LINHAS][COLUNAS], char NavioB[3]) {
    if (2 + 3 > LINHAS) {
        printf("NavioB fora dos limites!\n");
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i + 2][0] == '0') tabuleiro[i + 2][0] = NavioB[i];
        else { printf("O NavioB não pode ser posicionado pois iria sobrepor outro navio!\n"); break; }
    }
}

void funcaoNavioC(char tabuleiro[LINHAS][COLUNAS], char NavioC[3]) {
    if (2 + 3 > LINHAS || 2 + 3 > COLUNAS) {
        printf("NavioC fora dos limites!\n");
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i + 2][i + 2] == '0') tabuleiro[i + 2][i + 2] = NavioC[i];
        else { printf("O NavioC não pode ser posicionado pois iria sobrepor outro navio!\n"); break; }
    }
}

void funcaoNavioD(char tabuleiro[LINHAS][COLUNAS], char NavioD[3]) {
    // NavioD: começa em (9,4) e sobe diagonalmente (9,4),(8,5),(7,6)
    if (9 - (3 - 1) < 0 || 4 + (3 - 1) >= COLUNAS) {
        printf("NavioD fora dos limites!\n");
        return;
    }
    int aux = 4;
    for (int i = 9; i > 6; i--) {
        if (tabuleiro[i][aux] == '0') {
            tabuleiro[i][aux] = NavioD[9 - i];
            aux++;
        } else { printf("O NavioD não pode ser posicionado pois iria sobrepor outro navio!\n"); break; }
    }
}

// Constroi a matriz de habilidade "cone" (aponta para baixo).
// Regra simples: a partir do topo (linha 0 da matriz), a largura cresce até um limite.
void construirCone(int cone[HAB_SIZE][HAB_SIZE]) {
    int center = HAB_SIZE / 2;
    for (int i = 0; i < HAB_SIZE; i++) {
        for (int j = 0; j < HAB_SIZE; j++) {
            int level = i;                 // quanto mais baixo, maior o alcance
            int maxWidth = (level <= center) ? level : center; // limita o crescimento
            if (abs(j - center) <= maxWidth) cone[i][j] = 1;
            else cone[i][j] = 0;
        }
    }
}

// Constroi a matriz de habilidade "cruz" (linha e coluna passando pelo centro)
void construirCruz(int cruz[HAB_SIZE][HAB_SIZE]) {
    int center = HAB_SIZE / 2;
    for (int i = 0; i < HAB_SIZE; i++)
        for (int j = 0; j < HAB_SIZE; j++)
            cruz[i][j] = (i == center || j == center) ? 1 : 0;
}

// Constroi a matriz "octaedro" vista frontal (losango/diamond): |dr|+|dc| <= radius
void construirOctaedro(int octa[HAB_SIZE][HAB_SIZE]) {
    int center = HAB_SIZE / 2;
    int radius = center;
    for (int i = 0; i < HAB_SIZE; i++) {
        for (int j = 0; j < HAB_SIZE; j++) {
            if (abs(i - center) + abs(j - center) <= radius) octa[i][j] = 1;
            else octa[i][j] = 0;
        }
    }
}

// Sobrepõe a matriz de habilidade ao tabuleiro centrando-a em (origemLinha, origemColuna).
// Marca com 'marca' apenas posições dentro dos limites do tabuleiro.
// Não sobrescreve navios ('3') — só marca água ('0') para manter visual de navios.
void aplicarHabilidade(char tab[LINHAS][COLUNAS], int hab[HAB_SIZE][HAB_SIZE],
                       int origemLinha, int origemColuna, char marca) {
    int center = HAB_SIZE / 2;
    for (int i = 0; i < HAB_SIZE; i++) {
        for (int j = 0; j < HAB_SIZE; j++) {
            if (hab[i][j] != 1) continue;
            int br = origemLinha - center + i;
            int bc = origemColuna - center + j;
            if (br >= 0 && br < LINHAS && bc >= 0 && bc < COLUNAS) {
                if (tab[br][bc] == '0') tab[br][bc] = marca;
                // se já for navio '3', mantemos '3' (opcional: poderia marcar também)
            }
        }
    }
}

int main() {
    char tabuleiro[LINHAS][COLUNAS];
    char NavioA[3] = {'3','3','3'};
    char NavioB[3] = {'3','3','3'};
    char NavioC[3] = {'3','3','3'};
    char NavioD[3] = {'3','3','3'};

    // inicializa tabuleiro e posiciona navios
    iniciarTabuleiro(tabuleiro);
    funcaoNavioA(tabuleiro, NavioA);
    funcaoNavioB(tabuleiro, NavioB);
    funcaoNavioC(tabuleiro, NavioC);
    funcaoNavioD(tabuleiro, NavioD);

    // constrói as matrizes de habilidade (5x5)
    int cone[HAB_SIZE][HAB_SIZE];
    int cruz[HAB_SIZE][HAB_SIZE];
    int octa[HAB_SIZE][HAB_SIZE];
    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octa);

    // Define pontos de origem (linha, coluna) para cada habilidade no tabuleiro
    // (você pode mudar esses valores manualmente para testar)
    int origemConeLinha = 1, origemConeColuna = 4;   // exemplo: cone perto do topo
    int origemCruzLinha = 5, origemCruzColuna = 2;   // exemplo: cruz no meio-esquerda
    int origemOctaLinha = 7, origemOctaColuna = 7;   // exemplo: octaedro no canto inferior-direito

    // Aplica habilidades ao tabuleiro (marca '5' nas posições afetadas)
    aplicarHabilidade(tabuleiro, cone, origemConeLinha, origemConeColuna, HAB_MARK);
    aplicarHabilidade(tabuleiro, cruz, origemCruzLinha, origemCruzColuna, HAB_MARK);
    aplicarHabilidade(tabuleiro, octa, origemOctaLinha, origemOctaColuna, HAB_MARK);

    // Exibe o tabuleiro: 0 = água, 3 = navio, 5 = área afetada
    printf("Tabuleiro com habilidades (0=agua,3=navio,5=area afetada):\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}