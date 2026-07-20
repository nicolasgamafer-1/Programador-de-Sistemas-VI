#include <stdio.h>
#include <string.h>

struct Aluno{
	char nome[50];
	int idade;
	float nota;
};

int main(){
	struct Aluno a1;

		printf("digite seu nome\n");
			scanf("%[^\n]", a1.nome);
			
		printf("digite sua idade\n");
			scanf("%d", &a1.idade);
			
		printf("digite sua nota\n");
			scanf("%f", &a1.nota);

		
		printf("nome: %s\n", a1.nome);
		printf("idade: %d\n", a1.idade);
		printf("nota: %.2f\n", a1.nota);
		
		return(0);
}
	