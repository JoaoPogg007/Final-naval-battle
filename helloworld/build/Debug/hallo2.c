#include <stdio.h>

int main() {

    // =========================
    // TABULEIRO PRINCIPAL
    // =========================

    int tabuleiro[10][10];

    // Inicializa tudo com água
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // =========================
    // NAVIOS
    // =========================

    // Horizontal
    for(int j = 2; j < 5; j++) {
        tabuleiro[1][j] = 3;
    }

    // Vertical
    for(int i = 4; i < 7; i++) {
        tabuleiro[i][7] = 3;
    }

    // =========================
    // MATRIZES DAS HABILIDADES
    // =========================

    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // Inicializa tudo com 0
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {

            cone[i][j] = 0;
            cruz[i][j] = 0;
            octaedro[i][j] = 0;
        }
    }

    // =========================
    // HABILIDADE CONE
    // =========================

    for(int i = 0; i < 3; i++) {

        for(int j = 0; j < 5; j++) {

            if(j >= 2 - i && j <= 2 + i) {
                cone[i][j] = 1;
            }
        }
    }

    // =========================
    // HABILIDADE CRUZ
    // =========================

    for(int i = 0; i < 5; i++) {

        for(int j = 0; j < 5; j++) {

            if(i == 2 || j == 2) {
                cruz[i][j] = 1;
            }
        }
    }

    // =========================
    // HABILIDADE OCTAEDRO
    // =========================

    for(int i = 0; i < 5; i++) {

        for(int j = 0; j < 5; j++) {

            if((i + j >= 2) &&
               (i + j <= 6) &&
               (i - j <= 2) &&
               (j - i <= 2)) {

                octaedro[i][j] = 1;
            }
        }
    }

    // =========================
    // POSIÇÕES DAS HABILIDADES
    // =========================

    int origemConeLinha = 2;
    int origemConeColuna = 2;

    int origemCruzLinha = 6;
    int origemCruzColuna = 2;

    int origemOctLinha = 6;
    int origemOctColuna = 6;

    // =========================
    // SOBREPOR CONE
    // =========================

    for(int i = 0; i < 5; i++) {

        for(int j = 0; j < 5; j++) {

            int linhaTabuleiro =
            origemConeLinha + i - 2;

            int colunaTabuleiro =
            origemConeColuna + j - 2;

            if(linhaTabuleiro >= 0 &&
               linhaTabuleiro < 10 &&
               colunaTabuleiro >= 0 &&
               colunaTabuleiro < 10) {

                if(cone[i][j] == 1 &&
                   tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {

                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }

    // =========================
    // SOBREPOR CRUZ
    // =========================

    for(int i = 0; i < 5; i++) {

        for(int j = 0; j < 5; j++) {

            int linhaTabuleiro =
            origemCruzLinha + i - 2;

            int colunaTabuleiro =
            origemCruzColuna + j - 2;

            if(linhaTabuleiro >= 0 &&
               linhaTabuleiro < 10 &&
               colunaTabuleiro >= 0 &&
               colunaTabuleiro < 10) {

                if(cruz[i][j] == 1 &&
                   tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {

                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }

    // =========================
    // SOBREPOR OCTAEDRO
    // =========================

    for(int i = 0; i < 5; i++) {

        for(int j = 0; j < 5; j++) {

            int linhaTabuleiro =
            origemOctLinha + i - 2;

            int colunaTabuleiro =
            origemOctColuna + j - 2;

            if(linhaTabuleiro >= 0 &&
               linhaTabuleiro < 10 &&
               colunaTabuleiro >= 0 &&
               colunaTabuleiro < 10) {

                if(octaedro[i][j] == 1 &&
                   tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {

                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }

    // =========================
    // EXIBIR TABULEIRO
    // =========================

    printf("\nTABULEIRO FINAL\n\n");

    for(int i = 0; i < 10; i++) {

        for(int j = 0; j < 10; j++) {

            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }

    return 0;
}