#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {0};
    int navioH[3]; // navio horizontal
    int navioV[3]; // navio vertical
    int navioD1[3]; // navio diagonal 1
    int navioD2[3]; // navio diagonal 2

    // Coordenadas iniciais
    int linhaH = 4, colunaH = 4;
    int linhaV = 6, colunaV = 6;
    int linhaD1 = 0, colunaD1 = 0;
    int linhaD2 = 0, colunaD2 = 9;

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

    // primeira diagonal
    for (int i = 0; i < 3; i++) {
        navioD1[i] = linhaD1 + i;
        tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
    }

    // segunda diagonal
    for (int i = 0; i < 3; i++) {
        navioD2[i] = linhaD2 + i;
        tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
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