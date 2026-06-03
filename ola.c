#include <stdio.h>

int main(){
	int num1=0, num2=0, num3=0;
	printf("mede dois numeros inteiros que eu os somarei:\n ");
	scanf("%d", &num1);
	printf("proximo:\n ");
	scanf("%d", &num2);
	
	num3 = num1+num2;
	printf("o resultado da: %d", num3);
	
	return (0);
} 