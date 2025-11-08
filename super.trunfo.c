#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura da Carta
typedef struct {
    char nome[50];
    int velocidade;
    int potencia;
    int peso;
} Carta;

// Protótipos das funções
void mostrar_carta(const char *titulo, Carta c);
void desafio_1_comparacao_simples(Carta c1, Carta c2);
void desafio_2_multiplos_atributos(Carta c1, Carta c2);
void desafio_3_operador_ternario(Carta c1, Carta c2);

// -------------------------------------------------------------------
// FUNÇÃO PRINCIPAL
// -------------------------------------------------------------------

int main() {
    // Inicialização das cartas para o jogo
    // (Valores escolhidos para ilustrar os diferentes resultados)
    Carta carta_jogador = {"F-1 Raptor", 300, 850, 2000};
    Carta carta_cpu = {"F-22 Lightning", 320, 900, 1800}; // Cuidado: Peso menor é melhor no Desafio 3!

    // Imprime as cartas para o jogador
    printf("🃏 Simulador de Super Trunfo em C 🃏\n");
    printf("======================================\n\n");
    mostrar_carta("Sua Carta (Jogador)", carta_jogador);
    mostrar_carta("Carta do Oponente (CPU)", carta_cpu);
    
    // --- DESAFIO 1: Comparação Simples (if/if-else) ---
    printf("\n--- 1. DESAFIO: Comparação Simples (Velocidade) ---\n");
    desafio_1_comparacao_simples(carta_jogador, carta_cpu);

    // --- DESAFIO 2: Múltiplos Atributos (if-else if / switch) ---
    printf("\n\n--- 2. DESAFIO: Múltiplos Atributos com Menus ---\n");
    desafio_2_multiplos_atributos(carta_jogador, carta_cpu);

    // --- DESAFIO 3: Operador Ternário e Lógica Complexa ---
    printf("\n\n--- 3. DESAFIO: Lógica Complexa (Potência e Peso) ---\n");
    desafio_3_operador_ternario(carta_jogador, carta_cpu);

    printf("\nFim da Simulação. Obrigado por jogar!\n");
    
    return 0;
}

// -------------------------------------------------------------------
// FUNÇÕES AUXILIARES
// -------------------------------------------------------------------

void mostrar_carta(const char *titulo, Carta c) {
    printf("**%s**:\n", titulo);
    printf("  Nome: %s\n", c.nome);
    printf("  [1] Velocidade (km/h): %d\n", c.velocidade);
    printf("  [2] Potência (HP): %d\n", c.potencia);
    printf("  [3] Peso (kg): %d\n", c.peso);
    printf("--------------------------------------\n");
}

// -------------------------------------------------------------------
// DESAFIO 1: Comparação de cartas com base em um único atributo (Velocidade)
// Requisito: Utilizar 'if' e 'if-else'.
// -------------------------------------------------------------------
void desafio_1_comparacao_simples(Carta c1, Carta c2) {
    printf("Regra: Comparar apenas o atributo VELOCIDADE.\n");
    
    // Comparação usando apenas 'if'
    if (c1.velocidade > c2.velocidade) {
        printf("RESULTADO (IF): 🏆 Jogador Venceu! Velocidade: %d > %d\n", 
               c1.velocidade, c2.velocidade);
    }
    
    // Comparação usando 'if-else' (para o caso de empate ou derrota)
    if (c1.velocidade <= c2.velocidade) {
        printf("RESULTADO (IF-ELSE): 🙁 Jogador Perdeu/Empatou. Velocidade: %d <= %d\n", 
               c1.velocidade, c2.velocidade);
    } 
}

