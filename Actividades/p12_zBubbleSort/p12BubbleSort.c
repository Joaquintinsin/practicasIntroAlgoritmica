// hacer un accion que cargue un arreglo de hasta 50 elementos, hacerle bubblesort y que lo muestre

#include <stdio.h>
#include <stdlib.h>

#define NMax 50

struct TData{
	int a[NMax];
	int cant;
};

void CargarArreglo(struct TData *arr);
void BubbleSort(struct TData* arr);
void MostrarArreglo(struct TData arr);

int main( int argc, char **argv ) {
	struct TData arrMain;
	
	printf ("1. Cargar \n");
	CargarArreglo(&arrMain);
	if ( arrMain.cant ){
		printf ("2. Mostrar \n");
		MostrarArreglo(arrMain);
		printf ("3. Ordenar Burbuja \n");
		BubbleSort(&arrMain);
		printf ("4. Mostrar \n");
		MostrarArreglo(arrMain);
	}else{
		printf ("No se quiso cargar nada. Cant arreglo: %d \n", arrMain.cant);
	}
	
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

void BubbleSort(struct TData* arr){
	int i, j; // (1..N+1);
	
	void Intercambiar(int *x, int *y){
		int tmp;
		
		tmp = *x;
		*x = *y;
		*y = tmp;
	}
	
	for ( i = (*arr).cant-1 ; i > 0 ; i-- ){
		for ( j = 0 ; j < i ; j++ ){
			if ( (*arr).a[j] < (*arr).a[j+1] ){
				Intercambiar(&((*arr).a[j]), &((*arr).a[j+1]));
			}
		}
	}
}

void MostrarArreglo(struct TData arr){
	for ( int i = 0 ; i < arr.cant ; i++ ){
		printf ("Elemento %d del arreglo: %d \n", i+1, arr.a[i]);
	}
}

/*
void genArray(int arr[], int seed){
	srand(seed);
	for (int i = 0 ; i < 50 ; i++ ){
		arr[i] = rand() % 100;
	}
}

Algoritmo Burbuja
Lexico
	N = 4
	s <-- arreglo [1...N] de Telemento
	i, j e (1...N+1)
	Acción Intercambiar (dato-resultado x,y e Telemento)
	{Pre-cond: x=x 0 ^ y=y 0 } / {Pos-cond: x=y 0 ^ y=x 0 }
Inicio
	i <-- N
	Mientras ( i > 1 ) hacer
		j <-- 1
		Mientras ( j < i ) hacer
			Si ( s[j] > s[j+1] ) entonces
				Intercambiar(s[j],s[j+1])
			Fsi
			j <-- j+1
		Fmientras
		i <-- i-1
	Fmientras
Fin
*/
