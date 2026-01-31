#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Contantes globais 

#define TAM_NOME  30
#define TAM_COR 10
#define TAM_NUM 10
#define MAX_TERRITORIOS 5

// Definição da estrutura Território

struct TERRITORIO{
   char nome[TAM_NOME];
   char cor[TAM_COR];
   int tropas;
};

// Função principal

int main () {
    struct TERRITORIO territorios[MAX_TERRITORIOS];
    char buffer[TAM_NUM];
    
// Exibe o Menu inicial
printf("=========================================================\n\n");
printf("Vamos cadastrar os 5 territórios iniciais do nosso mundo\n\n"); 

// Cadastro

    for (int i = 0; i < MAX_TERRITORIOS; i++){
        printf("--- Cadastrando Território %d --- \n", i + 1 );

        printf("Nome do território: ");
        fgets(territorios[i].nome, TAM_NOME, stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = 0;
        
        printf("Cor do exécito (ex: Azul, Verde): ");
        fgets(territorios[i].cor, TAM_COR, stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = 0;

        printf("Número de tropas: ");
        fgets(buffer, TAM_NUM, stdin);
        territorios[i].tropas = atoi(buffer);

        printf("\n");
    }
    
// Exibição

printf(" MAPA DO MUNDO - ESTADO ATUAL  \n");
printf("=============================================\n\n");
for (int i = 0; i < MAX_TERRITORIOS; i++){
        printf("Território %d\n", i + 1);
        printf("- Nome: %s\n", territorios[i].nome);
        printf("- Cor do exército: %n\n", territorios[i].cor);
        printf("- Número de Tropas: %d\n\n\n", territorios[i].tropas);
    }
 
    return 0; // Fim do programa
    
}
