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

typedef struct TData{
	Tregdiario a[Max];
	int cant;
}TData;

void PedirFecha(int anioEntry, long int *fecha);
void Alta(int anioEntry, char nom[25]);
void Suprimir(int anioEntry, char nom[25]);
void ModificarRegistro(int anioEntry, char nom[25]);
void MostrarArchivo(char nom[25]);
int BuscaPosRecursiva(TData array, int i, int fecha);
void MostrarDatos_Pos(int i, int fecha, TData *array);
void Verificar(char nom[25], FILE* *fA);
void DesplegarMenuDeOpciones();

int main( int argc, char **argv ) {
	Tregdiario capturarReg;
	char nombreArchivo[25];
	char extension[10];
	int opcionEntry, pedirAnio;
	long int delDiaArch, delMesArch;
	FILE* f;
	
	printf ("Inicio del programa.\n");
	printf ("A continuación se manejará un menú de opciones para el modelo de una estación metereológica. \n");
	printf ("Por favor, inserte el nombre del archivo que usará para el programa (no hace falta poner .dat): \n");
	scanf("%s", nombreArchivo);
	strcpy(extension, ".dat");
	strcat(nombreArchivo,extension);
	
	Verificar(nombreArchivo, &f);
	
	do{
		DesplegarMenuDeOpciones();
		scanf ("%d", &opcionEntry);
		// Modelo el Según en C como Si entonces así es más legible. Todas las condiciones de 
		// los sí son excluyentes uno al otro, por lo tanto resulta equivalente.
		if ( opcionEntry == 1 ){
			printf ("Opción 1: Alta de un registro diario \n");
			printf ("Ingresar el año correspondiente al registro. \n");
			printf ("En caso que el archivo ya tenga elementos cargados, debe coincidir con el año de los que ya estén cargados en el archivo \n");
			scanf ("%d", &pedirAnio);
			// Def de años
			if ( pedirAnio < 1000 || pedirAnio > 9999 ){
				do{
					printf ("Ingresar un año válido: ");
					scanf("%d", &pedirAnio);
				} while ( !( pedirAnio >= 1000 && pedirAnio <= 9999 ) );
			}
			f = fopen (nombreArchivo, "r+b");
			if ( fread(&capturarReg, sizeof(capturarReg), 1, f) == 0 ){
				Alta(pedirAnio, nombreArchivo);
			}else{
				delDiaArch = capturarReg.ddmmyyyy / 1000000;
				delMesArch = capturarReg.ddmmyyyy / 10000 - (delDiaArch*100);
				capturarReg.ddmmyyyy = capturarReg.ddmmyyyy - (delDiaArch*1000000) - (delMesArch*10000);
				// printf ("delDiaArch: %ld \n", delDiaArch);
				// printf ("delMesArch: %ld \n", delMesArch);
				// printf ("capturarReg.ddmmyyyy: %ld \n", capturarReg.ddmmyyyy);
				if ( capturarReg.ddmmyyyy == pedirAnio ){
					Alta(pedirAnio, nombreArchivo);
				}else{
					printf ("Los años no coinciden. El año cargado es %ld. \n", capturarReg.ddmmyyyy);
				}
			}
			fclose(f);
		}
		if ( opcionEntry == 2 ){
			printf ("Opción 2: Suprimir un registro diario \n");
			printf ("Ingresar el año \n");
			scanf ("%d", &pedirAnio);
			// Def de años
			if ( pedirAnio < 1000 || pedirAnio > 9999 ){
				do{
					printf ("Ingresar un año válido: ");
					scanf("%d", &pedirAnio);
				} while ( !( pedirAnio >= 1000 && pedirAnio <= 9999 ) );
			}
			f = fopen (nombreArchivo, "r+b");
			if ( fread(&capturarReg, sizeof(capturarReg), 1, f) == 0 ){
				Suprimir(pedirAnio, nombreArchivo);
			}else{
				delDiaArch = capturarReg.ddmmyyyy / 1000000;
				delMesArch = capturarReg.ddmmyyyy / 10000 - (delDiaArch*100);
				capturarReg.ddmmyyyy = capturarReg.ddmmyyyy - (delDiaArch*1000000) - (delMesArch*10000);
				// printf ("delDiaArch: %ld \n", delDiaArch);
				// printf ("delMesArch: %ld \n", delMesArch);
				// printf ("capturarReg.ddmmyyyy: %ld \n", capturarReg.ddmmyyyy);
				if ( capturarReg.ddmmyyyy == pedirAnio ){
					Suprimir(pedirAnio, nombreArchivo);
				}else{
					printf ("Los años no coinciden. El año cargado es %ld. \n", capturarReg.ddmmyyyy);
				}
			}
			fclose(f);
		}
		if ( opcionEntry == 3 ){
			printf ("Opción 3: Modificar un registro, se busca por la fecha \n");
			printf ("Ingresar el año \n");
			scanf ("%d", &pedirAnio);
			// Def de años
			if ( pedirAnio < 1000 || pedirAnio > 9999 ){
				do{
					printf ("Ingresar un año válido: ");
					scanf("%d", &pedirAnio);
				} while ( !( pedirAnio >= 1000 && pedirAnio <= 9999 ) );
			}
			delDiaArch = capturarReg.ddmmyyyy / 1000000;
			delMesArch = capturarReg.ddmmyyyy / 10000 - (delDiaArch*100);
			capturarReg.ddmmyyyy = capturarReg.ddmmyyyy - (delDiaArch*1000000) - (delMesArch*10000);
			// printf ("delDiaArch: %ld \n", delDiaArch);
			// printf ("delMesArch: %ld \n", delMesArch);
			// printf ("capturarReg.ddmmyyyy: %ld \n", capturarReg.ddmmyyyy);
			if ( capturarReg.ddmmyyyy == pedirAnio ){
				ModificarRegistro(pedirAnio, nombreArchivo);
			}else{
				printf ("Los años no coinciden. El año cargado es %ld. \n", capturarReg.ddmmyyyy);
			}
		}
		if ( opcionEntry == 4 ){
			printf ("Opción 4: Mostrar todos los registros activos \n");
			MostrarArchivo(nombreArchivo);
		}
		if ( opcionEntry == 5 ){
			printf ("Opción 5: Buscar registro de un día dado y mostrar todos los parámetros \n");
			printf ("Ingresar la fecha que quiere buscar \n");
			
		}
		if ( opcionEntry == 6 ){
			printf("Opción 6: Listar el día o días de máxima temperatura en lo que va del año \n");
			
		}
		if ( opcionEntry == 7 ){
			printf ("Opción 7: Listar el día o días de máxima precipitación en lo que va del año \n");
			
		}
		if ( opcionEntry == 8 ){
			printf ("Opción 8: Listar las fechas de mayor a menor velocidad de viento \n");
			
		}
		if ( opcionEntry == 9 ){
			printf ("Opción 9: Realizar una copia de seguridad del archivo del año en curso \n");
			
		}
		if ( opcionEntry == 10 ){
			printf ("Opción 10: Salir \n");
		}
		if (opcionEntry != 1 && opcionEntry != 2 && opcionEntry != 3 && opcionEntry != 4 
			&& opcionEntry != 5 && opcionEntry != 6 && opcionEntry != 7 && opcionEntry != 8 
			&& opcionEntry != 9 && opcionEntry != 10 ){
			// Otros: Osea negar todas las demás condiciones.
			printf ("Debe ser un número del 1 al 10. \n");
		}
	}while ( !( opcionEntry == 10 ) );
	
	printf ("Salida exitosa. \n");
	return 0;
}

