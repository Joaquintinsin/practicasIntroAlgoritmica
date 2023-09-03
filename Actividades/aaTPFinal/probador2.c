#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Max 256

typedef struct {
	long int ddmmyyyy;
	int tmax;
	int tmin;
	int HUM;
	int PNM;
	int DV;
	int FF;
	int PP;
	int borrado;
} Tregdiario;

void PedirFecha(long int *fecha){
	int dA, mA, aA;
	
	printf("Año: ");
	scanf("%d", &aA);
	if ( aA < 1000 || aA > 9999 ){
		do{
			printf("Ingresar un año válido: ");
			scanf("%d", &aA);
		} while ( aA < 1000 || aA > 9999 );
	}
	if ( ( (aA % 4)==0  && (aA % 100) != 0 ) || ( (aA % 100)==0 && (aA % 400)==0 ) ) {
		printf ("Es un año bisiesto. \n");
		printf("Mes: ");
		scanf("%d", &mA);
		if ( mA < 1 || mA > 12 ){
			do{
				printf("Ingresar un mes válido: ");
				scanf("%d", &mA);
			} while ( mA < 1 || mA > 12 );
		}
		printf("Día: ");
		scanf("%d", &dA);
		if ( dA < 1 || dA > 31 ){
			do{
				printf("Ingresar un día válido: ");
				scanf("%d", &dA);
			} while ( dA < 1 || dA > 31 );
		}
		if ( mA == 2 && dA > 29 ){
			do{
				printf("Ingresar un día de febrero válido: ");
				scanf("%d", &dA);
			} while ( dA < 1 || dA > 29 );
		}
	}else{
		printf ("No es un año bisiesto \n");
		printf("Mes: ");
		scanf("%d", &mA);
		if ( mA < 1 || mA > 12 ){
			do{
				printf("Ingresar un mes válido: ");
				scanf("%d", &mA);
			} while ( mA < 1 || mA > 12 );
		}
		printf("Día: ");
		scanf("%d", &dA);
		if ( dA < 1 || dA > 31 ){
			do{
				printf("Ingresar un día válido: ");
				scanf("%d", &dA);
			} while ( dA < 1 || dA > 31 );
		}
		if ( mA == 2 && dA > 28 ){
			do{
				printf("Ingresar un día de febrero válido. \nRecordatorio: El año ingresado no es bisiesto: ");
				scanf("%d", &dA);
			} while ( dA < 1 || dA > 28 );
		}
	}
	*fecha = dA*1000000 + mA*10000 + aA;
}

