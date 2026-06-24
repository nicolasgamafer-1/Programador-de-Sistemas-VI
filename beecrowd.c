#include <stdio.h>

void menu();
int soma (int a, int b);
int menos (int a, int b);
int divisao (int a, int b);
int multiplicacao (int a, int b);


int main() 
{
	int calculo = 0, a=0, b=0, resposta=0;


	do 
	{

		menu();

		scanf("%d", &calculo);

		switch (calculo)
		{
			case 0:
				calculo = 0;
			break;
			
			case 1:
			 printf("digite dois numeros\n");
			 scanf("%d", &a);
			 scanf("%d", &b);
			 resposta = soma(a,b);
			 printf("a resposta: %d\n", resposta);
			break;
	 
			case 2:
			 printf("digite dois numeros\n");
			 scanf("%d", &a);
			 scanf("%d", &b);
			 resposta = multiplicacao(a,b);
			 printf("a resposta: %d\n", resposta);
			break;
	 
			case 3:
			 printf("digite dois numeros\n");
			 scanf("%d", &a);
			 scanf("%d", &b);
			 if (b == 0)
        printf("Erro: divisao por zero!\n");
    else {
			 resposta = divisao(a,b);
			 printf("a resposta: %d\n", resposta);
	        }
			break;
	 
			case 4:
				printf("digite dois numeros\n");
				scanf("%d", &a);
				scanf("%d", &b);
				resposta = menos(a,b);
				printf("a resposta: %d\n", resposta);
			break;
	 
			default:
				printf("essa nao es uma resposta valida\n");
		}
	}while(calculo != 0);
 
    return 0;
}

void menu()
{
printf("========================\n");
printf("1 - Soma\n");
printf("2 - Multiplicacao\n");
printf("3 - Divisao\n");
printf("4 - Subtracao\n");
printf("0 - Sair\n");
printf("========================\n");
printf("Digite uma opcao:\n");

}

int soma (int a, int b){
return( a + b );}


int multiplicacao (int a, int b){
return( a * b );}

int menos (int a, int b){
return(a-b);}

int divisao (int a, int b){
return(a/b);}
