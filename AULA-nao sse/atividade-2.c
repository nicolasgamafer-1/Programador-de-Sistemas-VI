#include <stdio.h>

struct Aluno {
    char nome[50];
    float nota;
};

int main() {
  
    struct Aluno alunos[5];

    printf("=== CADASTRO DE ALUNOS ===\n");
    for (int i = 0; i < 5; i++) {
        printf("\nAluno %d:\n", i + 1);
        
        printf("Nome: ");
        scanf(" %49[^\n]", alunos[i].nome); 
        
        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
    }

    printf("\n=== LISTA DE ALUNOS ===\n");
    for (int i = 0; i < 5; i++) {
        printf("Aluno %d: %-20s | Nota: %.1f\n", i + 1, alunos[i].nome, alunos[i].nota);

    }

    return 0;
}