int ArchVacio(char nom[20]){
    FILE* f;
    Tregdiario r;
    
    f = fopen(nom,"a+b");
    
    if ( fread(&r, sizeof(Tregdiario), 1, f) == 0 ){
		fclose(f);
		return 1;
    }else{
        do{
            if( !r.borrado ){
                fclose(f);
                return 0;
            }
        } while ( fread(&r, sizeof(Tregdiario), 1, f) > 0 );
    }
    fclose(f);
    return 1;
}

void PedirFecha(int anioEntry, long int *fecha){
	int mA, dA;
	
	printf ("Ingresar el mes correspondiente al registro: ");
	
	if ( ( (anioEntry % 4)==0  && (anioEntry % 100) != 0 ) || ( (anioEntry % 100)==0 && (anioEntry % 400)==0 ) ) {	// Es bisiesto
		scanf("%d", &mA);
		if ( mA < 1 || mA > 12 ){
			do{
				printf("Ingresar un mes válido: ");
				scanf("%d", &mA);
			} while ( mA < 1 || mA > 12 );
		}
		printf("Ingresar el día correspondiente al registro: ");
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
	}else{	// No es bisiesto
		scanf("%d", &mA);
		if ( mA < 1 || mA > 12 ){
			do{
				printf("Ingresar un mes válido: ");
				scanf("%d", &mA);
			} while ( mA < 1 || mA > 12 );
		}
		printf("Ingresar el día correspondiente al registro: ");
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
		}else{
			if ( (mA == 4 || mA == 5 || mA == 6 || mA == 9 || mA == 11) && dA == 31 ){
				do{
					printf ("Ingresar un día válido. Los meses 4, 5, 6, 9 y 11 tienen 30 días \n");
					scanf("%d", &dA);
				} while ( dA < 1 || dA > 30 );
			}
		}
	}
	*fecha = dA*1000000 + mA*10000 + anioEntry;
}

