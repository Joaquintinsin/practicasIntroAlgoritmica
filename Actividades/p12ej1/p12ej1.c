#include <stdio.h>
#include <string.h>

#define NMax 256

typedef struct TElem{
	char titulo[50];
	char apellido[25];
	int year;
	int nroPag;
	char nomEdit[25];
}TElem;

struct TData{
	TElem a[NMax];
	int cant;
}TData;

void CargarArreglo(struct TData *arr);

int main( int argc, char **argv ) {
	struct TData arreglo;
	int i;
	char ape[25];
	
	CargarArreglo(&arreglo);
	
	if ( arreglo.cant == 0 ){
		printf ("El arreglo está vacío \n");
	}else{
		printf ("Apellido del autor a buscar: ");
		scanf("%s", ape);
		i = 0;
		
		while ( i < arreglo.cant && ( strcmp(ape, arreglo.a[i].apellido) == 1 ) ){
			i++;
		}
		
		if ( i == arreglo.cant ){
			printf ("No encontrado \n");
		}else{
			printf ("El autor tiene libros \n");
		}
	}	
	
	return 0;
}

void CargarArreglo(struct TData *arr){
	int i;
	TElem vA;
	
	printf("Cantidad a cargar del arreglo: ");
	do{
		scanf("%d", &arr->cant);
		if ( !( arr->cant >= 0 && arr->cant <= NMax ) ){
			printf ("Del 0 hasta %d \n", NMax);
		}
	} while ( !( arr->cant >= 0 && arr->cant <= NMax ) );
	for ( i = 0 ; i < arr->cant ; i++ ){
		printf ("Elemento nro %d: \n", i+1);
		printf ("Título del libro: ");
		scanf("%s", vA.titulo);
		printf ("Apellido del autor: ");
		scanf("%s", vA.apellido);
		printf ("Año del libro: ");
		scanf("%d", &vA.year);
		printf ("Número de páginas del libro: ");
		scanf("%d", &vA.nroPag);
		printf ("Nombre de Editorial del libro: ");
		scanf("%s", vA.nomEdit);
		arr->a[i] = vA;
	}
}
