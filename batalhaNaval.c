#include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3

// Função para imprimir o tabuleiro
void exibir_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se é possível posicionar o navio sem sobreposição e dentro do tabuleiro
int pode_posicionar_navio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int nova_linha = linha + (direcao == 0 ? i : 0);    // Direção horizontal ou vertical
        int nova_coluna = coluna + (direcao == 1 ? i : 0);  // Direção horizontal ou vertical

        if (diagonal) {
            nova_linha = linha + i;
            nova_coluna = coluna + i;
        }

        if (nova_linha >= TAMANHO || nova_coluna >= TAMANHO || tabuleiro[nova_linha][nova_coluna] != 0) {
            return 0;
        }
    }
    return 1;
}

// Função para posicionar o navio
void posicionar_navio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int nova_linha = linha + (direcao == 0 ? i : 0);
        int nova_coluna = coluna + (direcao == 1 ? i : 0);

        if (diagonal) {
            nova_linha = linha + i;
            nova_coluna = coluna + i;
        }

        tabuleiro[nova_linha][nova_coluna] = 3;
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};  // Inicializa todas as posições com 0 (água)

    // Coordenadas e direções fixas para os navios
    int coordenadas_navios[4][3] = {
        {0, 0, 0}, // Navio 1: Horizontal
        {2, 5, 1}, // Navio 2: Vertical
        {4, 0, 0}, // Navio 3: Diagonal principal
        {7, 9 - TAMANHO_NAVIO + 1, 0}  // Navio 4: Diagonal inversa
    };

    // Posicionando os dois primeiros navios (horizontais e verticais)
    for (int i = 0; i < 2; i++) {
        int linha = coordenadas_navios[i][0];
        int coluna = coordenadas_navios[i][1];
        int direcao = coordenadas_navios[i][2];

        if (pode_posicionar_navio(tabuleiro, linha, coluna, direcao, 0)) {
            posicionar_navio(tabuleiro, linha, coluna, direcao, 0);
        }
    }

    // Posicionando os dois navios diagonais
    for (int i = 2; i < 4; i++) {
        int linha = coordenadas_navios[i][0];
        int coluna = coordenadas_navios[i][1];

        if (pode_posicionar_navio(tabuleiro, linha, coluna, 0, 1)) {
            posicionar_navio(tabuleiro, linha, coluna, 0, 1);
        }
    }

    // Exibindo o tabuleiro
    exibir_tabuleiro(tabuleiro);

    return 0;
}
