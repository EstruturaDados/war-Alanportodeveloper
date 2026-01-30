#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Contantes globais 

#define TAM_NOME  30
#define TAM_COR 10
#define MAX_TERRITORIOS 5

// Definição da estrutura Território

struct TERRITORIO{
   char nome[TAM_NOME];
   char cor[TAM_COR];
   int tropas;
};

// Função para limpar o Buffer de entrada

void limparBufferEntrada() {
int c;
while ((c = getchar()) != '\n' && c != EOF);

}

// Função principal

int main () {
    struct TERRITORIO territorios[MAX_TERRITORIOS];

    
// Exibe o Menu inicial
printf("=========================================================\n\n");
printf("Vamos cadastrar os 5 territórios iniciais do nosso mundo\n\n"); 

}

