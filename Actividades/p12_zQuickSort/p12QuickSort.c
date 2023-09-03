/* elegir cualquier pivote y particionar el arreglo. que en el lado izq queden los mnores al pivot
 y a la derecha los mayores al pivot, en cualquier orden.
 separar en 3: menores que el pivot, el pivot, y los mayores que el pivot. llamar a quicksort
 con los menores y con los mayores. es un algoritmo recursivo
*/

#include <stdio.h>
#include <stdlib.h>

#define NMax 50

struct TData{
	int a[NMax];
	int cant;
};

void CargarArreglo(struct TData *arr);
void MostrarArreglo(struct TData arr);
void QuickSort(struct TData *arr, int *inf, int *sup);

int main( int argc, char **argv ) {
	struct TData arrMain;
	int x, y;
	
	printf ("1. Cargar \n");
	CargarArreglo(&arrMain);
	
	x = 0;
	y = arrMain.cant-1;
	
	printf ("2. Mostrar \n");
	MostrarArreglo(arrMain);
	printf ("3. Ordenar QuickSort \n");
	QuickSort(&arrMain, &x, &y);
	printf ("4. Mostrar \n");
	MostrarArreglo(arrMain);
	
	
	return 0;
}

void CargarArreglo(struct TData *arr){
	int i, elemento;
	
	printf("Cantidad a cargar del arreglo: ");
	do{
		scanf("%d", &arr->cant);
		if ( !( arr->cant >= 0 && arr->cant <= NMax ) ){
			printf ("Del 0 hasta %d \n", NMax);
		}
	} while ( !( arr->cant >= 0 && arr->cant <= NMax ) );
	for ( i = 0 ; i < arr->cant ; i++ ){
		printf ("Elemento nro %d: ", i+1);
		scanf ("%d", &elemento);
		arr->a[i] = elemento;
	}
}

void MostrarArreglo(struct TData arr){
	for ( int i = 0 ; i < arr.cant ; i++ ){
		printf ("Elemento %d del arreglo: %d \n", i+1, arr.a[i]);
	}
}

void QuickSort(struct TData *arr, int *inf, int *sup){
	int pivot, tam;
	int i, j;
	
	i = *inf;
	j = *sup;
	pivot = arr->a[((*inf+*sup) / 2)];
	while ( i <= j ){
		while ( arr->a[i] < pivot ){
			i++;
		}
		while ( arr->a[j] > pivot ){
			j--;
		}
		if ( i <= j ){
			tam = arr->a[i];
			arr->a[i] = arr->a[j];
			arr->a[j] = tam;
			i++;
			j--;
		}
	}
	if ( *inf < j ){
		QuickSort(arr, inf, &j);
	}
	if ( *sup > i ){
		QuickSort(arr, &i, sup);
	}
}
