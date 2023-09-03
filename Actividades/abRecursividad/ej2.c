#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NMax 30
typedef struct{
	int a[NMax];
	int cant;
} TData;

int AuxValAbs(int x);
void CrearArreglo(TData *ar);
void MostrarArreglo(TData ar);

// inciso a
// {Pre: suma = 0}
long int SumatoriaArreglo(TData q, long int suma);
// inciso b
// {Pre: producto = 1, q.cant > 0}
void ProductoArreglo(TData q, int n, long int *producto);

int main( int argc, char **argv ) {
	int opcion;
	TData arreglo;
	
	printf ("1: Sumar los 30 elementos del arreglo \n");
	printf ("2: Multiplicar los elementos del arreglo del primero hasta un numero dado \n");
	do{
		scanf ("%d", &opcion);
	}while ( !(opcion == 1 || opcion == 2) );
	
	CrearArreglo(&arreglo);
	MostrarArreglo(arreglo);
	
	if ( opcion == 1 ){
		long int inicial = 0;
		long int res;
		res = SumatoriaArreglo(arreglo, inicial);
		printf ("resultado: %ld \n", res);
		
		res = 0;
		for (int i = 0 ; i < arreglo.cant ; i++)
			res = res + arreglo.a[i];
		printf ("deberia dar: %ld", res);
	}else{
		int posDeseada;
		long int res = 1;
		printf ("hasta qué posición quiere multiplicar? del 1 al 30: ");
		do{
			scanf ("%d", &posDeseada);
		} while ( posDeseada < 1 || posDeseada > NMax );
		ProductoArreglo(arreglo, posDeseada-1, &res);
		
		printf ("resultado: %ld \n", res);
	}
	
	return 0;
}

int AuxValAbs(int x){
	if ( x < 0 ){
		return -x;
	}else{
		return x;
	}
}

void CrearArreglo(TData *ar){
	#define RangoNros 10
	srand(time(NULL));
	ar->cant = NMax;
	for (int i = 0 ; i < ar->cant ; i++)
		ar->a[i] = rand() % RangoNros+1;
}

void MostrarArreglo(TData ar){
	for (int i = 0 ; i < ar.cant ; i++)
		printf ("ar.a[%d]: %d \n", i, ar.a[i]);
}

long int SumatoriaArreglo(TData q, long int suma){
	long int resultado = suma;
	
	if ( q.cant == -1 ){
		//*suma = *suma + q.a[q.cant];
		return resultado;
	}else{
		// printf ("q.cant: %d \n", q.cant);
		resultado = suma + q.a[q.cant];
		q.cant--;
		return SumatoriaArreglo(q, resultado);
	}
}

void ProductoArreglo(TData q, int n, long int *producto){
	if ( n == 0 || q.cant == 0 ){
		*producto = q.a[n] * (*producto);
	}else{
		*producto = q.a[n] * (*producto);
		q.cant--;
		ProductoArreglo(q, n-1, producto);
	}
}
