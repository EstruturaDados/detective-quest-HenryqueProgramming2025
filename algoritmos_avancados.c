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

// Função para criar uma nova sala (nó da árvore)

struct Sala* criarSala(const char* nome) {
    struct Sala* novaSala = (struct Sala*)malloc(sizeof(struct Sala));
    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    return novaSala;
}

// Função para explorar a mansão (navegar pela árvore)
void explorarMansao(struct Sala* atual) {
    if (atual == NULL) {
        return;
    }
    
    printf("\n📍 Você está na: %s\n", atual->nome);
    
    // Verifica se é uma sala sem saída (nó folha)
    if (atual->esquerda == NULL && atual->direita == NULL) {
        printf("🚫 Esta sala não tem saídas. Fim do caminho!\n");
        return;
    }
    
    // Mostra opções de navegação
    printf("Para onde deseja ir?\n");
    if (atual->esquerda != NULL) {
        printf("[E] Esquerda → %s\n", atual->esquerda->nome);
    }
    if (atual->direita != NULL) {
        printf("[D] Direita → %s\n", atual->direita->nome);
    }
    printf("[S] Sair da investigação\n");
    
    char escolha;
    printf("\nEscolha (E/D/S): ");
    scanf(" %c", &escolha);
    
    // Processa a escolha do jogador
    switch(escolha) {
        case 'E':
        case 'e':
            if (atual->esquerda != NULL) {
                explorarMansao(atual->esquerda);
            } else {
                printf("❌ Não há saída pela esquerda!\n");
                explorarMansao(atual); // Volta para a mesma sala
            }
            break;
            
        case 'D':
        case 'd':
            if (atual->direita != NULL) {
                explorarMansao(atual->direita);
            } else {
                printf("❌ Não há saída pela direita!\n");
                explorarMansao(atual); // Volta para a mesma sala
            }
            break;
            
        case 'S':
        case 's':
            printf("🏃 Saindo da investigação...\n");
            return;
            
        default:
            printf("❌ Opção inválida! Use E, D ou S.\n");
            explorarMansao(atual); // Volta para a mesma sala
    }
}

// Função para liberar a memória da árvore (pós-ordem)
void liberarArvore(struct Sala* raiz) {
    if (raiz == NULL) {
        return;
    }
    
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}
