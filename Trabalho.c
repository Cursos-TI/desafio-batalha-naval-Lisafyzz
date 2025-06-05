#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {0};
    int navioH[3]; // navio horizontal
    int navioV[3]; // navio vertical

    // Coordenadas iniciais
    int linhaH = 2, colunaH = 4;
    int linhaV = 5, colunaV = 6;

    // Preenche navio horizontal
    for (int i = 0; i < 3; i++) {
        navioH[i] = colunaH + i;
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    // Preenche navio vertical
    for (int i = 0; i < 3; i++) {
        navioV[i] = linhaV + i;
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // Exibe o tabuleiro
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}