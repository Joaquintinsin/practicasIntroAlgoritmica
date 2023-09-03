#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NMAX 30

typedef struct {
	int ar[NMAX];
	int cant;
} TData;

void CargarDatos(TData* r);

int main( int argc, char **argv ) {
	TData res;
	
	CargarDatos(&res);
	
	return 0;
}

void CargarDatos(TData* r) {
	int i;
	
	srand(time(NULL));
	
	printf ("Ingrese cuántos números quiere cargar, hasta un máximo de 30: ");
	scanf ("%d", &(r->cant) );
	
	for ( i = 0; i < r->cant; i++ ) {
		r->ar[i] = rand() % (999-0)+0;	// r->ar[i] = rand() % (M-N)+N;	M es el rango maximo que varian los nros aleatorios. N es el rango minimo que varian los nros aleatorios.
		printf ("El nro %d aleatorio devuelto es: %d \n", i+1, (r->ar[i]) );
	}
}
