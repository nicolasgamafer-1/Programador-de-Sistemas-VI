#include <stdio.h>
#include <string.h>

struct Livro {
    char titulo[100];
    char autor[100];
    float preco;
};

int main() {
  
    struct Livro meuLivro;

    strcpy(meuLivro.titulo, "POEMA SATIRICO");
    strcpy(meuLivro.autor, "GREGORIO DE MATOS");
    meuLivro.preco = 49.90;

    printf("--- Dados do Livro ---\n");
    printf("Titulo: %s\n", meuLivro.titulo);
    printf("Autor:  %s\n", meuLivro.autor);
    printf("Preco:  R$ %.2f\n", meuLivro.preco);

    return 0;
}