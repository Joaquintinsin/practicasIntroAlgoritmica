#include <stdio.h>

void Calcular(int x, int *max, int *min, int *med);
void InformarResultados(int vMax, int vMin, int vMed);
void PedirEntradasYCalcular(int iterador, int hastaSec, int entrada, int *max, int *min, int *med);

int main(){
	int cantSec;		// Dato. Almacena la cant de numeros que hay que iterar
	int num = 0;		// Dato. Almacena los nros de la secuencia y me quedo con el maximo y el minimo.
	int i = 1;			// Iterador. Inicializo en 1
	int valMax = 0;// Resultado. Inicializo en 0, almacenará el valor maximo.
	int valMin = 99999;// Resultado. Inicializo en un nro muy grande y almacena el valor mínimo
	int media;			// Resultado. Almacenará el valor del medio de la secuencia, relaciona a valMax y valMin
	
	printf ("Ingrese cuántos números posee la secuencia: ");
	scanf ("%d", &cantSec);
	
	PedirEntradasYCalcular(i, cantSec, num, &valMax, &valMin, &media);
	
	InformarResultados(valMax,valMin,media);
	
	return 0;
}

void Calcular(int x, int *max, int *min, int *med){
	if ( x >= *max ){
		*max = x;
	}
	if ( x <= *min ){
		*min = x;
	}
	*med = ( *max + *min ) / 2;
}

void PedirEntradasYCalcular(int iterador, int hastaSec, int entrada, int *max, int *min, int *med){
	while ( iterador <= hastaSec ) { 
		printf ("Ingrese el número de la posición %d de la secuencia: ", iterador);
		scanf ("%d", &entrada);
		printf ("\n");
		Calcular(entrada, max, min, med);
		iterador++;
	}
}

void InformarResultados(int vMax, int vMin, int vMed){	
	printf ("El valor máximo registrado fue: %d \n", vMax);
	printf ("El valor mínimo registrado fue: %d \n", vMin);
	printf ("El valor del medio registrado fue: %d \n", vMed);
}
