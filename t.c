#include <stdio.h>

// Função simples para calcular valor absoluto de um número inteiro
int valor_absoluto(int x) {
    if (x < 0)
        return -x;
    else
        return x;
}

int main() {
    int tamanhoTabuleiro = 10;
    int tamanhoHabilidade = 5;

    int tabuleiro[10][10] = {0};

    // Colocar navios
    int linhaNavioH = 4;
    int colunaNavioH = 4;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaNavioH][colunaNavioH + i] = 3;
    }

    int linhaNavioV = 6;
    int colunaNavioV = 6;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaNavioV + i][colunaNavioV] = 3;
    }

    for (int i = 0; i < 3; i++) {
        tabuleiro[i][i] = 3;
    }

    for (int i = 0; i < 3; i++) {
        tabuleiro[i][9 - i] = 3;
    }

    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // Matriz cone
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i <= 2 && j >= 2 - i && j <= 2 + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // Matriz cruz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // Matriz octaedro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int distancia = valor_absoluto(i - 2) + valor_absoluto(j - 2);
            if (distancia <= 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    int origemLinha, origemColuna;
    int offset = 2;

    // Aplicar cone no (2,2)
    origemLinha = 2;
    origemColuna = 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] == 1) {
                int linha = origemLinha - offset + i;
                int coluna = origemColuna - offset + j;
                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                    if (tabuleiro[linha][coluna] == 0) {
                        tabuleiro[linha][coluna] = 5;
                    }
                }
            }
        }
    }

    // Aplicar cruz no (5,5)
    origemLinha = 5;
    origemColuna = 5;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) {
                int linha = origemLinha - offset + i;
                int coluna = origemColuna - offset + j;
                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                    if (tabuleiro[linha][coluna] == 0) {
                        tabuleiro[linha][coluna] = 5;
                    }
                }
            }
        }
    }

    // Aplicar octaedro no (7,7)
    origemLinha = 7;
    origemColuna = 7;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1) {
                int linha = origemLinha - offset + i;
                int coluna = origemColuna - offset + j;
                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                    if (tabuleiro[linha][coluna] == 0) {
                        tabuleiro[linha][coluna] = 5;
                    }
                }
            }
        }
    }

    // Mostrar tabuleiro
    printf("Legenda: 0=agua, 3=navio, 5=habilidade\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}