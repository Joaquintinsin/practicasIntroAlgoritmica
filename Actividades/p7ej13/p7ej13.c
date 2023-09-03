#include <stdio.h>

#define NMax 15

typedef struct{
	int a[NMax];
	int cant;
} TData;

void CargarArreglo(TData* arr);
void InsertarElemento(int elem, TData* arre);
void MostrarArreglo(TData arr);

int main( int argc, char **argv ) {
	TData arreglo;
	int elemento;
	
	CargarArreglo(&arreglo);
	
	MostrarArreglo(arreglo);
		/*
		for (int j=0; j<=arreglo.cant; j++){
			printf("Componente %d del arreglo cargado: %d \n", j, arreglo.a[j]);
		}
		*/
	printf ("Ingrese el nro que quiere ingresar al arreglo: ");
	scanf ("%d", &elemento);
	InsertarElemento(elemento, &arreglo);
	MostrarArreglo(arreglo);
		/*
		for (int k=0; k<=arreglo.cant; k++){
			printf("Componente %d del arreglo final: %d \n", k, arreglo.a[k]);
		}
		*/
	
	return 0;
}

void CargarArreglo(TData* arr){	// Accion CargarArreglo(resultado arr e TData)
	int i;
	i = 0;
	
	printf ("Ingrese cuántos elementos tiene el arreglo: ");
	scanf ("%d", &arr->cant);
	arr->cant = arr->cant - 1;	// resto uno porque sino hace el ingreso de 1 extra, podria restarse tambien en la condición del mientras
	while ( i <= arr->cant ){
		printf("Ingrese el componente %d del arreglo: ", (i+1));	// hago los printf con i+1 para que visualmente empiece desde el 1 y no desde el 0
		scanf ("%d", &arr->a[i]);
		i++;
	}
}

void InsertarElemento(int elem, TData* arre){	// Accion InsertarElemento(dato elem e (1..10), dato/resultado arre e TData)
	int i;
	int aux;
	
	i = 1;
	while ( i <= arre->cant ){
		if ( arre->a[i] > elem ){
			aux = arre->a[i];
			arre->a[i] = elem;
			elem = aux;
		}
		i++;
	}
	arre->cant++;
	arre->a[i] = elem;
}

void MostrarArreglo(TData arr){	// Accion MostrarArreglo(dato arr e TData)
	int i;
	for (i=0; i<=arr.cant; i++){
		printf("Componente %d del arreglo nuevo: %d \n", (i+1), arr.a[i]);	// hago los printf con i+1 para que visualmente empiece desde el 1 y no desde el 0
	}
}
