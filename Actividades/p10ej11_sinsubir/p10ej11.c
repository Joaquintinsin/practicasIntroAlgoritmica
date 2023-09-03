// p10ej11	Arreglar (E 02/10 agregué MostrarArchivo. No muestra nada)

#include <stdio.h>
#include <stdlib.h>

#define NMax 1000



typedef struct TPers {
	char nombre[50];
	int edad;	//(0..120)
} TPers;

typedef struct TData{
	TPers a[NMax];
	int cant;	//(0..NMax)
} TData;

void CargarArregloDeRegistro (TData* aReg);
FILE* AlmacenarPersEnArchivo(char nom[50], TData arr);
void MostrarArchivo(char nom[25], FILE* fA);

int main(){
	TData arregloPersonas;
	FILE* f;
	char nombreArchivo[50];
	
	printf("Nombre del archivo: ");
	scanf("%s", nombreArchivo);
	CargarArregloDeRegistro(&arregloPersonas);
	f = AlmacenarPersEnArchivo(nombreArchivo, arregloPersonas);
	
	MostrarArchivo(nombreArchivo, f);
	
	return 0;
}

void CargarArregloDeRegistro (TData* aReg){
	int i;
	
	printf("¿Cuántos elementos tiene el arreglo?: ");
	do{
		scanf("%d", &aReg->cant);
		if ( aReg->cant < 0 || aReg->cant > 120 ){
			printf ("Poner de 0 a %d \n", NMax);
		}
	}while ( !(aReg->cant >= 0 && aReg->cant <= NMax) );
	
	for( i = 0 ; i < aReg->cant ; i++ ){
		printf("Alumno %d del arreglo: \n", i+1);
		printf("Inserte el nombre del alumno: ");
		scanf("%s", aReg->a[i].nombre);
		printf("Inserte la edad del alumno: ");
		scanf("%d", &aReg->a[i].edad);
	}
}

FILE* AlmacenarPersEnArchivo(char nom[50], TData arr){
	FILE* fA;
	int i;
	
	fA = fopen(nom, "a+b");
	if ( fA == NULL ){
		printf("El archivo está vacío, se agregará al comienzo. \n");
	}else{
		printf("El archivo tiene elementos, se agregará al final. \n");
		for( i = 0 ; i < arr.cant ; i++ ){
			// Escribir(fA, arr.a[i])
			fprintf(fA,"%s",arr.a[i].nombre);
			fprintf(fA,"%d",arr.a[i].edad);
		}
	}
	fclose(fA);
	return fA;
}

void MostrarArchivo(char nom[25], FILE* fA){
	int res, i;
	TData vA;
	
	fA = fopen(nom, "rb");
	
	if ( fA == NULL ){
		printf ("El archivo está vacío");
	}else{
		res = fread(&vA, sizeof(TData), 1, fA);
		i = 0;
		while ( res ){
			printf("Nombre en archivo: %s \n", vA.a[i].nombre);
			printf("Edad en archivo: %d \n", vA.a[i].edad);
			i++;
			res = fread(&vA, sizeof(TData), 1, fA);
		}
	}
	fclose(fA);
}
