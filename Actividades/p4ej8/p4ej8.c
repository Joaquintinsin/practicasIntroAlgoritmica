#include <stdio.h>

int main(){
	int n;				// dato entrada
	int i;					// variable contador
	int res;				// almacenador del resultado de la multiplicacion
	
	printf("¿La tabla de qué número quiere? \n");
	scanf("%d",&n);
	
	i = 0;
	while ( i <= 10 ) {
		res = n * i;
		printf("%d x %d = %d \n", n, i, res);
		i++;
	}
	
	return 0;
}

