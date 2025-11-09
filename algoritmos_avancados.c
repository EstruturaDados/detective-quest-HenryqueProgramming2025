#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct para representar cada sala da mansão
struct Sala {
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
};

// Protótipos das funções
struct Sala* criarSala(const char* nome);
void explorarMansao(struct Sala* atual);
void liberarArvore(struct Sala* raiz);

int main() {
    printf("=== DETECTIVE QUEST - EXPLORAÇÃO DA MANSÃO ===\n\n");
    
    // Montagem do mapa da mansão (árvore binária)
    struct Sala* hall = criarSala("Hall de Entrada");
    struct Sala* salaEstar = criarSala("Sala de Estar");
    struct Sala* cozinha = criarSala("Cozinha");
    struct Sala* biblioteca = criarSala("Biblioteca");
    struct Sala* quarto = criarSala("Quarto Principal");
    struct Sala* jardim = criarSala("Jardim");
    struct Sala* porao = criarSala("Porão");
    
    // Construção da árvore (mapa da mansão)
    hall->esquerda = salaEstar;
    hall->direita = cozinha;
    
    salaEstar->esquerda = biblioteca;
    salaEstar->direita = quarto;
    
    cozinha->esquerda = jardim;
    cozinha->direita = porao;
    
    // Folhas (salas sem saída)
    biblioteca->esquerda = NULL;
    biblioteca->direita = NULL;
    
    quarto->esquerda = NULL;
    quarto->direita = NULL;
    
    jardim->esquerda = NULL;
    jardim->direita = NULL;
    
    porao->esquerda = NULL;
    porao->direita = NULL;
    
    printf("💀 Um crime ocorreu nesta mansão!\n");
    printf("🔍 Explore os cômodos para encontrar pistas...\n\n");
    
    // Inicia a exploração a partir do Hall
    explorarMansao(hall);
    
    // Libera a memória alocada
    liberarArvore(hall);
    
    printf("\n=== INVESTIGAÇÃO ENCERRADA ===\n");
    return 0;
}
