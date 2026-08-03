#include <stdio.h>

int main() {
    int matriz[4][4];
    int soma = 0;


    printf("Digite os elementos da matriz 4x4:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nDiagonal Principal:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d ", matriz[i][i]);
        soma += matriz[i][i];
    }

    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {

            printf("%d", matriz[i][j]);
          }

          printf("\n");

      }


    printf("\n\nSoma = %d\n", soma);

    return 0;
}
