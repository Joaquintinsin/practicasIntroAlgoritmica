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
		if ( aReg->cant < 0 || aReg->cant > NMax ){
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
    
    fA = fopen(nom, "ab");  // Cambiar a "ab" si usas texto plano para almacenar
    if (fA == NULL){
        printf("El archivo está vacío, se agregará al comienzo. \n");
    } else {
        printf("El archivo tiene elementos, se agregará al final. \n");
    }
    
    for(i = 0; i < arr.cant; i++) {
        fprintf(fA, "%s %d\n", arr.a[i].nombre, arr.a[i].edad); // Separando con espacio y salto de línea
    }
    fclose(fA);
    return fA;
}

void MostrarArchivo(char nom[25], FILE* fA) {
    fA = fopen(nom, "r");
    TPers p;

    if (fA == NULL) {
        printf("Error al abrir el archivo. Asegúrate de que el archivo exista.\n");
    } else {
        printf("Contenido del archivo:\n");
        while (fscanf(fA, "%s %d", p.nombre, &p.edad) == 2) {
            printf("Nombre en archivo: %s\n", p.nombre);
            printf("Edad en archivo: %d\n", p.edad);
        }
    }
    fclose(fA);
}
