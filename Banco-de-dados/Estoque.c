#include <stdio.h>
#include <stdlib.h>
#include <C:\msys64\mingw64\include\libpq-fe.h>

void menu();
int insert ();
int select ();
int delete ();
int update ();



int main() 
{
	int calculo = 0, resposta = 0;
	
	const char *conninfo = "host=localhost port=5432 dbname=Estoque user=postgres password=admin";

PGconn *conn = PQconnectdb(conninfo);

if (PQstatus(conn) == CONNECTION_BAD){
	fprintf(stderr, "ERRO de conexao: %s\n", PQerrorMessage(conn));
	PQfinish(conn);
	return 1;
}	

printf("Conectado ao PostgreSQL com sucesso!\n\n");

PQfinish(conn);
	


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
			 resposta = insert ();
			break;
	 
			case 2:
			 resposta = select ();
			break;
			
			case 3:
			 resposta = delete ();
			break;
			
			case 4:
			 resposta = update ();
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
printf("1 - INSERT\n");
printf("2 - SELECT\n");
printf("3 - DELET\n");
printf("4 - UPDATE\n");
printf("0 - Sair\n");
printf("========================\n");
printf("Digite uma opcao:\n");

}

int insert (){
	char produto[15];
    int quantidade = 0;
    double preco = 0.0;
	int tamanho = 0;
	PGresult *res = NULL;
	
// String de conexão — ajuste os dados conforme seu banco
    const char *conninfo = "host=localhost port=5432 dbname=Estoque user=postgres password=admin";

    // Conecta ao banco
    PGconn *conn = PQconnectdb(conninfo);

    // Verifica se a conexão deu certo
    if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Erro de conexão: %s\n", PQerrorMessage(conn));
        PQfinish(conn);
        return 1;
    }

    printf("Conectado ao banco com sucesso!\n");
	
	printf("informe o nome: ");
	scanf("%s",produto);
	printf("informe a quantidade: ");
	scanf("%d",&quantidade);
	printf("informe o valor: ");
	scanf("%lf",&preco);
	
	tamanho = snprintf(NULL, 0,"INSERT INTO estoque (produto, quantidade, preco_unitario) VALUES ('%s', %d, %.2lf);",produto, quantidade, preco);
	tamanho = (tamanho + 1); // +1 para o '\0'
	
	// Comando INSERT
    char *sql = malloc(tamanho * sizeof(char));
	
	sprintf(sql,"INSERT INTO estoque (produto, quantidade, preco_unitario) VALUES ('%s', %d, %2.lf);", produto, quantidade, preco); 
    res = PQexec(conn, sql);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        fprintf(stderr, "Erro no INSERT: %s\n", PQerrorMessage(conn));
        PQclear(res);
        PQfinish(conn);
        return 1;
    }

    printf("Insercao realizada com sucesso!\n");
	free(sql);
    PQclear(res);
    PQfinish(conn);
    return 0;
	}


int select (){

    // String de conexão — ajuste os dados conforme seu banco
    const char *conninfo = "host=localhost port=5432 dbname=Estoque user=postgres password=admin";

    // Conecta ao banco
    PGconn *conn = PQconnectdb(conninfo);

    // Verifica se a conexão deu certo
    if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Erro de conexão: %s\n", PQerrorMessage(conn));
        PQfinish(conn);
        return 1;
    }

    printf("Conectado ao banco com sucesso!\n");

    // Executa uma consulta simples
    PGresult *res = PQexec(conn, "SELECT * FROM estoque;");

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        fprintf(stderr, "Erro na consulta: %s\n", PQerrorMessage(conn));
        PQclear(res);
        PQfinish(conn);
        return 1;
    }

    // Obtém o número de linhas e colunas
    int linhas = PQntuples(res);
    int colunas = PQnfields(res);

    printf("Total de linhas: %d\n", linhas);
    printf("Total de colunas: %d\n\n", colunas);

    // Imprime o nome das colunas
    for (int j = 0; j < colunas; j++) {
        printf("%-20s", PQfname(res, j));
    }
    printf("\n------------------------------------------------------------\n");

    // Percorre dinamicamente todas as linhas e colunas
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%-20s", PQgetvalue(res, i, j));
        }
        printf("\n");
    }

    // Libera os resultados e encerra
    PQclear(res);
    PQfinish(conn);
    return 0;
}

int delete (){
	
	int controle = 0;
	
	printf("Qual o numero do codigo do produto que voce quer escluir: ");
	scanf("%d", &controle);
	
    // String de conexão — ajuste os dados conforme seu banco
    const char *conninfo = "host=localhost port=5432 dbname=Estoque user=postgres password=admin";

    // Conecta ao banco
    PGconn *conn = PQconnectdb(conninfo);

    // Verifica se a conexão deu certo
    if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Erro de conexão: %s\n", PQerrorMessage(conn));
        PQfinish(conn);
        return 1;
    }

    printf("Conectado ao banco com sucesso!\n");

    // Executa um delete simples
    char query[256];
	snprintf(query, sizeof(query), "DELETE FROM estoque WHERE codigo = %d;", controle);
	PGresult *res = PQexec(conn, query);


    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        fprintf(stderr, "deletar: %s\n", PQerrorMessage(conn));
        PQclear(res);
        PQfinish(conn);
        return 1;
    }


    // Exibe o resultado da consulta
	for(int i = 0; i < 2;i++)
	{
		for(int y = 0; y < 4;y++)
		{
			printf("DADOS: %s\n", PQgetvalue(res, i, y));
		}
	}
	
    // Libera os resultados e encerra
    PQclear(res);
    PQfinish(conn);
    return 0;
	
}

int update (){
	
	char controle = [100];
	int controle2 = 0;
	int controle3 = 0;
	
	printf("qual o nome do produto o preco e a quantidade: ");
	scanf("%s", &controle);
	scanf("%d", &controle2);
	scanf("%d", &controle3);
	
    // String de conexão — ajuste os dados conforme seu banco
    const char *conninfo = "host=localhost port=5432 dbname=Estoque user=postgres password=admin";

    // Conecta ao banco
    PGconn *conn = PQconnectdb(conninfo);

    // Verifica se a conexão deu certo
    if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Erro de conexão: %s\n", PQerrorMessage(conn));
        PQfinish(conn);
        return 1;
    }

    printf("Conectado ao banco com sucesso!\n");

    // Executa um delete simples
    char query[256];
	snprintf(query, sizeof(query), "UPDATE estoque 
SET produto = '%s', quantidade = %d, preco_unitario = %d WHERE id = %d;", controle, controle2, controle3);
	PGresult *res = PQexec(conn, query);


    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        fprintf(stderr, "deletar: %s\n", PQerrorMessage(conn));
        PQclear(res);
        PQfinish(conn);
        return 1;
    }


    // Exibe o resultado da consulta
	for(int i = 0; i < 2;i++)
	{
		for(int y = 0; y < 4;y++)
		{
			printf("DADOS: %s\n", PQgetvalue(res, i, y));
		}
	}
	
    // Libera os resultados e encerra
    PQclear(res);
    PQfinish(conn);
    return 0;
	
}