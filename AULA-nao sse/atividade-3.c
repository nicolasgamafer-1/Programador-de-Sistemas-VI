#include <stdio.h>
#include <string.h>

struct Endereco {
    char rua[100];
    int numero;
};

struct Pessoa {
    char nome[50];
    int idade;
    struct Endereco endereco;
};

int main() {
    struct Pessoa pessoa1;

    strcpy(pessoa1.nome, "Maria Silva");
    pessoa1.idade = 28;
    strcpy(pessoa1.endereco.rua, "sao joao");
    pessoa1.endereco.numero = 105;

    
    struct Pessoa *ptrPessoa = &pessoa1;

 
    printf("=== DADOS DA PESSOA ===\n");
    printf("Nome:     %s\n", ptrPessoa->nome);
    printf("Idade:    %d anos\n", ptrPessoa->idade);
    
    printf("Endereco: %s, N %d\n", ptrPessoa->endereco.rua, ptrPessoa->endereco.numero);


    return 0;
}