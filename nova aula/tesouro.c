#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h> // Necessário para multimídia

#pragma comment(lib, "winmm.lib") // Vincula a biblioteca de som do Windows
#define TAM 5
#define TESOUROS 3

typedef struct
{
	char nome[20];
	int tentativas;
}Jogador;

void inicializarMapa(char mapa[TAM][TAM]);
void mostrarMapa(char mapa[TAM][TAM]);
void posicionarTesouros(char mapa[TAM][TAM]);
int procurarTesouros(char mapa[TAM][TAM], int *encontrados);
void salvar(Jogador jogador);

 int main()
{
	char mapa[TAM][TAM];
    int encontrados = 0;
    Jogador jogador;
    jogador.tentativas = 0;

    srand(time(NULL));

    printf("----------BEM VINDO AO GAME----------\n");
    printf("Informe o seu NOME: ");
    scanf("%s", jogador.nome);

    inicializarMapa(mapa);
    posicionarTesouros(mapa);

    while (encontrados < TESOUROS) {
        mostrarMapa(mapa);
        procurarTesouros(mapa, &encontrados);
        jogador.tentativas++;
    }

    printf("\a\nParabens %s! Voce achou todos os tesouros em %d tentativas.\n", jogador.nome, jogador.tentativas);
    salvar(jogador);

    return 0;
}

void inicializarMapa(char mapa[TAM][TAM])
{
	int i, j;
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{
			mapa[i][j] = '#';
		}
	}
}

void mostrarMapa(char mapa[TAM][TAM]) {
    printf("\n  ");
    for (int j = 0; j < TAM; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAM; j++) {
            if (mapa[i][j] == 't') {
                printf("# ");
            } else {
                printf("%c ", mapa[i][j]);
            }
        }
        printf("\n");
    }
}


void posicionarTesouros(char mapa[TAM][TAM])
{
	int linha, coluna;
    int tesourosPosicionados = 0;

    while (tesourosPosicionados < 3) {
    
        linha = rand() % TAM;
        coluna = rand() % TAM;

        
        if (mapa[linha][coluna] != 't') {
            mapa[linha][coluna] = 't';
            tesourosPosicionados++; 
        }
    }
}

int procurarTesouros(char mapa[TAM][TAM], int *encontrados)
{
	int linha, coluna;

	printf("\nLinha:");
	scanf("%d", &linha);
	printf("\nColuna: ");
	scanf("%d", &coluna);

	if (mapa[linha][coluna] == 't')
	{
		printf("\atesouro encontrado\n");
		    // Reproduz um arquivo de som do sistema ou o seu próprio arquivo .wav
    PlaySound(TEXT("C:\\Windows\\Media\\tada.wav"), NULL, SND_FILENAME | SND_ASYNC);
    
    // Pausa o programa brevemente para dar tempo de o som tocar
    Sleep(1000);
		mapa[linha][coluna] = 'x';
		(*encontrados)++;
		return(1);
	}
	printf("\anada foi encontrado\n");
	
		mapa[linha][coluna] = 'o';
		return(1);
}

void salvar(Jogador jogador)
{
	FILE *arquivo;
	arquivo = fopen("historico.txt", "a");

	if (arquivo == NULL)
	{
		printf("erro ao abrir\n");
		return;
	}
	else{
		fprintf(arquivo, "%s | %d\n", jogador.nome, jogador.tentativas);
		fclose(arquivo);
	}
}