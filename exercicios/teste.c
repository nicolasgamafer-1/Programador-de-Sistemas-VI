#include <stdio.h>

int main(){

int matrix[5][5];
int i = 0, j = 0;

for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int maior = matrix[0][0];
    int menor = matrix[0][0];
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(matrix[i][j] > maior) {
                maior = matrix[i][j];
            }
            if(matrix[i][j] < menor) {
                menor = matrix[i][j];
            }
        }
    }
    
    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {

            printf("%d", matrix[i][j]);
          }

          printf("\n");

      }

    return 0;
}