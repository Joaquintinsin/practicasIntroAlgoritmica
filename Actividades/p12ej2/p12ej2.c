#include <stdio.h>

#define NMax 30

typedef struct TElem{
	int vUno;
	float vDos;
}TElem;

typedef struct TData{
	TElem a[NMax];
	int cant;
}TData;

void CargarArreglo(TData *arr);
void BusqSecRec(TElem k, TData arr, int i, int *pos);	// {Pre: i=0, arr.cant>0}

int main( int argc, char **argv ) {
	TData arreglo;
	
	CargarArreglo(&arreglo);
	if ( arreglo.cant == 0 ){
		printf ("El arreglo está vacío \n");
	}else{
		TElem elemento;
		int resPos;
		
		printf ("Elemento var uno: ");
		scanf ("%d", &elemento.vUno);
		printf ("Elemento var dos: ");
		scanf ("%f", &elemento.vDos);
		
		BusqSecRec(elemento, arreglo, 0, &resPos);
		
		printf ("Resultado de la posición: %d \n", resPos);
	}
	
	
	return 0;
}

void CargarArreglo(TData *arr){
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
		printf ("Var Uno del TElem: ");
		scanf("%d", &vA.vUno);
		printf ("Var Dos del TElem: ");
		scanf("%f", &vA.vDos);
		arr->a[i] = vA;
	}
}

void BusqSecRec(TElem k, TData arr, int i, int *pos){	// {Pre: i=0, arr.cant>0}
	if ( i == arr.cant ){
		// nada
	}else{
		if ( arr.a[i].vUno == k.vUno && arr.a[i].vDos == k.vDos ){
			*pos = i+1;
		}else{
			*pos = -1;
			BusqSecRec(k, arr, i+1, pos);
		}
	}
}
