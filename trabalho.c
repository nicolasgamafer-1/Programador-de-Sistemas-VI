#include <stdio.h>

void menu();
double soma (double a, double b);
double menos (double a, double b);
double divisao (double a, double b);
double multiplicacao (double a, double b);
double raiz (double raiz);
double potencia (double a, int exp);
int mmc(int a, int b);
int mdc(int a, int b);
int fatorialsimples(int a);
int fatorialduplo(int a);

int main() 
{
	int calculo = 0, exp = 0, resp = 0;
	double a=0.0, b=0.0, resposta=0.0;
	int aint =0, bint=0;


	do 
	{

		menu();

		scanf("%d", &calculo);

		switch (calculo)
		{
			case 3:
				calculo = 3;
			break;
			
			case 2:
			 printf("digite dois numeros\n");
			 scanf("%lf", &a);
			 scanf("%lf", &b);
			 resposta = soma(a,b);
			 printf("a resposta: %.5lf\n", resposta);
			break;
	 
			case 7:
			 printf("digite dois numeros\n");
			 scanf("%lf", &a);
			 scanf("%lf", &b);
			 resposta = multiplicacao(a,b);
			 printf("a resposta: %.5lf\n", resposta);
			break;
	 
			case 4:
			 printf("digite dois numeros\n");
			 scanf("%lf", &a);
			 scanf("%lf", &b);
			 resposta = divisao(a,b);
			 printf("a resposta: %.5lf\n", resposta);
			break;
	 
			case 5:
				printf("digite dois numeros\n");
				scanf("%lf", &a);
				scanf("%lf", &b);
				if ( b == 0 )
				printf("erro: nao e possivel dividir por zero");
				else{
				resposta = menos(a,b);
				printf("a resposta: %.5lf\n", resposta);
				}
				
			break;
			
			case 8:
				printf("digite um numeros\n");
				scanf("%lf", &a);
				resposta = raiz(a);
				printf("a resposta: %.5lf\n", resposta);
				
			break;
			
			case 6:
			printf("digite dois numeros, o primeiro sera o numero que sera tirado a potencia e o segundo sera o espoente\n");
			scanf("%lf", &a);
			scanf("%d", &exp);
			resposta = potencia(a,exp);
			printf("a resposta: %.5lf\n", resposta);
			
		break;	
		
		case 1:
			printf("digite dois numeros\n");
			scanf("%d", &aint);
			scanf("%d", &bint);
			resp = mmc(aint,bint);
			printf("a resposta: %d\n", resp);
			
		break;
		
		case 0:
			printf("digite dois numeros\n");
			scanf("%d", &aint);
			scanf("%d", &bint);
			resp = mdc(aint,bint);
			printf("a resposta: %d\n", resp);
			
		break;
		
			case 10: 
		printf("Digite um numero\n");
		scanf("%d", &aint);
		resp = fatorialsimples(aint);
		if (aint < 0) {
			printf("Nao existe fatorial para numeros negativos.\n");
		} else if (aint > 12) {
			printf("Valores acima de 12 estouram o limite.\n");
		} else {
			printf("O fatorial e: %d\n", fatorialsimples(aint));
		}
		break;
			
			
			default:
				printf("essa nao es uma resposta valida\n");
		}
	}while(calculo != 3);
 
    return 0;
}

void menu()
{
printf("--------------------------------------------------------------------------------------------------------------\n");
printf("|Bem vindo a Calculadora 1.0.................................................................................|\n");
printf("|Escolha uma opcao...........................................................................................|\n");
printf("--------------------------------------------------------------------------------------------------------------\n");
printf("| 0 - MDC....................................................................................................|\n");
printf("| 1 - MMC....................................................................................................|\n");
printf("| 2 - Soma...................................................................................................|\n");
printf("| 3 - Sair...................................................................................................|\n");
printf("| 4 - Divisao................................................................................................|\n");
printf("| 5 - Subtracao..............................................................................................|\n");
printf("| 6 - Potenciacao............................................................................................|\n");
printf("| 7 - Multiplicacao..........................................................................................|\n");
printf("| 8 - Raiz Quadrada..........................................................................................|\n");
printf("| 9 - Fatorial Duplo (N!!) ..................................................................................|\n");
printf("| 10 - Fatorial Simples (N!) ................................................................................|\n");
printf("| 11 - Equacao do Segundo Grau...............................................................................|\n");
printf("--------------------------------------------------------------------------------------------------------------\n");

}

double soma (double a, double b)
{
	double c =0.0;
 c = a+b;	
	return(c);
}

double multiplicacao (double a, double b)
{
	double c =0.0;
	c = a*b;
return(c);
}

double menos (double a, double b)
{
	double c =0.0;
	c = a-b;
return(c);
}

double divisao (double a, double b)
{
	double c =0.0;
	c = a/b;
return(c);
}

double raiz (double a) 
{
	double raiz=0.0, b=0.0;
	
	b = a;

for(int i=0; i < 100; i++)
{

raiz = 0.5*(b + (a/b));

b = raiz;
}
return(raiz);
}

double potencia (double a, int exp)
{
	double resultado = 1.0;
	
	if(exp == 0.0)
	{
		return 1.0;
	}
	
	for(int i=0; i < exp; i++) {
		resultado *= a;
	}
	
	return(resultado);
}

int mmc (int a, int b)
{
	int c = 0;
	
	 if (a == 0 || b == 0) return 0;
	return (a / mdc(a, b)) * b; 
	
	return(c);
}

int mdc(int a, int b) {
    int resto;
    
    while (b != 0) {
        resto = a % b; 
        a = b;         
        b = resto;     
    }
    
    return (a); 
}

int fatorialsimples(int a) {
    int fatorial = 1;
    
    for (int i = 1; i <= a; i++) {
        fatorial *= i;
    }
    
    return (fatorial);
}

int fatorialduplo(int a) {
    int fatorial = 1;
    
    for (int i = 1; i <= a; i+2) {
        fatorial *= i;
    }
    
    return (fatorial);
}