void Alta(int anioEntry, char nom[25]){
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
	
	FILE* fA;
	Tregdiario rA;
	int rta;
	
	fA = fopen(nom, "a+b");
	do{
		PedirFecha(anioEntry, &(rA.ddmmyyyy));
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
		fwrite(&rA, sizeof(Tregdiario), 1, fA);
		printf ("¿Desea seguir cargando? 1/0: ");
		scanf ("%d", &rta);
	} while ( rta );
	fclose(fA);
}

void Suprimir(int anioEntry, char nom[25]){
	long int fecha;
	Tregdiario rA;
	FILE* f;
	
	f = fopen(nom,"r+b");
	
	if ( ArchVacio(nom) ){
		printf ("No se puede suprimir porque el archivo está vacío. \n");
		printf ("Vuelve al menú principal.\n");
	}else{
		printf ("De que fecha es el registro que quiere suprimir?: \n");
		PedirFecha(anioEntry, &fecha);
		if ( !ArchVacio(nom) ){
			while( fread(&rA, sizeof(Tregdiario), 1, f) > 0 ) {
				if ( rA.ddmmyyyy == fecha && !rA.borrado ) {
					rA.borrado = 1;
					fseek(f, (-1)*sizeof(Tregdiario), SEEK_CUR);
					fwrite(&rA, sizeof(Tregdiario), 1, f);
					printf("Suprimido con exito \n");
					fclose(f);
					return;
				}
			}
			printf("No se encontró la fecha %ld para suprimir \n", fecha);
		}else{
			printf("El archivo está vacío \n");
		}
	}
	fclose(f);
}

void ModificarRegistro(int anioEntry, char nom[25]){
	long int fecha;
	FILE* f;
	Tregdiario regMod, regArch;
	
	f = fopen(nom, "r+b");
	PedirFecha(anioEntry, &fecha);
	while ( fread(&regArch, sizeof(Tregdiario), 1, f) > 0 && regArch.ddmmyyyy != fecha ){
		printf ("lectura registro: %ld \n", regArch.ddmmyyyy);
		// ya está avanzando el cabezal por el fread como condición del mientras
	}
	if ( regArch.ddmmyyyy == fecha ){
		if ( !regArch.borrado ){
			fseek(f, ftell(f), -sizeof(Tregdiario));	// IrPos(f, PosicionActual(f)-1)
			printf ("La temp máxima cargada es %d \n", regArch.tmax);
			printf ("Ingresar la nueva temperatura máxima: ");
			scanf("%d", &regMod.tmax);
			if ( regMod.tmax < -100 || regMod.tmax > 100 ){
				do{
					printf ("Ingresar una temperatura válida. Entre -100 y 100: ");
					scanf ("%d", &regMod.tmax);
				} while ( regMod.tmax < -100 || regMod.tmax > 100 );
			}
			printf ("La temp mínima cargada es %d \n", regArch.tmin);
			printf ("Ingresar la nueva temperatura mínima: ");
			scanf("%d", &regMod.tmin);
			if ( regMod.tmin < -100 || regMod.tmin > 100 ){
				do{
					printf ("Ingresar una temperatura válida. Entre -100 y 100: ");
					scanf ("%d", &regMod.tmax);
				} while ( regMod.tmin < -100 || regMod.tmin > 100 );
			}
			printf ("La humedad cargada es %d \n", regArch.HUM);
			printf ("Ingresar la nueva humedad: ");
			scanf("%d", &regMod.HUM);
			if ( regMod.HUM < 0 || regMod.HUM > 100 ){
				do{
					printf ("Ingresar un porcentaje de humedad válido. Entre 0 y 100: ");
					scanf ("%d", &regMod.HUM);
				} while ( regMod.HUM < 0 || regMod.HUM > 100 );
			}
			printf ("La presión atmosférica cargada es %d \n", regArch.PNM);
			printf ("Ingresar la nueva presión atmosférica: ");
			scanf("%d", &regMod.PNM);
			if ( regMod.PNM < 900 || regMod.PNM > 3500 ){
				do{
					printf ("Ingresar una presión atmosférica válida. Entre 900 y 3500: ");
					scanf ("%d", &regMod.PNM);
				} while ( regMod.PNM < 900 || regMod.PNM > 3500 );
			}
			printf ("La dirección del viento cargada es %d \n", regArch.DV);
			printf ("Ingresar la nueva dirección del viento: ");
			scanf("%d", &regMod.DV);
			if ( regMod.DV < 0 || regMod.DV > 360 ){
				do{
					printf ("Ingresar una dirección de viento válida. Entre 0 y 360: ");
					scanf ("%d", &regMod.DV);
				} while ( regMod.DV < 0 || regMod.DV > 360 );
			}
			printf ("La velocidad del viento cargada es %d \n", regArch.FF);
			printf ("Ingresar la nueva velocidad del viento: ");
			scanf("%d", &regMod.FF);
			if ( regMod.FF <= 0 ){
				do{
					printf ("Ingresar una velocidad de viento válida. Debe ser positivo: ");
					scanf ("%d", &regMod.FF);
				} while ( regMod.FF <= 0 );
			}
			printf ("La precipitación de la fecha cargada es %d \n", regArch.PP);
			printf ("Ingresar la nueva temperatura máxima: ");
			scanf("%d", &regMod.PP);
			if ( regMod.PP < 0 || regMod.PP > 1000 ){
				do{
					printf ("Ingresar una precipitación pluvial válida. Entre 0 y 1000: ");
					scanf ("%d", &regMod.PP);
				} while ( regMod.PP < 0 || regMod.PP > 1000 );
			}
			regMod.ddmmyyyy = fecha;
			regMod.borrado = 0;
			fwrite(&regMod, sizeof(Tregdiario), 1, f);
			printf ("Se modificó con éxito \n");
		}else{
			printf ("El registro de la fecha %ld está borrado \n", fecha);
		}
	}else{
		printf ("La fecha no existe \n");
	}
	fclose(f);
}

