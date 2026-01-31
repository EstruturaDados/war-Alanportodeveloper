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

do


{
    for (int i = 0; i < MAX_TERRITORIOS; i++){
        printf("--- Cadastrando Território %d --- \n", i + 1 );
        printf("Nome do território: %s \n", territorios[i].nome);
        printf("Cor do exécito (ex: Azul, Verde): %s \n", territorios[i].cor);
        printf("Número de Tropas: %d \n\n", territorios[i].tropas);
    }
    
} while (MAX_TERRITORIOS < 5);



return 0; // Fim do programa
}

