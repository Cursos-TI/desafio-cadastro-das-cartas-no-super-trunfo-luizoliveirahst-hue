#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

// Função para exibir o menu de atributos
void exibir_menu(int atributos_selecionados[]) {
    printf("\n--- Escolha um Atributo para Comparação ---\n");
    if (atributos_selecionados[0] == 0) printf("1. População\n");
    if (atributos_selecionados[1] == 0) printf("2. Área\n");
    if (atributos_selecionados[2] == 0) printf("3. PIB\n");
    if (atributos_selecionados[3] == 0) printf("4. Número de Pontos Turísticos\n");
    if (atributos_selecionados[4] == 0) printf("5. Densidade Populacional\n");
    if (atributos_selecionados[5] == 0) printf("6. PIB per Capita\n");
    printf("Digite o número do atributo desejado: ");
}

// Função para obter o valor de um atributo de uma carta
float get_atributo_value(Carta carta, int atributo_id) {
    switch (atributo_id) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontos_turisticos;
        case 5: return carta.densidade_populacional;
        case 6: return carta.pib_per_capita;
        default: return 0.0;
    }
}

// Função para obter o nome de um atributo
const char* get_atributo_name(int atributo_id) {
    switch (atributo_id) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Número de Pontos Turísticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per Capita";
        default: return "Desconhecido";
    }
}

int main() {
    // Inicialização das 8 cartas predefinidas
    Carta baralho[8] = {
        {"A01", "Sao_Paulo", 12325000, 1521.11, 699.28, 50, 0.0, 0.0},
        {"B02", "Rio_de_Janeiro", 6748000, 1200.25, 300.50, 30, 0.0, 0.0},
        {"C03", "Brasilia", 3094000, 5779.99, 280.00, 25, 0.0, 0.0},
        {"D04", "Salvador", 2900000, 693.80, 60.00, 40, 0.0, 0.0},
        {"E01", "Fortaleza", 2686000, 313.14, 55.00, 35, 0.0, 0.0},
        {"F02", "Belo_Horizonte", 2530000, 331.40, 90.00, 28, 0.0, 0.0},
        {"G03", "Manaus", 2219000, 11401.00, 70.00, 20, 0.0, 0.0},
        {"H04", "Curitiba", 1963000, 434.96, 85.00, 22, 0.0, 0.0}
    };

    // Cálculo da densidade populacional e PIB per capita para as cartas predefinidas
    for (int i = 0; i < 8; i++) {
        baralho[i].densidade_populacional = (baralho[i].area > 0) ? (float)baralho[i].populacao / baralho[i].area : 0.0;
        baralho[i].pib_per_capita = (baralho[i].populacao > 0) ? (baralho[i].pib * 1000000000) / baralho[i].populacao : 0.0;
    }

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    int pontuacao_jogador = 0;
    int pontuacao_cpu = 0;
    int rodadas = 3; // Exemplo: 3 rodadas

    printf("\n--- Bem-vindo ao Super Trunfo de Países! ---\n");
    printf("O jogo terá %d rodadas.\n", rodadas);

    for (int i = 1; i <= rodadas; i++) {
        printf("\n--- Rodada %d ---\n", i);

        // Seleção aleatória de duas cartas
        int index_carta1 = rand() % 8;
        int index_carta2;
        do {
            index_carta2 = rand() % 8;
        } while (index_carta1 == index_carta2);

        Carta carta1 = baralho[index_carta1];
        Carta carta2 = baralho[index_carta2];

        int escolha_atributo1, escolha_atributo2;
        int atributos_selecionados[6] = {0, 0, 0, 0, 0, 0}; // 0 = disponível, 1 = selecionado

        printf("\n--- Cartas Sorteadas ---\n");
        printf("Sua Carta:\n");
        printf("  Nome da Cidade: %s\n", carta1.nome_cidade);
        printf("  População: %lu\n", carta1.populacao);
        printf("  Área: %.2f km²\n", carta1.area);
        printf("  PIB: %.2f bilhões de reais\n", carta1.pib);
        printf("  Número de Pontos Turísticos: %d\n", carta1.pontos_turisticos);
        printf("  Densidade Populacional: %.2f hab/km²\n", carta1.densidade_populacional);
        printf("  PIB per Capita: %.2f reais\n", carta1.pib_per_capita);

        // Escolha do primeiro atributo
        exibir_menu(atributos_selecionados);
        scanf("%d", &escolha_atributo1);
        atributos_selecionados[escolha_atributo1 - 1] = 1;

        // Escolha do segundo atributo (menu dinâmico)
        exibir_menu(atributos_selecionados);
        scanf("%d", &escolha_atributo2);

        // Comparação e soma dos atributos
        float valor1_attr1 = get_atributo_value(carta1, escolha_atributo1);
        float valor2_attr1 = get_atributo_value(carta2, escolha_atributo1);
        float valor1_attr2 = get_atributo_value(carta1, escolha_atributo2);
        float valor2_attr2 = get_atributo_value(carta2, escolha_atributo2);

        // Ajuste para Densidade Populacional (menor valor vence)
        valor1_attr1 = (escolha_atributo1 == 5) ? -valor1_attr1 : valor1_attr1;
        valor2_attr1 = (escolha_atributo1 == 5) ? -valor2_attr1 : valor2_attr1;
        valor1_attr2 = (escolha_atributo2 == 5) ? -valor1_attr2 : valor1_attr2;
        valor2_attr2 = (escolha_atributo2 == 5) ? -valor2_attr2 : valor2_attr2;

        float soma_carta1 = valor1_attr1 + valor1_attr2;
        float soma_carta2 = valor2_attr1 + valor2_attr2;

        printf("\n--- Detalhes da Rodada ---\n");
        printf("Atributos escolhidos: %s e %s\n", get_atributo_name(escolha_atributo1), get_atributo_name(escolha_atributo2));
        printf("\nSua Carta (%s):\n", carta1.nome_cidade);
        printf("  %s: %.2f\n", get_atributo_name(escolha_atributo1), get_atributo_value(carta1, escolha_atributo1));
        printf("  %s: %.2f\n", get_atributo_name(escolha_atributo2), get_atributo_value(carta1, escolha_atributo2));
        printf("  Soma dos atributos: %.2f\n", soma_carta1);

        printf("\nCarta do Oponente (%s):\n", carta2.nome_cidade);
        printf("  %s: %.2f\n", get_atributo_name(escolha_atributo1), get_atributo_value(carta2, escolha_atributo1));
        printf("  %s: %.2f\n", get_atributo_name(escolha_atributo2), get_atributo_value(carta2, escolha_atributo2));
        printf("  Soma dos atributos: %.2f\n", soma_carta2);

        if (soma_carta1 > soma_carta2) {
            printf("\nResultado da Rodada: Você venceu com a carta %s!\n", carta1.nome_cidade);
            pontuacao_jogador++;
        } else if (soma_carta2 > soma_carta1) {
            printf("\nResultado da Rodada: A CPU venceu com a carta %s!\n", carta2.nome_cidade);
            pontuacao_cpu++;
        } else {
            printf("\nResultado da Rodada: Empate!\n");
        }

        printf("\nPontuação Atual: Jogador %d x %d CPU\n", pontuacao_jogador, pontuacao_cpu);
    }

    printf("\n--- Fim do Jogo ---\n");
    if (pontuacao_jogador > pontuacao_cpu) {
        printf("Parabéns! Você venceu o jogo!\n");
    } else if (pontuacao_cpu > pontuacao_jogador) {
        printf("Que pena! A CPU venceu o jogo!\n");
    } else {
        printf("O jogo terminou em empate!\n");
    }

    return 0;
}

