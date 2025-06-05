#include <stdio.h>

int main() {
    int i, j;

    // Criação do tabuleiro 10x10 com água 0
    int tabuleiro[10][10] = {0};

    // Colocando navio horizontal linha 2, colunas 4 a 6
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;
    tabuleiro[2][6] = 3;

    // Colocando navio vertical coluna 7, linhas 5 a 7
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;

    // Exibindo o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}