#include <stdio.h>

void Swap(float *a, float *b);

int main( int argc, char **argv ) {
	float n1, n2;
	printf("Introduzca dos valores xd \n");
	scanf("%f", &n1);
	scanf("%f", &n2);
	Swap(&n1,&n2);
	printf("El valor de n1 es %f \n", n1);
	printf("El valor de n2 es %f \n", n2);
	return 0;
}

void Swap(float *a, float *b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
