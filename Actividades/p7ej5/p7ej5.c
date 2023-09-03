#include <stdio.h>

#define MAX 200

typedef struct {
	int a[MAX];
	int cant;
} TData;

void CargarNotas(TData* notas);
void PromedioNotas(TData notas, float* res);

int main( int argc, char **argv ) {
	TData misNotas;
	float promedio;
	
	CargarNotas(&misNotas);
	PromedioNotas(misNotas, &promedio);
	printf ("El promedio de todas las notas es %f \n", promedio);
	
	return 0;
}

void CargarNotas(TData* notas) {
	int i;
	
	printf ("Ingrese cuántas notas quiere cargar: ");
	scanf ("%d", &(notas->cant) );
	
	for (i = 1; i <= (notas->cant); i++){
		printf ("Ingrese la nota nro %d: ", i);
		scanf ("%d", &(notas->a[i]) );
	}
}

void PromedioNotas(TData notas, float* res) {
	int aux;
	float acum1, acum2;
	
	aux = 1;
	acum2 = 0;
	
	while (aux <= notas.cant) {
		acum1 = notas.a[aux];
		acum2 = acum1 + acum2;
		aux++;
	}
	
	*res = (acum2 / notas.cant);
}
