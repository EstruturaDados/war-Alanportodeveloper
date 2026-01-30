#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Contantes globais 

#define TAM_NOME  30
#define TAM_COR 10

// Definição da estrutura Território

struct Territorio {
   char nome[TAM_NOME];
   char cor[TAM_COR];
   int tropas;
};
