#include<stdio.h>

int main(){

double x2 = 0.0;
double y2 = 0.0;
double y1 = 0.0;
double x1 = 0.0;
double raiz = 0.0;
double x = 0.0;
double xk = 0.0;

scanf("%lf %lf", &x1, &y1);
scanf("%lf %lf", &x2, &y2);

x = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);

xk = x;

for(int i=0; i < 1000; i++)
{

raiz = 0.5*(xk + (x/xk));

xk = raiz;


}

printf("%.4lf\n", raiz);

return(0);

}