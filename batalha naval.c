#include <stdio.h>

// Definição do tamanho do tabuleiro usando uma macro (constante)
#define TAMANHO 10

// Protótipos das funções
void inicializar_tabuleiro(char tabuleiro[TAMANHO][TAMANHO]);
void posicionar_navios(char tabuleiro[TAMANHO][TAMANHO]);
void exibir_tabuleiro(char tabuleiro[TAMANHO][TAMANHO]);
void simular_ataque_especial(char tabuleiro[TAMANHO][TAMANHO], int centro_linha, int centro_coluna);

int main() {
    // 1. Representação do Tabuleiro (Matriz/Vetores)
    // A matriz armazena o estado de cada célula: 'A' (Água), 'N' (Navio)
    char tabuleiro[TAMANHO][TAMANHO];

    printf("🚢 Batalha Naval Simplificado em C 🚢\n\n");

    // Preenche o tabuleiro com água
    inicializar_tabuleiro(tabuleiro);
    
    // Posiciona navios
    posicionar_navios(tabuleiro);

    printf("--- Tabuleiro Inicial ---\n");
    exibir_tabuleiro(tabuleiro);

    // Ponto central para a simulação do ataque especial (área 3x3)
    int centro_ataque_linha = 4;
    int centro_ataque_coluna = 4;
    
    printf("\n💥 Simulação de Ataque Especial (Area 3x3 centrada em [%d, %d]) 💥\n", 
           centro_ataque_linha, centro_ataque_coluna);

    // Chamada da função que contém a lógica dos loops e condicionais aninhadas
    simular_ataque_especial(tabuleiro, centro_ataque_linha, centro_ataque_coluna);
    
    printf("\n--- Tabuleiro Após Ataque Especial ---\n");
    exibir_tabuleiro(tabuleiro);

    return 0;
}

// Inicializa a matriz (tabuleiro) com 'A' (Água)
void inicializar_tabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    // 2. Aplicação de Loops Aninhados para Percorrer a Matriz
    for (int i = 0; i < TAMANHO; i++) {       // Loop para Linhas
        for (int j = 0; j < TAMANHO; j++) {   // Loop para Colunas
            tabuleiro[i][j] = 'A'; // Inicializa a célula com Água
        }
    }
}

// Posiciona navios no tabuleiro ('N')
void posicionar_navios(char tabuleiro[TAMANHO][TAMANHO]) {
    // Navio 1: Horizontal
    tabuleiro[3][2] = 'N';
    tabuleiro[3][3] = 'N';
    tabuleiro[3][4] = 'N';

    // Navio 2: Vertical (algumas posições propositalmente dentro da área de efeito 3x3)
    tabuleiro[4][5] = 'N'; 
    tabuleiro[5][5] = 'N'; // Posição que será atingida pelo ataque (5, 5)
    tabuleiro[6][5] = 'N'; 
}

// Exibe o tabuleiro no console
void exibir_tabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    // Exibe índices das colunas
    printf("  ");
    for (int j = 0; j < TAMANHO; j++) {
        printf(" %d", j);
    }
    printf("\n");
    printf("  ----------------------------------\n");

    // 2. Aplicação de Loops Aninhados para Exibição
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d |", i); // Exibe índice da linha
        for (int j = 0; j < TAMANHO; j++) {
            printf(" %c", tabuleiro[i][j]); // Exibe o conteúdo da célula
        }
        printf(" |\n");
    }
    printf("  ----------------------------------\n");
}

// Simula uma área de efeito 3x3 (ataque especial)
void simular_ataque_especial(char tabuleiro[TAMANHO][TAMANHO], int centro_linha, int centro_coluna) {
    // A área de efeito vai de (centro - 1) até (centro + 1)
    
    // 2. Aplicação de Loops Aninhados para a Área de Efeito
    for (int i = centro_linha - 1; i <= centro_linha + 1; i++) { // Linhas da área (3)
        for (int j = centro_coluna - 1; j <= centro_coluna + 1; j++) { // Colunas da área (3)
            
            // 3. Aplicação de Condicionais (if/else)
            // 1) Verifica se a coordenada está DENTRO dos limites válidos do tabuleiro
            if (i >= 0 && i < TAMANHO && j >= 0 && j < TAMANHO) {
                
                // 2) Verifica o conteúdo da célula para simular o resultado do ataque
                if (tabuleiro[i][j] == 'N') {
                    tabuleiro[i][j] = 'X'; // 'X' para Acerto (Hit)
                    printf("  Acerto em [%d, %d]! (Navio atingido)\n", i, j);
                } 
                else if (tabuleiro[i][j] == 'A') {
                    tabuleiro[i][j] = 'O'; // 'O' para Erro (Miss)
                    printf("  Erro em [%d, %d]. (Água)\n", i, j);
                }
                // Se já for 'X' ou 'O', a célula é ignorada
            } else {
                printf("  Coordenada [%d, %d] fora dos limites do tabuleiro. Ignorada.\n", i, j);
            }
        }
    }
}