void Alta(FILE* *fA){
	// posiblemente tenga q pedir la fecha en un modulo especial para esta accion
	void PedirTemp(int *tM){
		scanf ("%d", &(*tM));
		if ( *tM < -100 || *tM > 100 ){
			do{
				printf ("Ingresar una temperatura válida. Entre -100 y 100: ");
				scanf ("%d", &(*tM));
			} while ( *tM < -100 || *tM > 100 );
		}
	}
	void PedirHumedad(int *hA){
		scanf ("%d", &(*hA));
		if ( *hA < 0 || *hA > 100 ){
			do{
				printf ("Ingresar un porcentaje de humedad válido. Entre 0 y 100: ");
				scanf ("%d", &(*hA));
			} while ( *hA < 0 || *hA > 100 );
		}
	}
	void PedirDirViento(int *dvA){
		scanf ("%d", &(*dvA));
		if ( *dvA < 0 || *dvA > 360 ){
			do{
				printf ("Ingresar una dirección de viento válida. Entre 0 y 360: ");
				scanf ("%d", &(*dvA));
			} while ( *dvA < 0 || *dvA > 360 );
		}
	}
	void PedirPresAtm(int *prA){
		scanf ("%d", &(*prA));
		if ( *prA < 900 || *prA > 3500 ){
			do{
				printf ("Ingresar una presión atmosférica válida. Entre 900 y 3500: ");
				scanf ("%d", &(*prA));
			} while ( *prA < 900 || *prA > 3500 );
		}
	}
	void PedirVelocViento(int *wA){
		scanf ("%d", &(*wA));
		if ( *wA <= 0 ){
			do{
				printf ("Ingresar una velocidad de viento válida. Debe ser positivo: ");
				scanf ("%d", &(*wA));
			} while ( *wA <= 0 );
		}
	}
	void PedirPrecPluv(int *ppA){
		scanf ("%d", &(*ppA));
		if ( *ppA < 0 || *ppA > 1000 ){
			do{
				printf ("Ingresar una precipitación pluvial válida. Entre 0 y 1000: ");
				scanf ("%d", &(*ppA));
			} while ( *ppA < 0 || *ppA > 1000 );
		}
	}
	long int entryAnio;
	long int delDiaEntry;
	long int delMesEntry;
	long int delDiaArch;
	long int delMesArch;
	Tregdiario rA, captError;
	int rta;
	
	printf ("Desea dar de alta un registro? T/F :");
	scanf ("%d", &rta);
	if ( rta ){
		do{
			printf ("Ingresar la fecha correspondiente al registro: \n");
			PedirFecha(&rA.ddmmyyyy);
			if ( feof(*fA) ){
				printf ("Ingresar la temperatura máxima de la fecha: ");
				PedirTemp(&rA.tmax);
				printf ("Ingresar la temperatura mínima de la fecha: ");
				PedirTemp(&rA.tmin);
				printf ("Ingresar el porcentaje de humedad promedio de la fecha: ");
				PedirHumedad(&rA.HUM);
				printf ("Ingresar el promedio de presión atmosférica de la fecha: ");
				PedirPresAtm(&rA.PNM);
				printf ("Ingresar la dirección del viento de la fecha: ");
				PedirDirViento(&rA.DV);
				printf ("Ingresar la velocidad máxima del viento de la fecha: ");
				PedirVelocViento(&rA.FF);
				printf ("Ingresar la precipitación pluvial acumulado el día de la fecha: ");
				PedirPrecPluv(&rA.PP);
				rA.borrado = 0;
				fwrite(&rA, sizeof(rA), 1, *fA);
			}else{
				fread(&captError, sizeof(captError), 1, *fA);
				if ( feof(*fA) ){
					printf("cargar sin drama \n");
				}else{
					delDiaEntry = rA.ddmmyyyy/1000000;
					printf ("delDiaEntry: %ld \n", delDiaEntry);
					delDiaArch = captError.ddmmyyyy/1000000;
					printf ("delDiaArch: %ld \n", delDiaArch);
					delMesEntry = rA.ddmmyyyy/10000 - (delDiaEntry*100);
					printf ("delMesEntry: %ld \n", delMesEntry);
					delMesArch = captError.ddmmyyyy/10000 - (delDiaArch*100);
					printf ("delMesArch: %ld \n", delMesArch);
					entryAnio = rA.ddmmyyyy - (delDiaEntry*1000000) + (delMesEntry*10000);
					printf ("entryAnio: %ld \n", entryAnio);
					captError.ddmmyyyy = captError.ddmmyyyy - (delDiaArch*1000000) + (delMesArch*10000);
					printf ("captError.ddmmyyyy: %ld \n", captError.ddmmyyyy);
					if ( captError.ddmmyyyy == entryAnio ){
						printf ("Son iguales, se agregan todos los demás campos etc etc \n");
					}else{
						printf("El año que ingresó no coincide con el año de los registros que ya están almacenados en el archivo \n");
					}
				}
			}
			printf ("¿Desea seguir cargando? 1/0: ");
			scanf ("%d", &rta);
		} while ( rta );
	}else{
		printf ("Vuelve al menú principal \n");
	}
}

void MostrarArchivo(FILE* fA){
	Tregdiario test;
	
	rewind(fA);
	fread(&test, sizeof(test), 1, fA);
	if ( feof(fA) ){
		printf ("Archivo vacío \n");
	}else{
		while ( !feof(fA) ){
			if ( !test.borrado ){
				printf ("test.ddmmyyy = %ld \n", test.ddmmyyyy);
				printf ("test.tmax = %d \n", test.tmax);
				printf ("test.tmin = %d \n", test.tmin);
				printf ("test.HUM = %d \n", test.HUM);
				printf ("test.PNM = %d \n", test.PNM);
				printf ("test.DV = %d \n", test.DV);
				printf ("test.FF = %d \n", test.FF);
				printf ("test.PP = %d \n", test.PP);
				printf ("test.borrado = %d \n", test.borrado);
			}
			fread(&test, sizeof(test), 1, fA);
		}
	}
}

void Verificar(char nom[25], FILE* *fA){
	Tregdiario aux;
	
	*fA = fopen(nom, "a+b");
	rewind(*fA);
	fread(&aux, sizeof(aux), 1, *fA);
	if ( feof(*fA) ){
		printf ("El archivo %s fue creado. \n", nom);
	}else{
		printf ("Archivo: %s - abierto exitosamente. \n", nom);
	}
	fclose(*fA);
}

int main( int argc, char **argv ) {
	char narc[25];
	char extension[10];
	FILE* f;
	
	printf ("Inicio del programa.\n");
	printf ("A continuación se manejará un menú de opciones para el modelo de una estación metereológica. \n");
	printf ("Por favor, inserte el nombre del archivo que usará para el programa (no hace falta poner .dat): \n");
	scanf("%s", narc);
	strcpy(extension, ".dat");
	strcat(narc,extension);
	
	Verificar(narc, &f);
	
	f = fopen(narc, "a+b");
	Alta(&f);
	MostrarArchivo(f);
	
	fclose(f);
	
	return 0;
}
