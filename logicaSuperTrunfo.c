#include <stdio.h>

typedef struct {
    char estado[50];
    int codigo;
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Cidade;

void cadastrarCidade(Cidade *cidade) {
    printf("Digite o estado: ");
    scanf("%s", cidade->estado);
    printf("Digite o código da carta: ");
    scanf("%d", &cidade->codigo);
    printf("Digite o nome da cidade: ");
    scanf("%s", cidade->nome);
    printf("Digite a população: ");
    scanf("%d", &cidade->populacao);
    printf("Digite a área (km²): ");
    scanf("%f", &cidade->area);
    printf("Digite o PIB (bilhões): ");
    scanf("%f", &cidade->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade->pontos_turisticos);
}

void compararCartas(Cidade c1, Cidade c2, int atributo1, int atributo2) {
    float valor1a, valor2a, valor1b, valor2b;
    int vencedor1, vencedor2;

    // Lógica para definir os valores dos atributos
    switch (atributo1) {
        case 1: valor1a = c1.populacao; valor2a = c2.populacao; vencedor1 = valor1a < valor2a ? 1 : 2; break;
        case 2: valor1a = c1.area; valor2a = c2.area; vencedor1 = valor1a > valor2a ? 1 : 2; break;
        case 3: valor1a = c1.pib; valor2a = c2.pib; vencedor1 = valor1a > valor2a ? 1 : 2; break;
        case 4: valor1a = c1.pontos_turisticos; valor2a = c2.pontos_turisticos; vencedor1 = valor1a > valor2a ? 1 : 2; break;
        default: printf("Atributo inválido!\n"); return;
    }

    switch (atributo2) {
        case 1: valor1b = c1.populacao; valor2b = c2.populacao; vencedor2 = valor1b < valor2b ? 1 : 2; break;
        case 2: valor1b = c1.area; valor2b = c2.area; vencedor2 = valor1b > valor2b ? 1 : 2; break;
        case 3: valor1b = c1.pib; valor2b = c2.pib; vencedor2 = valor1b > valor2b ? 1 : 2; break;
        case 4: valor1b = c1.pontos_turisticos; valor2b = c2.pontos_turisticos; vencedor2 = valor1b > valor2b ? 1 : 2; break;
        default: printf("Atributo inválido!\n"); return;
    }

    printf("\nResultado da comparação:\n");
    
    if (vencedor1 == vencedor2) {
        printf("A cidade %s vence com base nos atributos escolhidos!\n", vencedor1 == 1 ? c1.nome : c2.nome);
    } else {
        printf("Empate na comparação dos atributos escolhidos!\n");
    }
}

int main() {
    Cidade cidade1, cidade2;
    int atributo1, atributo2, opcao;

    printf("Cadastro da primeira cidade:\n");
    cadastrarCidade(&cidade1);

    printf("\nCadastro da segunda cidade:\n");
    cadastrarCidade(&cidade2);

    do {
        printf("\nMenu de Comparação:\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n");
        printf("5 - Sair\nEscolha dois atributos para comparar:\n");
        printf("Primeiro atributo: ");
        scanf("%d", &atributo1);
        
        if (atributo1 == 5) break;
        
        printf("Segundo atributo: ");
        scanf("%d", &atributo2);
        
        if (atributo2 == 5) break;

        compararCartas(cidade1, cidade2, atributo1, atributo2);
    } while (atributo1 != 5 && atributo2 != 5);

    printf("Obrigado por jogar 'Super Trunfo - Países'!\n");

    return 0;
}