#include <stdio.h>
#include <string.h>

// Definição da estrutura para a carta
typedef struct {
    char codigo[5]; // Ex: A01, B02
    char nome_cidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

int main() {
    Carta carta1, carta2;

    printf("--- Cadastro da Carta 1 ---\n");
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", carta1.codigo);
    printf("Digite o nome da cidade: ");
    scanf("%s", carta1.nome_cidade);
    printf("Digite a população: ");
    scanf("%lu", &carta1.populacao);
    printf("Digite a área (em km²): ");
    scanf("%f", &carta1.area);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    // Cálculo para Carta 1
    if (carta1.area > 0) {
        carta1.densidade_populacional = (float)carta1.populacao / carta1.area;
    } else {
        carta1.densidade_populacional = 0.0;
    }
    if (carta1.populacao > 0) {
        carta1.pib_per_capita = (carta1.pib * 1000000000) / carta1.populacao; // PIB em bilhões para reais
    } else {
        carta1.pib_per_capita = 0.0;
    }

    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Digite o código da carta (ex: B02): ");
    scanf("%s", carta2.codigo);
    printf("Digite o nome da cidade: ");
    scanf("%s", carta2.nome_cidade);
    printf("Digite a população: ");
    scanf("%lu", &carta2.populacao);
    printf("Digite a área (em km²): ");
    scanf("%f", &carta2.area);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // Cálculo para Carta 2
    if (carta2.area > 0) {
        carta2.densidade_populacional = (float)carta2.populacao / carta2.area;
    } else {
        carta2.densidade_populacional = 0.0;
    }
    if (carta2.populacao > 0) {
        carta2.pib_per_capita = (carta2.pib * 1000000000) / carta2.populacao; // PIB em bilhões para reais
    } else {
        carta2.pib_per_capita = 0.0;
    }

    printf("\n--- Dados das Cartas Cadastradas ---\n");

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", carta1.codigo[0]);
    printf("Código: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.nome_cidade);
    printf("População: %lu\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhões de reais\n", carta1.pib);
    printf("Número de Pontos Turísticos: %d\n", carta1.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidade_populacional);
    printf("PIB per Capita: %.2f reais\n", carta1.pib_per_capita);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", carta2.codigo[0]);
    printf("Código: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.nome_cidade);
    printf("População: %lu\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhões de reais\n", carta2.pib);
    printf("Número de Pontos Turísticos: %d\n", carta2.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidade_populacional);
    printf("PIB per Capita: %.2f reais\n", carta2.pib_per_capita);

    // Comparação do atributo escolhido (População)
    printf("\nComparação de cartas (Atributo: População):\n");
    printf("\nCarta 1 - %s (%c%c): %lu\n", carta1.nome_cidade, carta1.codigo[0], carta1.codigo[1], carta1.populacao);
    printf("Carta 2 - %s (%c%c): %lu\n", carta2.nome_cidade, carta2.codigo[0], carta2.codigo[1], carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}

