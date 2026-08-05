#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define TAM 8
#define NAVIOS 3

typedef struct {
    char nome[20];
    int tentativas;
} Jogador;

void inicializartabuleiro(char tabuleiro[TAM][TAM]);
void mostrartabuleiro(char tabuleiro[TAM][TAM]);
void posicionarnavios(char tabuleiro[TAM][TAM]);
int realizarataque(char tabuleiro[TAM][TAM], int *destruidos);
void salvar(Jogador jogador);
void ler();

int main() {
    char tabuleiro[TAM][TAM];
    int destruidos = 0;
    Jogador jogador;
    jogador.tentativas = 0;
    
    srand(time(NULL));
    
    printf("----------BEM VINDO AO BATALHA NAVAL----------\n");
    printf("Informe o seu NOME: ");
    scanf("%s", jogador.nome);
    
    inicializartabuleiro(tabuleiro);
    posicionarnavios(tabuleiro);
    
    while (destruidos < NAVIOS) {
        mostrartabuleiro(tabuleiro);
        realizarataque(tabuleiro, &destruidos);
        jogador.tentativas++;
    }
    
    printf("\a\nParabens %s! Voce achou todos os navios em %d tentativas.\n", jogador.nome, jogador.tentativas);
    salvar(jogador);
    
    printf("\n--- HALL DA FAMA ---\n");
    ler();
    
    return 0;
}

void inicializartabuleiro(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = '~';
        }
    }
}

void mostrartabuleiro(char tabuleiro[TAM][TAM]) {
    printf("\n   ");
    for (int j = 0; j < TAM; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d   ", i);
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 'N') {
                printf("~ ");
            } else {
                printf("%c ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }
}

void posicionarnavios(char tabuleiro[TAM][TAM]) {
    int linha, coluna;
    int naviosPosicionados = 0;
    while (naviosPosicionados < NAVIOS) {
        linha = rand() % TAM;
        coluna = rand() % TAM;
        if (tabuleiro[linha][coluna] != 'N') {
            tabuleiro[linha][coluna] = 'N';
            naviosPosicionados++;
        }
    }
}

int realizarataque(char tabuleiro[TAM][TAM], int *destruidos) {
    int linha, coluna;
    printf("\nLinha: ");
    scanf("%d", &linha);
    printf("Coluna: ");
    scanf("%d", &coluna);
    
    if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM) {
        printf("Posicao invalida! Tente novamente.\n");
        return 0;
    }
    
    if (tabuleiro[linha][coluna] == 'N') {
        printf("\aBOMBA! navio encontrado\a\n");
        tabuleiro[linha][coluna] = 'x';
        (*destruidos)++;
        return 1;
    }
    
    printf("\aAGUA! nada foi encontrado\n");
    tabuleiro[linha][coluna] = 'o';
    return 1;
}

void salvar(Jogador jogador) {
    FILE *arquivo = fopen("historico.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para salvamento\n");
        return;
    }
    fprintf(arquivo, "%s | %d tentativas\n", jogador.nome, jogador.tentativas);
    fclose(arquivo);
}

void ler() {
    FILE *pont_arq = fopen("historico.txt", "r");
    char linha[256];
    
    if (pont_arq == NULL) {
        printf("Nenhum historico encontrado.\n");
        return;
    }
    
    while (fgets(linha, sizeof(linha), pont_arq) != NULL) {
        printf("%s", linha);
    }
    printf("-----------------------------------\n");
    fclose(pont_arq);
}
