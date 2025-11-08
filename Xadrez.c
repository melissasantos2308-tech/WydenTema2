#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Tamanho do tabuleiro
#define TAMANHO 8

// Protótipos das funções
void mostrar_tabuleiro(int linha_peca, int coluna_peca, char peca);
int posicao_valida(int linha, int coluna);
void movimentos_torre(int linha, int coluna);
void movimentos_bispo(int linha, int coluna);
void movimentos_cavalo(int linha, int coluna);

// -------------------------------------------------------------------
// FUNÇÃO PRINCIPAL
// -------------------------------------------------------------------

int main() {
    char escolha_peca;
    char pos_char[3];
    int linha_inicial, coluna_inicial;
    int entrada_valida = 0;

    printf("♟️ Simulador de Movimentos de Peças de Xadrez em C ♟️\n");
    printf("==================================================\n");

    // Loop do-while para garantir uma entrada de peça válida
    do {
        printf("\nEscolha a peça (T - Torre, B - Bispo, C - Cavalo): ");
        if (scanf(" %c", &escolha_peca) != 1) {
            // Limpa o buffer de entrada em caso de falha na leitura
            while (getchar() != '\n');
            continue;
        }
        escolha_peca = toupper(escolha_peca); // Converte para maiúscula

        if (escolha_peca == 'T' || escolha_peca == 'B' || escolha_peca == 'C') {
            entrada_valida = 1;
        } else {
            printf("Erro: Peça inválida. Tente novamente.\n");
        }
    } while (entrada_valida == 0);

    entrada_valida = 0;
    // Loop while para garantir uma entrada de posição válida
    while (entrada_valida == 0) {
        printf("Digite a posição inicial (ex: a1, h8): ");
        if (scanf("%s", pos_char) != 1) {
            while (getchar() != '\n');
            continue;
        }
        
        // Valida e converte a posição: 'a1' -> (7, 0)
        if (pos_char[0] >= 'a' && pos_char[0] <= 'h' && 
            pos_char[1] >= '1' && pos_char[1] <= '8' && 
            pos_char[2] == '\0') 
        {
            coluna_inicial = pos_char[0] - 'a'; // 'a' -> 0, 'h' -> 7
            linha_inicial = '8' - pos_char[1];  // '1' -> 7, '8' -> 0
            entrada_valida = 1;
        } else {
            printf("Erro: Posição inválida. Use o formato 'letraNumero' (ex: d4).\n");
        }
    }
    
    // Mostra a posição inicial no tabuleiro
    printf("\n--- Posição Inicial ---\n");
    mostrar_tabuleiro(linha_inicial, coluna_inicial, escolha_peca);
    printf("Posição: %c%c\n", 'a' + coluna_inicial, '8' - linha_inicial);

    // Chama a função de movimento apropriada
    printf("\n--- Movimentos Válidos ---\n");
    switch (escolha_peca) {
        case 'T':
            movimentos_torre(linha_inicial, coluna_inicial);
            break;
        case 'B':
            movimentos_bispo(linha_inicial, coluna_inicial);
            break;
        case 'C':
            movimentos_cavalo(linha_inicial, coluna_inicial);
            break;
    }

    return 0;
}

// -------------------------------------------------------------------
// FUNÇÕES AUXILIARES
// -------------------------------------------------------------------

// Verifica se a posição (linha, coluna) está dentro dos limites do tabuleiro
int posicao_valida(int linha, int coluna) {
    return (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO);
}

// Função para mostrar o tabuleiro com a peça na posição inicial
void mostrar_tabuleiro(int linha_peca, int coluna_peca, char peca) {
    printf("  ");
    // Laço 'for' para imprimir as colunas (A-H)
    for (int j = 0; j < TAMANHO; j++) {
        printf(" %c", 'a' + j);
    }
    printf("\n");
    
    // Laço 'for' para as linhas (8-1)
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", '8' - i); // Número da linha (8 a 1)
        // Laço 'for' para as colunas
        for (int j = 0; j < TAMANHO; j++) {
            if (i == linha_peca && j == coluna_peca) {
                printf("|%c", peca); // Posição da peça
            } else {
                // Alterna ' ' e '.' para o visual do tabuleiro
                if ((i + j) % 2 == 0) {
                    printf("| ");
                } else {
                    printf("|.");
                }
            }
        }
        printf("|\n");
    }
}

// -------------------------------------------------------------------
// FUNÇÕES DE MOVIMENTO COM ESTRUTURAS DE REPETIÇÃO
// -------------------------------------------------------------------

