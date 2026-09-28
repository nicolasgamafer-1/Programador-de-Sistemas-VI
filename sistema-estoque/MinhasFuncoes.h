#include "cores.h"
#include <mmsystem.h> // Para a função PlaySound -lwinmm
#include <libpq-fe.h>

void Menu();
void Filtro();
void Ordem();
void Som(const wchar_t *arquivo, int tempo);
void ZerarDescricao(char * descricao);
void NullStruct(estq * pnt_deposito);
void CadastroDeProdutos(estq * pnt_deposito);
void ListarProdutos(PGconn *conn, int cod);
void AlterarQuantidadeProdutos(estq * pnt_deposito);
void CalcularValorTotalEstoque(estq * pnt_deposito);
void Imprimir(estq * pnt_deposito, int tam);
void BubbleSortCodigo(estq * pnt_deposito, int opcao, int tamanho);
void BubbleSortQuantidade(estq * pnt_deposito, int opcao, int tamanho);
void BubbleSortPreco(estq * pnt_deposito, int opcao, int tamanho);
int CompararPalavras(char *palavra1, char *palavra2);
void FiltrarOrdenar(estq * pnt_deposito);
void ApagarOsDadosDoSistema(estq * pnt_deposito);
void BarraDeCarregamento();

void Som(const wchar_t *arquivo, int tempo) 
{
    wchar_t caminho[300] = L"C:\\Windows\\Media\\";
    if (wcslen(caminho) + wcslen(arquivo) < sizeof(caminho) / sizeof(wchar_t)) 
    {
        wcscat(caminho, arquivo);
        PlaySoundW(caminho, NULL, SND_FILENAME | SND_ASYNC);
    }
    else
    {
        wprintf(L"Erro: nome de arquivo muito grande.\n");
    }

    Sleep(tempo);
}

void BarraDeCarregamento() 
{
    int i, j;
    int total = 47;

    system("");

    printf(FG_AZUL "|***********************************************|" RESET "\n");
    printf("%s|*           %sPROCESSANDO REQUISIÇÃO%s            *|%s\n", FG_AZUL, RESET, FG_AZUL, RESET);
    printf("%s|***********************************************|%s\n", FG_AZUL, RESET);
    printf("%s|", FG_AZUL);

    for (i = 0; i <= total; i++) 
    {
        int percent = (i * 100) / total;

        printf("\r%s|", FG_AZUL);

        printf(BG_VERDE);
        for (j = 0; j < i; j++)
        {
            printf(" ");
        }
        printf(BG_PRETO);
        for (j = i; j < total; j++)
        {
            printf(" ");
        }
        printf(RESET "%s| %3d%%", FG_AZUL, percent);

        fflush(stdout);
        Sleep(10);
    }

    printf(RESET "\n%s|***********************************************|%s\n", FG_AZUL, RESET);
    printf("%s|*                %sCONCLUÍDO!%s                    *|%s\n", FG_AZUL, FG_VERDE, FG_AZUL, RESET);
    printf("%s|***********************************************|%s\n\n", FG_AZUL, RESET);
    Som(L"Windows Logon.wav",500);
}

