#include <stdio.h>

int main(){

int matrix[4][4];
int i = 0, j = 0, testo = 0;

for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            scanf("%d", &matrix[i][j]);

            (testo += matrix[i][j]);
        }
    }

    printf("a soma seles es %d \n", testo);

    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {

            printf("%d", matrix[i][j]);
          }

          printf("\n");

      }



    return 0;
}