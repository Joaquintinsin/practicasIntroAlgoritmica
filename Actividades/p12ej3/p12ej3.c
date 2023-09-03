#include <stdio.h>

#define NMax 1000

typedef struct TData{
	int a[NMax];
	int cant;
}TData;

void CargarArreglo(TData *arr);

int main( int argc, char **argv ) {
	int nCmp, pivot, inf, sup;
	TData arreglo;
	
	CargarArreglo(&arreglo);
	if ( arreglo.cant == 0 ){
		printf ("El arreglo está vacío \n");
	}else{
		printf ("Número a comparar: ");
		scanf ("%d", &nCmp);
		if ( nCmp < arreglo.a[0] || nCmp > arreglo.a[arreglo.cant-1] ){
			printf ("No está en el arreglo \n");
		}else{
			inf = 0;
			sup = arreglo.cant - 1;
			while ( inf < sup ){
				pivot = (inf + sup) / 2;
				if ( nCmp > arreglo.a[pivot] ){
					inf = pivot + 1;
				}else{
					sup = pivot;
				}
			}
			if ( arreglo.a[inf] == nCmp ){
				printf ("Posición del elemento para C: %d \n", inf);
				printf ("Posición del elemento para nosotros: %d \n", inf+1);
			}else{
				printf ("No está en el arreglo \n");
			}
		}
	}
	
	return 0;
}

void MostrarArreglo(TData arr){
	for ( int i = 0 ; i < arr.cant ; i++ ){
		printf ("Elemento %d del arreglo: %d \n", i+1, arr.a[i]);
	}
}

void CargarArreglo(TData *arr){
	int i;
	int elemIns;
	
	void BubbleSort(TData* arr){
		int i, j; // (1..N+1);
		
		void Intercambiar(int *x, int *y){
			int tmp;
			
			tmp = *x;
			*x = *y;
			*y = tmp;
		}
		
		for ( i = (*arr).cant-1 ; i > 0 ; i-- ){
			for ( j = 0 ; j < i ; j++ ){
				if ( (*arr).a[j] > (*arr).a[j+1] ){
					Intercambiar(&((*arr).a[j]), &((*arr).a[j+1]));
				}
			}
		}
	}
	
	printf("Cantidad a cargar del arreglo: ");
	do{
		scanf("%d", &arr->cant);
		if ( !( arr->cant >= 0 && arr->cant <= NMax ) ){
			printf ("Del 0 hasta %d \n", NMax);
		}
	} while ( !( arr->cant >= 0 && arr->cant <= NMax ) );
	for ( i = 0 ; i < arr->cant ; i++ ){
		printf ("Elemento nro %d: ", i+1);
		scanf ("%d", &elemIns);
		arr->a[i] = elemIns;
	}
	printf ("Sin ordenar \n");
	MostrarArreglo(*arr);
	// Ordenarlo
	BubbleSort(arr);
	printf ("Desps de BubbleSort \n");
	MostrarArreglo(*arr);
}
