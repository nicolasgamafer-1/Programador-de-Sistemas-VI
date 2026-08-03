#include <stdio.h>

int main(){
    int matrix[4][3];
    int i = 0, j = 0;

    for(i = 0; i < 4; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int linhaDesejada1 = 0;
    int soma1 = 0;
    for (int i = 0; i < 4; i++) {
        soma1 += matrix[i][linhaDesejada1];
    }

    int linhaDesejada2 = 1;
    int soma2 = 0;
    for (int i = 0; i < 4; i++) {
        soma2 += matrix[i][linhaDesejada2];
    }

    int linhaDesejada3 = 2;
    int soma3 = 0;
    for (int i = 0; i < 4; i++) {
        soma3 += matrix[i][linhaDesejada3];
    }

    printf("Soma 1: %d\n", soma1);
    printf("Soma 2: %d\n", soma2);
    printf("Soma 3: %d\n", soma3);

    return 0;
}