void MostrarArchivo(char nom[25]){
	FILE* f;
	Tregdiario reg;
	int i = 0;
	
	f = fopen(nom, "r+b");
	
	if ( fread(&reg, sizeof(Tregdiario), 1, f) == 0 ){
		printf ("Archivo vacío \n");
	}else{
		do {
			if ( !reg.borrado ){
				i++;
				printf ("reg.ddmmyyy = %ld \n", reg.ddmmyyyy);
				printf ("reg.tmax = %d \n", reg.tmax);
				printf ("reg.tmin = %d \n", reg.tmin);
				printf ("reg.HUM = %d \n", reg.HUM);
				printf ("reg.PNM = %d \n", reg.PNM);
				printf ("reg.DV = %d \n", reg.DV);
				printf ("reg.FF = %d \n", reg.FF);
				printf ("reg.PP = %d \n", reg.PP);
				// printf ("reg.borrado = %d \n", reg.borrado);
			}
		} while ( fread(&reg, sizeof(Tregdiario), 1, f) > 0 );
		if ( i == 0 ){
			printf ("Todos los registros están borrados \n");
		}
	}
	fclose(f);
}

int BuscaPosRecursiva(TData array, int i, int fecha){
    if (i == array.cant + 1){
        return -1;
    }else{
        if (array.a[i].ddmmyyyy == fecha && !array.a[i].borrado){
            return i;
        }else{
            return BuscaPosRecursiva(array, i+1,fecha);
        }
    }
}

void MostrarDatos_Pos(int i, int fecha, TData *array){ // el arreglo es de tipo dato resultado
    if (i == -1){
        printf("No se encontró la fecha \n");
    }else{
        if ( array->a[i].ddmmyyyy == fecha && !array->a[i].borrado){

            printf("Registro encontrado: %ld \n", array->a[i].ddmmyyyy);
           
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

void DesplegarMenuDeOpciones(){
	printf ("\n");
	printf ("· Menú principal");
	printf ("\n");
	printf ("Seleccione una opción para continuar: \n");
	printf ("\t 1. Alta de un registro diario \n");
	printf ("\t 2. Suprimir un registro diario \n");
	printf ("\t 3. Modificar un registro, se busca por la fecha \n");
	printf ("\t 4. Mostrar todos los registros activos \n");
	printf ("\t 5. Buscar registro de un día dado y mostrar todos los parámetros \n");
	printf ("\t 6. Listar el día o días de máxima temperatura en lo que va del año \n");
	printf ("\t 7. Listar el día o días de máxima precipitación en lo que va del año \n");
	printf ("\t 8. Listar las fechas de mayor a menor velocidad de viento \n");
	printf ("\t 9. Realizar una copia de seguridad del archivo del año en curso \n");
	printf ("\t 10. Salir \n");
}