/**
 * 🏰 Movimento da Torre
 * A Torre se move na horizontal e vertical (4 direções).
 * Uso: Laços 'for' para cada direção.
 */
void movimentos_torre(int linha, int coluna) {
    int count = 0;
    
    printf("Movimentos (Horizontal/Vertical) usando 4 laços 'for':\n");

    // 1. Horizontal para a DIREITA (coluna crescente)
    for (int c = coluna + 1; c < TAMANHO; c++) {
        printf("  %c%d ", 'a' + c, '8' - linha);
        count++;
    }

    // 2. Horizontal para a ESQUERDA (coluna decrescente)
    for (int c = coluna - 1; c >= 0; c--) {
        printf("  %c%d ", 'a' + c, '8' - linha);
        count++;
    }
    
    // 3. Vertical para CIMA (linha decrescente)
    for (int l = linha - 1; l >= 0; l--) {
        printf("  %c%d ", 'a' + coluna, '8' - l);
        count++;
    }

    // 4. Vertical para BAIXO (linha crescente)
    for (int l = linha + 1; l < TAMANHO; l++) {
        printf("  %c%d ", 'a' + coluna, '8' - l);
        count++;
    }
    
    if (count == 0) printf("Nenhum movimento válido.\n");
    printf("\nTotal de %d movimentos potenciais (sem considerar bloqueio).\n", count);
}

/**
 * ♝ Movimento do Bispo
 * O Bispo se move nas diagonais (4 direções).
 * Uso: Laço 'while' para cada direção.
 */
void movimentos_bispo(int linha, int coluna) {
    int dl, dc, count = 0;
    
    printf("Movimentos (Diagonal) usando 4 laços 'while':\n");

    // 1. Diagonal CIMA-DIREITA (linha decrescente, coluna crescente)
    dl = linha - 1; dc = coluna + 1;
    while (posicao_valida(dl, dc)) {
        printf("  %c%d ", 'a' + dc, '8' - dl);
        dl--; dc++;
        count++;
    }

    // 2. Diagonal CIMA-ESQUERDA (linha decrescente, coluna decrescente)
    dl = linha - 1; dc = coluna - 1;
    while (posicao_valida(dl, dc)) {
        printf("  %c%d ", 'a' + dc, '8' - dl);
        dl--; dc--;
        count++;
    }

    // 3. Diagonal BAIXO-DIREITA (linha crescente, coluna crescente)
    dl = linha + 1; dc = coluna + 1;
    while (posicao_valida(dl, dc)) {
        printf("  %c%d ", 'a' + dc, '8' - dl);
        dl++; dc++;
        count++;
    }

    // 4. Diagonal BAIXO-ESQUERDA (linha crescente, coluna decrescente)
    dl = linha + 1; dc = coluna - 1;
    while (posicao_valida(dl, dc)) {
        printf("  %c%d ", 'a' + dc, '8' - dl);
        dl++; dc--;
        count++;
    }
    
    if (count == 0) printf("Nenhum movimento válido.\n");
    printf("\nTotal de %d movimentos potenciais (sem considerar bloqueio).\n", count);
}

/**
 * ♞ Movimento do Cavalo
 * O Cavalo tem 8 movimentos fixos em 'L'.
 * Uso: Laço 'for' para iterar sobre 8 deslocamentos fixos.
 */
void movimentos_cavalo(int linha, int coluna) {
    // 8 possíveis deslocamentos do Cavalo (diferença de linha, diferença de coluna)
    // O array dl e dc armazena os pares (dl[i], dc[i])
    const int dl[] = {-2, -2, -1, -1, 1, 1, 2, 2}; // Deslocamentos de linha
    const int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1}; // Deslocamentos de coluna
    int nova_linha, nova_coluna;
    int count = 0;
    
    printf("Movimentos (8 posições fixas) usando laço 'for' para iterar os deslocamentos:\n");

    // O laço 'for' itera sobre os 8 movimentos possíveis
    for (int i = 0; i < 8; i++) {
        nova_linha = linha + dl[i];
        nova_coluna = coluna + dc[i];

        // Verifica se a nova posição está dentro do tabuleiro
        if (posicao_valida(nova_linha, nova_coluna)) {
            printf("  %c%d ", 'a' + nova_coluna, '8' - nova_linha);
            count++;
        }
    }

    if (count == 0) printf("Nenhum movimento válido.\n");
    printf("\nTotal de %d movimentos válidos.\n", count);
}
