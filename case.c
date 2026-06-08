#include <stdio.h>
 
int main() {
int dia = 0;

printf("fale um numero de 1 a 7:\n");
scanf("%d", &dia);

 switch (dia)
 {
 case 1:
 printf("esse numero representa domingo\n");
 break;
 
 case 2:
 printf("esse numero representa segunda\n");
 break;
 
 case 3:
 printf("esse numero representa terca\n");
 break;
 
 case 4:
 printf("esse numero representa quarta\n");
 break;
 
 case 5:
 printf("esse numero representa quinta\n");
 break;
 
 case 6:
 printf("esse numero representa sexta\n");
 break;
 
 case 7:
 printf("esse numero representa sabado\n");
 break;
 
 default:
 printf("esse numero nao representa um dia da semana\n");
 }
 
    return 0;
}