void Menu()
{
    printf(FG_AZUL "|***********************************************|" RESET "\n");
    printf("%s|*       %sBEM VINDO AO SISTEMA DE ESTOQUE%s       *|%s\n",FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|*     %sESCOLHA A FUNCAO QUE DESEJA UTILIZAR%s    *|%s\n",FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|***********************************************|%s\n",FG_AZUL,RESET);
    printf("%s|--%sCOD%s--|---------------%sDESCRICAO%s---------------|%s\n",FG_AZUL,RESET,FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|%s   1   %s|     %sCadastrar produto(s);%s             |%s\n",FG_AZUL,RESET,FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|%s   2   %s|     %sListar produtos;%s                  |%s\n",FG_AZUL,RESET,FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|%s   3   %s|     %sBuscar produto por codigo;%s        |%s\n",FG_AZUL,RESET,FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|%s   4   %s|     %sAtualizar quantidade em estoque;%s  |%s\n",FG_AZUL,RESET,FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|%s   5   %s|     %sCalcular valor total do estoque;%s  |%s\n",FG_AZUL,RESET,FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|%s   6   %s|     %sFiltrar e Ordenar;%s                |%s\n",FG_AZUL,RESET,FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|%s   7   %s|     %sApagar TODOS os Itens do estoque;%s |%s\n",FG_AZUL,RESET,FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|%s   8   %s|     %sEncerrar programa;%s                |%s\n",FG_AZUL,RESET,FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|-----------------------------------------------|%s\n",FG_AZUL,RESET);
    printf("%s|***********************************************|%s\n\n",FG_AZUL,RESET);
}

void Filtro()
{
    printf("%s|***********************************************|%s\n",FG_AZUL,RESET);
    printf("%s|*       %sESCOLHA O PARAMETRO DE ORDENACAO%s      *|%s\n",FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|*     %sESCOLHA A FUNCAO QUE DESEJA UTILIZAR%s    *|%s\n",FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|***********************************************|%s\n",FG_AZUL,RESET);
    printf("%s|--%sCOD%s--|----------------%sORDENAR%s----------------|%s\n",FG_AZUL,RESET,FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|%s   1   %s|     %sOrdernar por nome do produto(s);%s  |%s\n",FG_AZUL,RESET,FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|%s   2   %s|     %sOrdernar por codigo do produto;%s   |%s\n",FG_AZUL,RESET,FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|%s   3   %s|     %sOrdernar por quantidade;%s          |%s\n",FG_AZUL,RESET,FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|%s   4   %s|     %sOrdernar por valor do produto;%s    |%s\n",FG_AZUL,RESET,FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|-----------------------------------------------|%s\n",FG_AZUL,RESET);
    printf("%s|***********************************************|%s\n\n",FG_AZUL,RESET);
}

void Ordem()
{
    printf("%s|***************************************************|%s\n",FG_AZUL,RESET);
    printf("%s|*         %sESCOLHA O FORMA DE ORDENACAO%s             *|%s\n",FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|*       %sESCOLHA A OPCAO QUE DESEJA UTILIZAR%s       *|%s\n",FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|***************************************************|%s\n",FG_AZUL,RESET);
    printf("%s|--%sCOD%s--|----------------%sORDENAR%s--------------------|%s\n",FG_AZUL,RESET,FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|%s   1   %s|     %sCrescente - Alfabetica Crescente;%s     |%s\n",FG_AZUL,RESET,FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|%s   2   %s|     %sDecrescente - Alfabetica Decrescente;%s |%s\n",FG_AZUL,RESET,FG_AZUL,RESET,FG_AZUL,RESET);
    printf("%s|---------------------------------------------------|%s\n",FG_AZUL,RESET);
    printf("%s|***************************************************|%s\n\n",FG_AZUL,RESET);
}

void ZerarDescricao(char * descricao)
{
    for(int i = 0; i < MAX_SIZE_DESCRICAO; i++)
    {
        descricao[i] = '\0';
    }
}

void NullStruct(estq * pnt_deposito)
{
    for(int i = 0; i < MAX_SIZE_V_STRUCT; i++)
    {
        ZerarDescricao(pnt_deposito[i].produto);
        pnt_deposito[i].codigo = -1;
        pnt_deposito[i].quantidade = -1;
        pnt_deposito[i].preco_unitario = -1.0;
    }
}

void CadastroDeProdutos(estq * pnt_deposito)
{
    int quantidade = 0;
    FILE * arquivo;
    
    arquivo = fopen("arquivo.txt","a");
    
    printf("Informe a quantidade de itens que deseja cadastrar\n");
    scanf("%d",&quantidade);
    printf("\n");
    
    if(quantidade > MAX_SIZE_V_STRUCT)
    {
        printf("Nessa versão do sistemas permitimos um cadastro máximo de 1000 itens\n");
        printf("Entre em contato com o fornecedor do sistema para mais informacoes\n");
    }
    else
    {
        if(arquivo != NULL)
        {
            for(int i = 0; i < quantidade; i++)
            {
                printf("Informe o NOME do produto: ");
                scanf(" %[^\n]", pnt_deposito[i].produto);
                printf("Informe o CODIGO do produto: ");
                scanf("%d", &pnt_deposito[i].codigo);
                printf("Informe a QUANTIDADE do produto: ");
                scanf("%d", &pnt_deposito[i].quantidade);
                printf("Informe o PRECO UNITARIO do produto: ");
                scanf("%lf", &pnt_deposito[i].preco_unitario);
                printf("\n");
                
                fprintf(arquivo,"%s\n%d\n%d\n%.2lf\n",pnt_deposito[i].produto,pnt_deposito[i].codigo,pnt_deposito[i].quantidade,pnt_deposito[i].preco_unitario);
            }
            
            fclose(arquivo);
            system("cls");
            printf("\n\nCADASTRO CONCLUIDO\n\n");
            Som(L"tada.wav",500);
        }
        else
        {
            printf("ERRO ao acessar o arquivo contate o administrador do sistema\n");
        }
    }
}

void ListarProdutos(PGconn *conn, int cod)
{
    char query[256];

    if (cod <= 0) {
        snprintf(query, sizeof(query), "SELECT codigo, produto, quantidade, preco_unitario FROM estoque ORDER BY codigo;");
    } else {
        snprintf(query, sizeof(query), "SELECT codigo, produto, quantidade, preco_unitario FROM estoque WHERE codigo = %d;", cod);
    }

    PGresult *res = PQexec(conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        fprintf(stderr, "Erro na consulta: %s\n", PQerrorMessage(conn));
        PQclear(res);
        return;
    }

    int linhas = PQntuples(res);

    if (linhas == 0) {
        printf("\nNenhum produto encontrado.\n\n");
        PQclear(res);
        return;
    }

    printf("\n%s╔═════╦══════════════════════════╦════════════╦════════════════╗%s\n", FG_VERDE, RESET);
    printf("%s║%s COD %s║%s        DESCRICAO         %s║%s QUANTIDADE %s║%s VALOR UNITARIO %s║%s\n", FG_VERDE, RESET, FG_VERDE, RESET, FG_VERDE, RESET, FG_VERDE, RESET, FG_VERDE, RESET);

    for (int i = 0; i < linhas; i++) {
        int codigo = atoi(PQgetvalue(res, i, 0));
        char *produto = PQgetvalue(res, i, 1);
        int quantidade = atoi(PQgetvalue(res, i, 2));
        double preco_unitario = atof(PQgetvalue(res, i, 3));

        if (i % 2 == 0) {
            printf("%s║%s%s%s%5d%s%s║%s%s%s%-26.26s%s%s║%s%s%s%12d%s%s║%s%s%s%16.2lf%s%s║%s\n",
                   FG_VERDE, RESET, FG_PRETO, BG_BRANCO, codigo, RESET,
                   FG_VERDE, RESET, FG_PRETO, BG_BRANCO, produto, RESET,
                   FG_VERDE, RESET, FG_PRETO, BG_BRANCO, quantidade, RESET,
                   FG_VERDE, RESET, FG_PRETO, BG_BRANCO, preco_unitario, RESET,
                   FG_VERDE, RESET);
        } else {
            printf("%s║%s%s%s%5d%s%s║%s%s%s%-26.26s%s%s║%s%s%s%12d%s%s║%s%s%s%16.2lf%s%s║%s\n",
                   FG_VERDE, RESET, FG_BRANCO, BG_PRETO, codigo, RESET,
                   FG_VERDE, RESET, FG_BRANCO, BG_PRETO, produto, RESET,
                   FG_VERDE, RESET, FG_BRANCO, BG_PRETO, quantidade, RESET,
                   FG_VERDE, RESET, FG_BRANCO, BG_PRETO, preco_unitario, RESET,
                   FG_VERDE, RESET);
        }
    }

    printf("%s╚═════╩══════════════════════════╩════════════╩════════════════╝%s\n\n", FG_VERDE, RESET);

    PQclear(res);
}

void AlterarQuantidadeProdutos(estq * pnt_deposito)
{
    FILE * arquivo;
    int i = 0;
    int cod = 0;
    int quantidade = 0;
    arquivo = fopen("arquivo.txt","r");
    
    printf("Informe o CODIGO do produto que deseja modificar: ");
    scanf("%d",&cod);
    
    if(arquivo != NULL)
    {
        printf("\n");
        printf("%s╔═════╦══════════════════════════╦════════════╦════════════════╗%s\n",FG_VERDE,RESET);
        printf("%s║%s COD %s║%s        DESCRICAO         %s║%s QUANTIDADE %s║%s VALOR UNITARIO %s║%s\n",FG_VERDE,RESET,FG_VERDE,RESET,FG_VERDE,RESET,FG_VERDE,RESET,FG_VERDE,RESET);
        while(fscanf(arquivo,"%[^\n]\n%d\n%d\n%lf\n",pnt_deposito[i].produto,&pnt_deposito[i].codigo,&pnt_deposito[i].quantidade,&pnt_deposito[i].preco_unitario) != EOF)
        {
            if(pnt_deposito[i].codigo == cod)
            {
                if(i%2 == 0)
                {
                    printf("%s║%s%s%s%5d%s%s║%s%s%s%26s%s%s║%s%s%s%12d%s%s║%s%s%s%16.2lf%s%s║%s\n",FG_VERDE,RESET,FG_PRETO,BG_BRANCO,pnt_deposito[i].codigo,RESET,FG_VERDE,RESET,FG_PRETO,BG_BRANCO,pnt_deposito[i].produto,RESET,FG_VERDE,RESET,FG_PRETO,BG_BRANCO,pnt_deposito[i].quantidade,RESET,FG_VERDE,RESET,FG_PRETO,BG_BRANCO,pnt_deposito[i].preco_unitario,RESET,FG_VERDE,RESET);
                }
                else
                {
                    printf("%s║%s%s%s%5d%s%s║%s%s%s%26s%s%s║%s%s%s%12d%s%s║%s%s%s%16.2lf%s%s║%s\n",FG_VERDE,RESET,FG_BRANCO,BG_PRETO,pnt_deposito[i].codigo,RESET,FG_VERDE,RESET,FG_BRANCO,BG_PRETO,pnt_deposito[i].produto,RESET,FG_VERDE,RESET,FG_BRANCO,BG_PRETO,pnt_deposito[i].quantidade,RESET,FG_VERDE,RESET,FG_BRANCO,BG_PRETO,pnt_deposito[i].preco_unitario,RESET,FG_VERDE,RESET);
                }
                printf("%s╚═════╩══════════════════════════╩════════════╩════════════════╝%s\n\n",FG_VERDE,RESET);
                printf("informe a NOVA quantidade\n");
                scanf("%d",&quantidade);
                pnt_deposito[i].quantidade = quantidade;
            }
            i++;
        }
        fclose(arquivo);
        
        arquivo = fopen("arquivo.txt","w");
        if(arquivo != NULL)
        {
            for(int y = 0; y < i; y++)
            {
                fprintf(arquivo,"%s\n%d\n%d\n%.2lf\n",pnt_deposito[y].produto,pnt_deposito[y].codigo,pnt_deposito[y].quantidade,pnt_deposito[y].preco_unitario);
            }
            fclose(arquivo);
            system("cls");
            printf("\n\nATUALIZACAO CONCLUIDA\n\n");
        }   
        else
        {
            printf("ERRO ao acessar o arquivo contate o administrador do sistema\n");
        }
    }
    else
    {
        printf("ERRO ao acessar o arquivo contate o administrador do sistema\n");
    }
}

void CalcularValorTotalEstoque(estq * pnt_deposito)
{
    FILE * arquivo;
    int i = 0;
    double valor_total_estoque = 0.0;
    arquivo = fopen("arquivo.txt","r");
    
    if(arquivo != NULL)
    {
        printf("\n");
        printf("%s╔═════╦══════════════════════════╦════════════╦════════════════╗%s\n",FG_VERDE,RESET);
        printf("%s║%s COD %s║%s        DESCRICAO         %s║%s QUANTIDADE %s║%s VALOR UNITARIO %s║%s\n",FG_VERDE,RESET,FG_VERDE,RESET,FG_VERDE,RESET,FG_VERDE,RESET,FG_VERDE,RESET);
        while(fscanf(arquivo,"%[^\n]\n%d\n%d\n%lf\n",pnt_deposito[i].produto,&pnt_deposito[i].codigo,&pnt_deposito[i].quantidade,&pnt_deposito[i].preco_unitario) != EOF)
        {
            if(i%2 == 0)
            {
                printf("%s║%s%s%s%5d%s%s║%s%s%s%26s%s%s║%s%s%s%12d%s%s║%s%s%s%16.2lf%s%s║%s\n",FG_VERDE,RESET,FG_PRETO,BG_BRANCO,pnt_deposito[i].codigo,RESET,FG_VERDE,RESET,FG_PRETO,BG_BRANCO,pnt_deposito[i].produto,RESET,FG_VERDE,RESET,FG_PRETO,BG_BRANCO,pnt_deposito[i].quantidade,RESET,FG_VERDE,RESET,FG_PRETO,BG_BRANCO,pnt_deposito[i].preco_unitario,RESET,FG_VERDE,RESET);
            }
            else
            {
                printf("%s║%s%s%s%5d%s%s║%s%s%s%26s%s%s║%s%s%s%12d%s%s║%s%s%s%16.2lf%s%s║%s\n",FG_VERDE,RESET,FG_BRANCO,BG_PRETO,pnt_deposito[i].codigo,RESET,FG_VERDE,RESET,FG_BRANCO,BG_PRETO,pnt_deposito[i].produto,RESET,FG_VERDE,RESET,FG_BRANCO,BG_PRETO,pnt_deposito[i].quantidade,RESET,FG_VERDE,RESET,FG_BRANCO,BG_PRETO,pnt_deposito[i].preco_unitario,RESET,FG_VERDE,RESET);
            }
            valor_total_estoque += pnt_deposito[i].quantidade * pnt_deposito[i].preco_unitario;
            i++;
        }
        printf("%s╚═════╩══════════════════════════╩════════════╩════════════════╝%s\n\n",FG_VERDE,RESET);  
        printf("O valor total em mercadoria em seu estoque e: R$ %.2lf\n\n",valor_total_estoque);
        fclose(arquivo);
    }
    else
    {
        printf("ERRO ao acessar o arquivo contate o administrador do sistema\n");
    }
}

void Imprimir(estq * pnt_deposito, int tam)
{
    int i = 0;
    printf("\n");
    printf("%s╔═════╦══════════════════════════╦════════════╦════════════════╗%s\n",FG_VERDE,RESET);
    printf("%s║%s COD %s║%s        DESCRICAO         %s║%s QUANTIDADE %s║%s VALOR UNITARIO %s║%s\n",FG_VERDE,RESET,FG_VERDE,RESET,FG_VERDE,RESET,FG_VERDE,RESET,FG_VERDE,RESET);
    for(i = 0; i < tam; i++)
    {
        if(i%2 == 0)
        {
            printf("%s║%s%s%s%5d%s%s║%s%s%s%26s%s%s║%s%s%s%12d%s%s║%s%s%s%16.2lf%s%s║%s\n",FG_VERDE,RESET,FG_PRETO,BG_BRANCO,pnt_deposito[i].codigo,RESET,FG_VERDE,RESET,FG_PRETO,BG_BRANCO,pnt_deposito[i].produto,RESET,FG_VERDE,RESET,FG_PRETO,BG_BRANCO,pnt_deposito[i].quantidade,RESET,FG_VERDE,RESET,FG_PRETO,BG_BRANCO,pnt_deposito[i].preco_unitario,RESET,FG_VERDE,RESET);
        }
        else
        {
            printf("%s║%s%s%s%5d%s%s║%s%s%s%26s%s%s║%s%s%s%12d%s%s║%s%s%s%16.2lf%s%s║%s\n",FG_VERDE,RESET,FG_BRANCO,BG_PRETO,pnt_deposito[i].codigo,RESET,FG_VERDE,RESET,FG_BRANCO,BG_PRETO,pnt_deposito[i].produto,RESET,FG_VERDE,RESET,FG_BRANCO,BG_PRETO,pnt_deposito[i].quantidade,RESET,FG_VERDE,RESET,FG_BRANCO,BG_PRETO,pnt_deposito[i].preco_unitario,RESET,FG_VERDE,RESET);
        }
    }
    printf("%s╚═════╩══════════════════════════╩════════════╩════════════════╝%s\n\n",FG_VERDE,RESET);  
}

void BubbleSortCodigo(estq * pnt_deposito, int opcao, int tamanho)
{
    estq aux;
    if(opcao == 1)
    {   
        for(int i = 0; i < tamanho; i++)
        {
            for(int k = 0; k < tamanho-1; k++)
            {
                if(pnt_deposito[i].codigo < pnt_deposito[k].codigo)
                {
                    aux = pnt_deposito[i];
                    pnt_deposito[i] = pnt_deposito[k];
                    pnt_deposito[k] = aux;
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < tamanho; i++)
        {
            for(int k = 0; k < tamanho-1; k++)
            {
                if(pnt_deposito[i].codigo > pnt_deposito[k].codigo)
                {
                    aux = pnt_deposito[i];
                    pnt_deposito[i] = pnt_deposito[k];
                    pnt_deposito[k] = aux;
                }
            }
        }
    }
}

void BubbleSortQuantidade(estq * pnt_deposito, int opcao, int tamanho)
{
    estq aux;
    if(opcao == 1)
    {   
        for(int i = 0; i < tamanho; i++)
        {
            for(int k = 0; k < tamanho-1; k++)
            {
                if(pnt_deposito[i].quantidade < pnt_deposito[k].quantidade)
                {
                    aux = pnt_deposito[i];
                    pnt_deposito[i] = pnt_deposito[k];
                    pnt_deposito[k] = aux;
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < tamanho; i++)
        {
            for(int k = 0; k < tamanho-1; k++)
            {
                if(pnt_deposito[i].quantidade > pnt_deposito[k].quantidade)
                {
                    aux = pnt_deposito[i];
                    pnt_deposito[i] = pnt_deposito[k];
                    pnt_deposito[k] = aux;
                }
            }
        }
    }
}

void BubbleSortPreco(estq * pnt_deposito, int opcao, int tamanho)
{
    estq aux;
    if(opcao == 1)
    {   
        for(int i = 0; i < tamanho; i++)
        {
            for(int k = 0; k < tamanho-1; k++)
            {
                if(pnt_deposito[i].preco_unitario < pnt_deposito[k].preco_unitario)
                {
                    aux = pnt_deposito[i];
                    pnt_deposito[i] = pnt_deposito[k];
                    pnt_deposito[k] = aux;
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < tamanho; i++)
        {
            for(int k = 0; k < tamanho-1; k++)
            {
                if(pnt_deposito[i].preco_unitario > pnt_deposito[k].preco_unitario)
                {
                    aux = pnt_deposito[i];
                    pnt_deposito[i] = pnt_deposito[k];
                    pnt_deposito[k] = aux;
                }
            }
        }
    }
}

int CompararPalavras(char *palavra1, char *palavra2)
{
    int i = 0;

    while (palavra1[i] != '\0' && palavra2[i] != '\0')
    {
        if (palavra1[i] < palavra2[i])
        {
           return(0);
        }
        else if (palavra1[i] > palavra2[i])
        {
            return(1);
        }
        i++;
    }

    if (palavra1[i] == '\0' && palavra2[i] == '\0')
    {
         return(0);
    }
    else if (palavra1[i] == '\0')
    {
        return(0);
    }
    else
    {
        return(1);
    }
}

void BubbleSortDescricao(estq * pnt_deposito, int opcao, int tamanho)
{
    estq aux;
    int troca = -1;

    for(int i = 0; i < tamanho; i++)
    {
        for(int k = 0; k < tamanho-1; k++)
        {
            if(opcao == 1)
            {
                troca = CompararPalavras(pnt_deposito[i].produto,pnt_deposito[k].produto);
                if(!troca)
                {
                    aux = pnt_deposito[i];
                    pnt_deposito[i] = pnt_deposito[k];
                    pnt_deposito[k] = aux;
                }
            }
            else
            {
                troca = CompararPalavras(pnt_deposito[i].produto,pnt_deposito[k].produto);
                if(troca)
                {
                    aux = pnt_deposito[i];
                    pnt_deposito[i] = pnt_deposito[k];
                    pnt_deposito[k] = aux;
                }
            }
        }
    }
}

void FiltrarOrdenar(estq * pnt_deposito)
{
    FILE * arquivo;
    int i = 0;
    int escolha = 0;
    arquivo = fopen("arquivo.txt","r");
    system("cls");
    if(arquivo != NULL)
    {
        while(fscanf(arquivo,"%[^\n]\n%d\n%d\n%lf\n",pnt_deposito[i].produto,&pnt_deposito[i].codigo,&pnt_deposito[i].quantidade,&pnt_deposito[i].preco_unitario) != EOF)
        {
            i++;
        }
        fclose(arquivo);        
        printf("Escolha como desenha ordenar sua listagem\n");
        Filtro();
        scanf("%d",&escolha);
        system("cls");
        switch(escolha)
        {
            case 1:
                printf("Informe a ordem que deseja\n");
                Ordem();
                scanf("%d",&escolha);
                switch(escolha)
                {
                    case 1:
                        BubbleSortDescricao(pnt_deposito, escolha, i);
                        system("cls");
                        Imprimir(pnt_deposito, i);
                    break;
                    case 2:
                        BubbleSortDescricao(pnt_deposito, escolha, i);
                        system("cls");
                        Imprimir(pnt_deposito, i);
                    break;
                    default:
                        printf("Escolha uma opcao valida no sistema!\n");
                }
            break;
            case 2:
                printf("Informe a ordem que deseja\n");
                Ordem();
                scanf("%d",&escolha);
                switch(escolha)
                {
                    case 1:
                        BubbleSortCodigo(pnt_deposito, escolha, i);
                        system("cls");
                        Imprimir(pnt_deposito, i);
                    break;
                    case 2:
                        BubbleSortCodigo(pnt_deposito, escolha, i);
                        system("cls");
                        Imprimir(pnt_deposito, i);
                    break;
                    default:
                        printf("Escolha uma opcao valida no sistema!\n");
                }
            break;
            case 3:
                printf("Informe a ordem que deseja\n");
                Ordem();
                scanf("%d",&escolha);
                switch(escolha)
                {
                    case 1:
                        BubbleSortQuantidade(pnt_deposito, escolha, i);
                        system("cls");
                        Imprimir(pnt_deposito, i);
                    break;
                    case 2:
                        BubbleSortQuantidade(pnt_deposito, escolha, i);
                        system("cls");
                        Imprimir(pnt_deposito, i);
                    break;
                    default:
                        printf("Escolha uma opcao valida no sistema!\n");
                }
            break;
            case 4:
                printf("Informe a ordem que deseja\n");
                Ordem();
                scanf("%d",&escolha);
                switch(escolha)
                {
                    case 1:
                        BubbleSortPreco(pnt_deposito, escolha, i);
                        system("cls");
                        Imprimir(pnt_deposito, i);
                    break;
                    case 2:
                        BubbleSortPreco(pnt_deposito, escolha, i);
                        system("cls");
                        Imprimir(pnt_deposito, i);
                    break;
                    default:
                        printf("Escolha uma opcao valida no sistema!\n");
                }
            break;
            default:
                printf("Escolha uma opcao valida no sistema!\n");
        }
    }
    else
    {
        printf("ERRO ao acessar o arquivo contate o administrador do sistema\n");
    }
}

void ApagarOsDadosDoSistema(estq * pnt_deposito)
{
    FILE * arquivo;
    arquivo = fopen("arquivo.txt","w");
    if(arquivo != NULL)
    {
            fprintf(arquivo,"%s","");
            fclose(arquivo);
    }   
    else
    {
        printf("ERRO ao acessar o arquivo contate o administrador do sistema\n");
    }
}