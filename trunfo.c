#include <stdio.h>
#include <string.h>

#define MAX_CIDADES 100

// Estrutura para armazenar os dados de uma cidade
typedef struct {
    char estado[30];
    int codigo;
    char nome[50];
    int populacao;
    float pib;
    float area;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Cidade;

// Função para calcular densidade populacional
float calcularDensidadePopulacional(int populacao, float area) {
    if (area == 0) return 0;
    return populacao / area;
}

// Função para calcular PIB per capita
float calcularPIBPerCapita(float pib, int populacao) {
    if (populacao == 0) return 0;
    return pib / populacao;
}

// Função para registrar uma cidade
void registrarCidade(Cidade *c) {
    printf("\n--- Cadastro de Cidade ---\n");
    printf("Estado: ");
    scanf(" %[^\n]", c->estado);

    printf("Código: ");
    scanf("%d", &c->codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c->nome);

    printf("População: ");
    scanf("%d", &c->populacao);

    printf("PIB (em milhões R$): ");
    scanf("%f", &c->pib);

    printf("Área (em km²): ");
    scanf("%f", &c->area);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c->pontosTuristicos);

    // Cálculos derivados
    c->densidadePopulacional = calcularDensidadePopulacional(c->populacao, c->area);
    c->pibPerCapita = calcularPIBPerCapita(c->pib, c->populacao);
}

// Função para exibir os dados de uma cidade
void exibirCidade(const Cidade *c) {
    printf("\n=== Carta da Cidade ===\n");
    printf("Estado: %s\n", c->estado);
    printf("Código: %d\n", c->codigo);
    printf("Nome: %s\n", c->nome);
    printf("População: %d habitantes\n", c->populacao);
    printf("PIB: R$ %.2f milhões\n", c->pib);
    printf("Área: %.2f km²\n", c->area);
    printf("Pontos Turísticos: %d\n", c->pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c->densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", c->pibPerCapita);
}

int main() {
    Cidade cidades[MAX_CIDADES];
    int quantidade, i;

    printf("Quantas cidades deseja registrar? ");
    scanf("%d", &quantidade);

    if (quantidade > MAX_CIDADES || quantidade <= 0) {
        printf("Número inválido de cidades.\n");
        return 1;
    }

    for (i = 0; i < quantidade; i++) {
        printf("\n>>> Cidade %d de %d\n", i + 1, quantidade);
        registrarCidade(&cidades[i]);
    }

    printf("\n\n==== Cartas das Cidades Registradas ====\n");
    for (i = 0; i < quantidade; i++) {
        exibirCidade(&cidades[i]);
    }

    return 0;
}
