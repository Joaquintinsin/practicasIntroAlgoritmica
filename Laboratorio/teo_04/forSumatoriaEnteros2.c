// sumatoriaEnteros
#include <stdio.h>

int  n; //cantidad de numeros
int  i; // variable de control del para
int  s; // sumatoria de los n primeros numeros

int main(){
	printf("Ingrese la cantidad de numeros a sumar: ");
	scanf("%d",&n);
	s = 0;
	for (i=0; i<=n; i=++){ 
		s = s + i;
	}
	
	printf("La suma de los %d primeros numeros es: %d \n", n, s);
	
	return 0;
} 
