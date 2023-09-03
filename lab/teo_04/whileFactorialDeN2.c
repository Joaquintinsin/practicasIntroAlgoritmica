// factorialDeN
#include <stdio.h>

int n, k, factorial;

int main(){
	factorial=1;
	k=1;
	do {
		printf("Ingrese el numero del que desea conocer el factorial "); 
		scanf("%d",&n);
	} while (n<0); // (n>=0)
	
	while (k<=n) {
		factorial=factorial*k;
		k++; 
	}; 

	printf("El factorial es: %d", factorial);

	return 0;
}
