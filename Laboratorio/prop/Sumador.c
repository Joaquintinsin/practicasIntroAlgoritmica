#include <stdio.h>

int main(){

	int n;			//	Dato entrada
	int i;				// Contador
	int sumador;	// Sumador/Acumulador

	printf ("Ingrese un número entero positivo y le sumaré los anteriores. \n");
	scanf ("%d", &n);
	sumador = 0;
	i = 1;

	while ( n >= 1 ){
		sumador = sumador + i;
		i = i + 1;
		n = n - 1;
	}
	
	printf ("El resultado de sumar todos los anteriores es %d. \n", sumador);
	
	return 0;
}

