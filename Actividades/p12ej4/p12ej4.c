#include <stdio.h>

#define NMax 100

typedef struct TData{
	int a[NMax];
	int cant;
}TData;

void MostrarArreglo(TData arr);
void CargarArreglo(TData *arr);
// {Pre: q cargado, pivot = 0, inf = 0, sup = q.cant}
void BuscarElemento(int k, TData q, int pivot, int inf, int sup, int *pos);

int main( int argc, char **argv ) {
	TData arreglo;
	
	printf ("Cargar arreglo. Se ordenará al final. \n");
	CargarArreglo(&arreglo);
	if ( !arreglo.cant ){
		printf ("El arreglo está vacío \n");
	}else{
		int kElem, pivotMain = 0, infMain = 0, supMain = arreglo.cant, resPos;
		
		printf ("Elemento a buscar: ");
		scanf ("%d", &kElem);
		BuscarElemento(kElem, arreglo, pivotMain, infMain, supMain, &resPos);
		if ( resPos == -1 ){
			printf ("Elemento no encontrado \n");
		}else{
			printf ("Resultado pos en C: %d \n", resPos);
			printf ("Resultado pos para nosotros: %d \n", resPos+1);
		}
	}
	return 0;
}

void MostrarArreglo(TData arr){
	for ( int i = 0 ; i < arr.cant ; i++ ) printf ("Elemento %d del arreglo: %d \n", i+1, arr.a[i]);
}

void CargarArreglo(TData *arr){
	int i, elemento;
	
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
		scanf ("%d", &elemento);
		arr->a[i] = elemento;
	}
	
	// Ordenarlo
	BubbleSort(arr);
}

// {Pre: q cargado, pivot = 0, inf = 0, sup = q.cant}
void BuscarElemento(int k, TData q, int pivot, int inf, int sup, int *pos){
	if ( q.cant == 0 ){
		// nada
	}else{
		pivot = (inf + sup) / 2;
		if ( q.a[pivot] == k ){
			*pos = pivot;
		}else{
			if ( q.a[pivot] > k ){
				q.cant = q.cant - 1;
				*pos = -1;
				BuscarElemento(k, q, pivot, inf, pivot, pos);
			}else{
				if ( q.a[pivot] < k ){
					q.cant = q.cant - 1;
					*pos = -1;
					BuscarElemento(k, q, pivot, inf+1, sup, pos);
				}
			}
		}
	}
}
