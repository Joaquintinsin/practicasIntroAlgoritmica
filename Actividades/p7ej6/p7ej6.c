#include <stdio.h>

#define NMAX 60

typedef struct {
	int ar[NMAX];
	int cant;
} TData;

void CargarArreglo(TData* entry);
float Sumar(TData entry);

int main( int argc, char **argv ) {
	TData entrada;
	float sumaVentas;
	
	CargarArreglo(&entrada);
	sumaVentas = Sumar(entrada);
	printf ("Las ventas sumaron un total de: %f \n", sumaVentas);
	
	return 0;
}

void CargarArreglo(TData* entry) {
	int i;
	
	printf ("Ingrese cuántas ventas totales mensuales quiere cargar: ");
	scanf ("%d", &(entry->cant) );
	
	for (i = 1; i <= (entry->cant); i++){
		printf ("Ingrese la venta nro %d: ", i);
		scanf ("%d", &(entry->ar[i]) );
	}
}

float Sumar(TData entry) {
	int i;
	float suma;
	
	suma = 0;
	
	for ( i = 0; i <= entry.cant; i++ ) {
		suma = suma + entry.ar[i];
	}
	
	return suma;
}
