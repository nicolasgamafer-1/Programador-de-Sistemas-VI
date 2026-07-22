#include <stdio.h>

int main(){
	
	FILE *pont_arq;
	char palavra[20];
	double idade = 0.0;
	double total = 0.0;

	pont_arq = fopen("arquivo.txt", "a");

	if(pont_arq == NULL)
	{
		printf("ERRO! o arquivo nao foi aberto\n");
	}
	else
	{
		printf("o arquivo foi aberto com sucesso!\n");

		for (int i = 0; i < 2; ++i)
		{
			printf("escreva seu nome:\n");
			scanf("%s", &palavra);
			printf("escreva sua idade:\n");
			scanf("%lf", &idade);
			fprintf(pont_arq, "%s\n%lf\n", palavra, idade);

		}
	}

	fclose(pont_arq);

	pont_arq = fopen("arquivo.txt", "r");

	if (pont_arq == NULL)
	{
		printf("ERRO! o arquivo nao foi aberto\n");
	}
	else
	{
		printf("o arquivo foi aberto com sucesso\n");
		printf("pessoas cadastradas:\n");

		for (int i = 0; i < 2; ++i)
		{
			fscanf(pont_arq, "%s %lf", palavra,&idade);
			printf("%s\n %lf\n", palavra, idade);
		}
	}

	fclose(pont_arq);


	return 0;
}