#include <stdio.h>

int main(){
    int matrix[3][4];
    int i = 0, j = 0;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int linhaDesejada1 = 0;
    int soma1 = 0;
    for (int j = 0; j < 4; j++) {
        soma1 += matrix[linhaDesejada1][j];
    }

    int linhaDesejada2 = 1;
    int soma2 = 0;
    for (int j = 0; j < 4; j++) {
        soma2 += matrix[linhaDesejada2][j];
    }

    int linhaDesejada3 = 2;
    int soma3 = 0;
    for (int j = 0; j < 4; j++) {
        soma3 += matrix[linhaDesejada3][j];
    }

    printf("Soma da linha 1: %d\n", soma1);
    printf("Soma da linha 2: %d\n", soma2);
    printf("Soma da linha 3: %d\n", soma3);

    return 0;
}
