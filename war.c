// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>


// --- Constantes Globais ---

#define NUM_TERRITORIOS 5
#define NUM_MISSOES 2
#define TAM_NOME 30
#define TAM_COR 10

// --- Estrutura de Dados ---

typedef struct {
    char nome[TAM_NOME];
    char cor [TAM_COR];
    int tropas;
} Territorio;

// --- Protótipos das Funções ---
/// Setup e memória

Territorio* alocarMapa(void);
void inicializarTerritorios(Territorio *mapa);
void liberarMemoria(Territorio *mapa);

// Interface

void exibirMenuPrincipal(void);
void exibirMapa(const Territorio *mapa);
void exibirMissao(int missao, const char *corJogador);

// Lógica do jogo

void faseDeAtaque(Territorio *mapa, const char *corJogador);
void simularAtaque(Territorio *origem, Territorio *destino);
int sortearMissao(void);
int verificarVitoria(const Territorio *mapa, int missao, const char *corJogador);

void limparBufferEntrada(void);

// --- Função Principal (main) ---

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Territorio *mapa = alocarMapa();
    if (!mapa) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    inicializarTerritorios(mapa);

    char corJogador[TAM_COR] = "Azul";
    int missao = sortearMissao();
    int opcao;

    do {
        exibirMapa(mapa);
        exibirMissao(missao, corJogador);
        exibirMenuPrincipal();

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao)
        {
        case 1:
            faseDeAtaque(mapa, corJogador);
            break;

        case 2:
            if (verificarVitoria(mapa, missao, corJogador)) {
                printf("\n Missão cumprida! Você venceu o jogo!\n");
                opcao = 0;
            } else {
                printf("\n Missão ainda não concluída.\n");
            }

            break;

        case 0:
            printf("\nEncerrando o jogo....\n");
            break;
        
        default:
            printf("\nOpção inválida!\n");
        }

        printf("\nPressione ENTER para continuar....");
        getchar();

    } while (opcao != 0);

    liberarMemoria(mapa);
    return 0;
    
}


// --- Implementação das Funções ---

Territorio* alocarMapa(void) {
    return (Territorio *)calloc(NUM_TERRITORIOS, sizeof(Territorio));

}

void inicializarTerritorios(Territorio *mapa) {
    strcpy(mapa[0].nome, "Brasil");
    strcpy(mapa[0].cor, "Azul");
    mapa[0].tropas = 5;

    strcpy(mapa[1].nome, "Argentina");
    strcpy(mapa[1].cor, "Vermelho");
    mapa[1].tropas = 4;

    strcpy(mapa[2].nome, "Chile");
    strcpy(mapa[2].cor, "Verde");
    mapa[2].tropas = 3;

    strcpy(mapa[3].nome, "Peru");
    strcpy(mapa[3].cor, "Vermelho");
    mapa[3].tropas = 4;

    strcpy(mapa[4].nome, "Colombia");
    strcpy(mapa[4].cor, "Verde");
    mapa[4].tropas = 3;

}

void liberarMemoria(Territorio *mapa) {
    free(mapa);
}

void exibirMenuPrincipal(void) {
    printf("\n=== MENU PRINCIPAL ===\n");
    printf("1 - Atacar\n");
    printf("2 - Verificar Missão\n");
    printf("0 - Sair\n");
}

void exibirMapa(const Territorio *mapa) {
    printf("=== MAPA DO MUNDO ===\n");
    for (int i = 0; i < NUM_TERRITORIOS; i++) {
        printf("%d) %-10s | Dono: %-8s | Tropas: %d\n", i, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

void exibirMissao(int missao, const char *corJogador) {
    printf("\n=== MISSÃO SECRETA ===\n");
    if (missao == 0)
        printf("Conquistar todos os territórios do mapa.\n");
    else
        printf("Eliminar todos os territórios do exército vermelho.\n");
    
}

void faseDeAtaque(Territorio *mapa, const char *corJogador) {
    int origem, destino;

    printf("\nTerritório de origem (ID): ");
    scanf("%d", &origem);
    printf("Território de destino (ID): ");
    scanf("%d", &destino);

    if (origem < 0 || origem >= NUM_TERRITORIOS || 
        destino < 0 || destino >= NUM_TERRITORIOS) {
            printf("Território inválido!\n");
            return;
        }

        if (strcmp(mapa[origem].cor, corJogador) != 0) {
            printf("Você só pode atacar a partir de seus territórios!\n");
            return;
        }
        
         simularAtaque(&mapa[origem], &mapa[destino]);  
        
}

void simularAtaque(Territorio *origem, Territorio *destino) {
    if (origem->tropas < 2) {
        printf("Tropas insuficiente para atacar!\n");
        return;
    }

    int dadoAtaque = rand() % 6 + 1;
    int dadoDefesa = rand() % 6 + 1;

    printf("Ataque: %d | Defesa: %d\n", dadoAtaque, dadoDefesa);

    if (dadoAtaque > dadoDefesa) {
        destino->tropas--;
        if (destino->tropas <= 0) {
            strcpy(destino->cor, origem->cor);
            destino->tropas = 1;
            origem->tropas--;
            printf("Território conquistado!\n");
        }
        
    } else {
        origem->tropas--;
        printf("Ataque falhou!\n");
    }
    
}

int sortearMissao(void) {
    return rand() % NUM_MISSOES;
}

int verificarVitoria(const Territorio *mapa, int missao, const char *corJogador) {
    if (missao == 0) {
        for (int i = 0; i < NUM_TERRITORIOS; i++) {
            if (strcmp(mapa[i].cor, corJogador) != 0)
            return 0;
        } 
        return 1;
    } else {
        for (int i = 0; i < NUM_TERRITORIOS; i++) {
            if (strcmp(mapa[i].cor, "Vermelho") == 0)
                return 0;
        }
        return 1;
        
    }
}

void limparBufferEntrada(void) {
    int c;
    while ( (c = getchar()) != '\n' && c != EOF);
    
}