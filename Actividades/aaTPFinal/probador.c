#include <stdio.h>

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

void Alta(char nomArch[25], FILE* *fA){
	Tregdiario rA;
	int rta;
	
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
			if ( mA < 1 || aA > 12 ){
				do{
					printf("Ingresar un mes válido: ");
					scanf("%d", &mA);
				} while ( mA < 1 || mA > 12 );
			}
			printf("Día: ");
			scanf("%d", &dA);
			if ( aA < 1 || aA > 31 ){
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
			if ( mA < 1 || aA > 12 ){
				do{
					printf("Ingresar un mes válido: ");
					scanf("%d", &mA);
				} while ( mA < 1 || mA > 12 );
			}
			printf("Día: ");
			scanf("%d", &dA);
			if ( aA < 1 || aA > 31 ){
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
		*fecha = dA * 1000000 + mA * 10000 + aA;
	}
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
	
	*fA = fopen(nomArch, "a+b");
	printf ("Desea dar de alta un registro? 1/0 :");
	scanf ("%d", &rta);
	if ( rta ){
		do{
			printf ("Ingresar la fecha correspondiente al registro: \n");
			PedirFecha(&rA.ddmmyyyy);
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
			printf ("¿Desea seguir cargando? 1/0: ");
			scanf ("%d", &rta);
		} while ( rta );
	}else{
		printf ("Vuelve al menú principal \n");
	}
	fclose(*fA);
}

int main( int argc, char **argv ) {
	Tregdiario test;
	printf ("Nomb Arch: ");
	char narc[25];
	FILE* f;
	
	scanf("%s", narc);
	Alta(narc, &f);
	f = fopen (narc, "r+b");
	fread(&test, sizeof(test), 1, f);
	if ( feof(f) ){
		printf ("Archivo vacío \n");
	}else{
		while ( !feof(f) ){
			printf ("test.ddmmyyy = %ld \n", test.ddmmyyyy);
			printf ("test.tmax = %d \n", test.tmax);
			printf ("test.tmin = %d \n", test.tmin);
			printf ("test.HUM = %d \n", test.HUM);
			printf ("test.PNM = %d \n", test.PNM);
			printf ("test.DV = %d \n", test.DV);
			printf ("test.FF = %d \n", test.FF);
			printf ("test.PP = %d \n", test.PP);
			printf ("test.borrado = %d \n", test.borrado);
			fread(&test, sizeof(test), 1, f);
		}
	}
	fclose(f);
	
	return 0;
}