// -------------------------------------------------------------------
// DESAFIO 2: Comparação de cartas com múltiplos atributos
// Requisitos: Operadores lógicos, estruturas de decisão aninhadas/encadeadas, menu com 'switch'.
// -------------------------------------------------------------------
void desafio_2_multiplos_atributos(Carta c1, Carta c2) {
    int escolha;
    int valor1, valor2;
    char atributo[15];

    printf("Escolha o atributo para a rodada (1-Velocidade, 2-Potência, 3-Peso):\n");
    printf("Sua escolha: ");
    
    if (scanf("%d", &escolha) != 1) {
        printf("Entrada inválida. Usando Potência por padrão.\n");
        escolha = 2; // Default
        while(getchar() != '\n'); // Limpa buffer
    }

    // Estrutura 'switch' para definir o atributo e seus valores
    switch (escolha) {
        case 1:
            valor1 = c1.velocidade;
            valor2 = c2.velocidade;
            strcpy(atributo, "Velocidade");
            break;
        case 2:
            valor1 = c1.potencia;
            valor2 = c2.potencia;
            strcpy(atributo, "Potência");
            break;
        case 3:
            valor1 = c1.peso;
            valor2 = c2.peso;
            strcpy(atributo, "Peso");
            break;
        default:
            printf("Opção inválida. Usando Potência por padrão.\n");
            valor1 = c1.potencia;
            valor2 = c2.potencia;
            strcpy(atributo, "Potência");
            break;
    }
    
    printf("\nComparando por **%s** (%d vs %d):\n", atributo, valor1, valor2);

    // Estrutura de decisão encadeada (if-else if)
    if (valor1 > valor2) {
        printf("RESULTADO (if-else if): 🥇 Jogador VENCEU! Seu valor é MAIOR.\n");
        
    } else if (valor1 < valor2) {
        printf("RESULTADO (if-else if): 💀 Jogador PERDEU! Seu valor é MENOR.\n");
        
    } else { // Caso valor1 == valor2
        printf("RESULTADO (if-else if): 🤝 Empate! Ninguém pontuou.\n");
    }
    
    // Exemplo de Estrutura Aninhada e Operador Lógico '&&'
    if (valor1 > valor2) {
        // Vencedor: c1
        if (c1.potencia > 800 && c1.peso < 2000) { 
            printf("BÔNUS (Aninhado e Lógico): A carta vencedora é de ALTA performance (Potência > 800 E Peso < 2000).\n");
        }
    }
}

// -------------------------------------------------------------------
// DESAFIO 3: Comparação de cartas com base em dois atributos
// Requisitos: Operador ternário e lógica complexa.
// Regra Complexa: Vence quem tiver MAIOR Potência, MAS se a Potência for igual,
// vence quem tiver MENOR Peso (Peso é uma desvantagem).
// -------------------------------------------------------------------
void desafio_3_operador_ternario(Carta c1, Carta c2) {
    char *resultado_msg;

    printf("Regra Complexa:\n");
    printf("1. Vence quem tiver MAIOR Potência.\n");
    printf("2. Se a Potência EMPATAR, Vence quem tiver MENOR Peso.\n\n");
    
    printf("Potência (J vs C): %d vs %d | Peso (J vs C): %d vs %d\n", 
           c1.potencia, c2.potencia, c1.peso, c2.peso);
    
    // Lógica principal: Potência (Maior vence)
    if (c1.potencia > c2.potencia) {
        resultado_msg = "🏆 Jogador Venceu! (Maior Potência)";
    } 
    // Condição de desempate (if-else if): Peso (Menor vence, se Potência for igual)
    else if (c1.potencia == c2.potencia) {
        
        // Uso OBRIGATÓRIO do Operador Ternário para o desempate de Peso:
        resultado_msg = (c1.peso < c2.peso) ? 
                        "🏆 Jogador Venceu! (Empate na Potência, Menor Peso)" : 
                        "🙁 Jogador Perdeu/Empatou! (Empate na Potência)";
    } 
    // Última condição (else): Potência do Jogador é Menor
    else {
        resultado_msg = "💀 Jogador Perdeu! (Menor Potência)";
    }
    
    printf("\nRESULTADO FINAL: %s\n", resultado_msg);
}
