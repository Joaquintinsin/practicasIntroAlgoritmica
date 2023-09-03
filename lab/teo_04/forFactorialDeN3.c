// factorialDeN
#include <stdio.h>

int n, k, factorial;

int main(){
	factorial=1;
	printf("Ingrese el numero del que desea conocer el factorial "); 
	scanf("%d",&n);
	for (k=1; k<=n; k++) {
		factorial=factorial*k;
	}; 

	printf("El factorial de %d es: %d", n, factorial);

	return 0;
}
