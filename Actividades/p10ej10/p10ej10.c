#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nombre[50];
	char apellido[50];
	int dni;
	int edad;
	float totalVentas;
	float sueldoBasico;
	int present;
} TEmpleado;

void CargarArchivo(char nom[50], FILE* fA);
void MostrarArchivo(char nom[50], FILE* fA);
void BorrarEmpleado(char nomArc[25], FILE* fA);

int main( int argc, char **argv ) {
	FILE *f = NULL;
	char nombreArchivo[50];
	
	printf("Nombre del archivo: ");
	scanf("%s", nombreArchivo);
	
	CargarArchivo(nombreArchivo, f);
	MostrarArchivo(nombreArchivo, f);
	
	BorrarEmpleado(nombreArchivo, f);
	
	return 0;
}

void CargarArchivo(char nom[50], FILE* fA){
	char pararCarga;
	TEmpleado vA;
	
	fA = fopen(nom, "a+b");
	printf("Parar carga? S/N:");
	scanf("%s", &pararCarga);
	if ( pararCarga == 'n' ){
		do{
			printf("Datos del vendedor: \n");
			printf("Nombre: ");
			scanf("%s", vA.nombre);
			printf("Apellido: ");
			scanf("%s", vA.apellido);
			printf("DNI: ");
			scanf("%d", &vA.dni);
			printf("Edad: ");
			scanf("%d", &vA.edad);
			printf("Total ventas: ");
			scanf("%f", &vA.totalVentas);
			printf("Sueldo básico: ");
			scanf("%f", &vA.sueldoBasico);
			vA.present = 1;
			
			fwrite(&vA,sizeof(vA),1, fA);	// el 1 es de cantidad
			
			printf("Parar carga? S/N:");
			scanf("%s", &pararCarga);
		} while ( !( pararCarga == 's' ) );
	}
	fclose(fA);
}

void MostrarArchivo(char nom[50], FILE* fA){
	TEmpleado vA;
	int res;
	
	fA = fopen(nom, "r+b");
	res = fread(&vA, sizeof(vA), 1, fA);
	
	if ( fA == NULL ){
		printf ("Mostrar Archivo \n");
		printf ("El archivo no existe \n");
	}else{
		while ( res ){
			if ( vA.present == 1 ){
				printf("Nombre en archivo: %s \n", vA.nombre);
				printf("Apellido en archivo: %s \n", vA.apellido);
				printf("DNI en archivo: %d \n", vA.dni);
				printf("Edad en archivo: %d \n", vA.edad);
				printf("Total Ventas en archivo: %f \n", vA.totalVentas);
				printf("Sueldo Básico en archivo: %f \n", vA.sueldoBasico);
			}
			res = fread(&vA, sizeof(vA), 1, fA);
		}
	}
	fclose(fA);
}

void BorrarEmpleado(char nom[25], FILE* fA){
	TEmpleado vA;
	char apellido[25];
	int delete;
	
	fA = fopen(nom, "r+b");	// Abre para lectura/escritura binaria.
	
	if ( fA == NULL ){	// Nunca se va a dar porque con el CargarArchivo se crea...
		printf ("El archivo no existe \n");
	}else{
		printf ("¿Borrar empleado? 1/0 \n");
		scanf ("%d", &delete);
		
		if ( delete ){
			printf ("Ingrese el apellido que quiere dar de baja: ");
			scanf ("%s", apellido);
			
			rewind(fA);
			
			int res = fread(&vA,sizeof(vA), 1, fA);
			while ( res ){
				if ( strcmp(apellido, vA.apellido) == 0 ){
					// fseek(fA, 0, ftell(fA)-1);
					fseek(fA, -sizeof(vA), ftell(fA));
					if ( vA.present ){
						vA.present = 0;
						fwrite(&vA, sizeof(vA), 1, fA);
						printf ("Empleado %s borrado exitosamente \n", vA.apellido);
					}else{
						printf ("El empleado %s se encuentra borrado \n", vA.apellido);
					}
				}
				res = fread(&vA,sizeof(TEmpleado), 1, fA);
			}
		}
	}
	
	fclose(fA);
}



