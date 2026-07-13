/* ================================================================
   RPG DE TEXTO - A JORNADA DO HERÓI
   Trabalho em linguagem C
   ================================================================ */
#include <stdio.h>

void menu();

void criarPersonagem();

void mostrarStatus();

void explorarMapa();

void combate();

void subirNivel();

void loja();

void inventario();

void descansar();

void chefeFinal();

int main(){
	
	int controle = 0;
	
	printf(" _____  ____   _____ \n");
	printf("|  __ \\|  _ \\ / ____|\n");
	printf("| |__) | |_) | |  __ \n");
	printf("|  _  /|  __/| | |_ |\n");
	printf("| | \\ \\| |   | |__| |\n");
	printf("|_|  \\_\\_|    \\_____|\n");
    printf("\n");
    printf("=========================================\n");
    printf("        BEM-VINDO a SUA AVENTURA!\n");
    printf("=========================================\n");
	
	do
	{
		
		menu();
		
		scanf("%d", &controle);
		
		switch (controle)
		{
			case 1:
			break;
			
			default:
			printf("essa resposta nao esta catalogada no grimorio do mestre\n");
		}
		
	}while (controle != 0);
	
	return(0);
	
}

void menu()
{
printf("=================================================\n");
printf("          RPG DE TEXTO - A JORNADA DO HEROI      \n");
printf("=================================================\n");
printf("\n");
printf("1 - Criar Personagem\n");
printf("2 - Ver Status\n");
printf("3 - Explorar Mapa\n");
printf("4 - Loja\n");
printf("5 - Inventario\n");
printf("6 - Descansar\n");
printf("7 - Enfrentar Chefe Final\n");
printf("0 - Sair\n");
printf("\n");
printf("Escolha:\n");
}                                             