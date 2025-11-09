#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct para representar cada sala da mansão
struct Sala {
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
};

