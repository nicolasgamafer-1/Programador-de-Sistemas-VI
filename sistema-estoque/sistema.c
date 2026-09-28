#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <libpq-fe.h> // Incluído para conectar ao PostgreSQL

#define MAX_SIZE_DESCRICAO 25
#define MAX_SIZE_V_STRUCT 1000

typedef struct Estoque
{
	char produto[MAX_SIZE_DESCRICAO];
	int codigo;
	int quantidade;
	double preco_unitario;
} estq;

#include "MinhasFuncoes.h"

int main()
{
	system("color 07");
	system("chcp 65001");
	system("cls");

	// 1. Inicializa a conexão com o PostgreSQL
	// AJUSTE 'sua_senha' e 'sistema_estoque' conforme seu banco de dados
	PGconn *conn = PQconnectdb("host=localhost port=5432 dbname=sistema_estoque user=postgres password=sua_senha");

	if (PQstatus(conn) == CONNECTION_BAD)
	{
		fprintf(stderr, "Erro ao conectar ao PostgreSQL: %s\n", PQerrorMessage(conn));
		PQfinish(conn);
		return 1;
	}

	int escolha = 0;
	estq deposito[MAX_SIZE_V_STRUCT];

	BarraDeCarregamento();
	/*INICIALIZO MEU VETOR DE ESTRUTURA TODO NULO*/
	NullStruct(deposito);

	do
	{
		Menu();
		scanf("%d", &escolha);
		switch (escolha)
		{
			/*CADASTRO DE PRODUTOS NO ARQUIVO*/
			case 1:
				system("cls");
				CadastroDeProdutos(deposito);
				break;

			/*LISTAR PRODUTOS DO BANCO DE DADOS*/
			case 2:
				system("cls");
				ListarProdutos(conn, 0);
				break;

			/*BUSCAR PRODUTO POR CODIGO NO BANCO DE DADOS*/
			case 3:
			{
				system("cls");
				int cod;
				printf("Informe o CODIGO do produto que deseja procurar: ");
				scanf("%d", &cod);
				ListarProdutos(conn, cod);
				break;
			}

			/*ALTERAR QUANTIDADE DE PRODUTOS DO ESTOQUE POR CODIGO*/
			case 4:
				system("cls");
				AlterarQuantidadeProdutos(deposito);
				break;

			/*CALCULAR VALOR TOTAL DE PRODUTOS NO ESTOQUE*/
			case 5:
				system("cls");
				CalcularValorTotalEstoque(deposito);
				break;

			/*ORDENAR MINHAS LISTAGEM POR FILTROS */
			case 6:
				system("cls");
				FiltrarOrdenar(deposito);
				break;

			/*APAGAR MEU BANCO DE DADOS */
			case 7:
				system("cls");
				ApagarOsDadosDoSistema(deposito);
				system("cls");
				printf("\nEXCLUSAO CONCLUIDA\n");
				break;

			/*FINALIZAR O SISTEMA*/
			case 8:
				system("cls");
				printf("Sistema Finalizado\n");
				Som(L"Windows Shutdown.wav", 500);
				break;

			default:
				system("cls");
				printf("\nATENCAO: Escolha uma das opcoes disponiveis no menu!\n\n");
		}

	} while (escolha != 8);

	// 2. Encerra a conexão ao sair do programa
	PQfinish(conn);

	return 0;
}