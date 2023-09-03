// sumatoriaEnteros
#include <stdio.h>

int n, k, sumatoria;

int main(){
	sumatoria=0;
	k=1;
	printf("Ingrese el numero hasta donde quiere la sumatoria "); 
	scanf("%d",&n);
	
	do {
		sumatoria = sumatoria+k;
		k++; 
	} while (k<=n); // !(k>n) 
	
	printf("La sumatoria es: %d", sumatoria);
	
	return 0;
}
