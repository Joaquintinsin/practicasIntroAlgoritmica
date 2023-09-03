// No ordena bien

#include <stdio.h>

#define NMax 4

typedef struct TData{
	int a[NMax];
	int cant;
}TData;

void MostrarArreglo(struct TData arr);
void CargarArreglo(struct TData *arr);
void InsertionSort(TData *s);

int main( int argc, char **argv ) {
	TData sec;
	int aux;
	int i, j;
	
	printf ("1. Cargar arreglo \n");
	CargarArreglo(&sec);
	printf ("2. Mostrar \n");
	MostrarArreglo(sec);
	
	printf ("3. Insertion \n");
	i = 2;
	while ( i <= sec.cant-1 ){
		aux = sec.a[i];
		j = i - 1;
		while ( j > 0 && sec.a[j] > aux ){
			sec.a[j+1] = sec.a[j];
			j--;
		}
		sec.a[j+1] = aux;
		i++;
	}
	
	printf ("4. Mostrar \n");
	MostrarArreglo(sec);
	
	return 0;
}

void MostrarArreglo(struct TData arr){
	for ( int i = 0 ; i < arr.cant ; i++ ){
		printf ("Elemento %d del arreglo: %d \n", i+1, arr.a[i]);
	}
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

void InsertionSort(TData *s){
	int aux;
	int i, j;
	
	i = 1;
	while ( i < s->cant-1 ){
		aux = s->a[i];
		j = i - 1;
		while ( j >= 0 && s->a[j] > aux ){
			s->a[j+1] = s->a[j];
			j--;
		}
		s->a[j+1] = aux;
		i++;
	}
}

/*
Algoritmo Inserción
Lexico
	N=4
	s e arreglo [1...N] de Telemento
	aux e Telemento
	i, j e (1...N+1)
Inicio
	i <-- 2
	Mientras ( i <= N ) hacer
		aux <-- s[i]
		j <-- i-1
		Mientras ( j > 0 y s[j] > aux ) hacer
			s[j+1] <-- s[j]
			j <-- j-1
		Fmientras
		s[j+1] <-- aux
		i <-- i+1
	Fmientras
Fin 
*/
