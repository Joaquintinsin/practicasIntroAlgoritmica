#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
} TData;

typedef struct Tnodo{
	Tregdiario info;
	struct Tnodo* next;
} Tnodo;

int ArchVacio(char nom[20]);
void PedirAnio(int *anio);
void PedirFecha(int aA, long int *fecha);
TData ArchArray(char nom[25]);
void Verificar(char nom[25], FILE* *fA);
void Suprimir(int anioEntry, char nom[20]);
void Alta(int anioEntry, char nom[25]);
void ModificarRegistro(int anioEntry, char nom[20]);
void MostrarArchivo(char nom[25]);
int BuscaPosRecursiva(TData registro, int i, int fecha1);
void MostrarDatos_Pos(int i, TData registro);
void VaciarListaConFict(Tnodo *q);
void MostrarLSETempMax(Tnodo *q);
void ListarTempMax(char nom[25], Tnodo* *s);
void OrdenarInsertionReves(TData *arr);
void ListarPrecMax(char nom[25]);
void ListarMayMenVelViento(char nom[25]);
void OrdenarBubbleReves(TData *a);
void CopiaSeguridad(char nom[25]);

int main( int argc, char **argv ) {
	char nombreArchivo[25], extension[10];
	FILE* f;
	TData arreglo;
	Tnodo *listaTempMax;
	int anio, resRecurs;
	long int fechin;
	
	printf ("nombre archivo: ");
	scanf ("%[^\n]", nombreArchivo);
    strcpy(extension, ".dat");
    strcat(nombreArchivo,extension);
    Verificar(nombreArchivo, &f);
    MostrarArchivo(nombreArchivo);
    /*
    printf ("Alta \n");
    printf ("Año: ");
    scanf ("%d", &anio);
    Alta(anio, nombreArchivo);
    printf ("Suprimir \n");
    printf ("Año: ");
    scanf ("%d", &anio);
    Suprimir(anio, nombreArchivo);
    printf ("Modificar \n");
    printf ("Año: ");
    scanf ("%d", &anio);
    ModificarRegistro(anio, nombreArchivo);
    */
    printf ("¿Arch Vacio? %d \n", ArchVacio(nombreArchivo));
	arreglo = ArchArray(nombreArchivo);
	/*
	for ( int i = 0 ; i < arreglo.cant ; i++ ){
		printf ("arreglo.a[%d].ddmmyyyy = %ld \n", i, arreglo.a[i].ddmmyyyy);
		printf ("arreglo.a[%d].tmax = %d \n", i, arreglo.a[i].tmax);
		printf ("arreglo.a[%d].tmin = %d \n", i, arreglo.a[i].tmin);
		printf ("arreglo.a[%d].HUM = %d \n", i, arreglo.a[i].HUM);
		printf ("arreglo.a[%d].PNM = %d \n", i, arreglo.a[i].PNM);
		printf ("arreglo.a[%d].borrado = %d \n", i, arreglo.a[i].borrado);
	}
	PedirAnio(&anio);
	PedirFecha(anio, &fechin);
	resRecurs = BuscaPosRecursiva(arreglo, 0, fechin);
	MostrarDatos_Pos(resRecurs, arreglo);
	printf ("recRecurs: %d \n", resRecurs);
	*/
	printf ("¿arreglo.cant? %d \n", arreglo.cant);
	for ( int i = 0 ; i < arreglo.cant ; i++ ){
		printf ("arreglo.a[%d].ddmmyyyy = %ld \n", i, arreglo.a[i].ddmmyyyy);
		printf ("arreglo.a[%d].tmax = %d \n", i, arreglo.a[i].tmax);
		printf ("arreglo.a[%d].tmin = %d \n", i, arreglo.a[i].tmin);
		printf ("arreglo.a[%d].HUM = %d \n", i, arreglo.a[i].HUM);
		printf ("arreglo.a[%d].PNM = %d \n", i, arreglo.a[i].PNM);
		printf ("arreglo.a[%d].DV = %d \n", i, arreglo.a[i].DV);
		printf ("arreglo.a[%d].FF = %d \n", i, arreglo.a[i].FF);
		printf ("arreglo.a[%d].PP = %d \n", i, arreglo.a[i].PP);
		printf ("arreglo.a[%d].borrado = %d \n", i, arreglo.a[i].borrado);
	}
	//printf ("OrdenarDiezInsertionReves \n");
	//OrdenarDiezInsertionReves(&arreglo);
	printf ("ListarPrecMax \n");
	ListarPrecMax(nombreArchivo);
	printf ("FListarPrecMax \n");
	/*
	for ( int i = 0 ; i < 10 && i < arreglo.cant ; i++ ){
		printf ("arregloPrecip.a[%d].ddmmyyyy = %ld \n", i, arregloPrecip.a[i].ddmmyyyy);
		printf ("arregloPrecip.a[%d].tmax = %d \n", i, arregloPrecip.a[i].tmax);
		printf ("arregloPrecip.a[%d].tmin = %d \n", i, arregloPrecip.a[i].tmin);
		printf ("arregloPrecip.a[%d].HUM = %d \n", i, arregloPrecip.a[i].HUM);
		printf ("arregloPrecip.a[%d].PNM = %d \n", i, arregloPrecip.a[i].PNM);
		printf ("arregloPrecip.a[%d].DV = %d \n", i, arregloPrecip.a[i].DV);
		printf ("arregloPrecip.a[%d].FF = %d \n", i, arregloPrecip.a[i].FF);
		printf ("arregloPrecip.a[%d].PP = %d \n", i, arregloPrecip.a[i].PP);
		printf ("arregloPrecip.a[%d].borrado = %d \n", i, arregloPrecip.a[i].borrado);
	}
	*/
	
	printf ("ListarTempMax \n");
	ListarTempMax(nombreArchivo, &listaTempMax);
	printf ("ListarMayMenVelViento \n");
	ListarMayMenVelViento(nombreArchivo);
	printf ("listaTempMax: %p \n", listaTempMax);
	printf ("MostrarLSETempMax \n");
	MostrarLSETempMax(listaTempMax);
	
	CopiaSeguridad(nombreArchivo);
	
	return 0;
}

int ArchVacio(char nom[20]){
    FILE* f;
    Tregdiario r;
   
    f = fopen(nom,"r+b");
    // Abrirlo con "r+b" posicionó el cabezal al inicio
    if ( fread(&r, sizeof(Tregdiario), 1, f) == 0 ){
        fclose(f);
        return 1;
    }else{
        do{
            if ( !r.borrado ){
                fclose(f);
                return 0;
            }
        } while ( fread(&r, sizeof(Tregdiario), 1, f) > 0 );
        if ( fread(&r, sizeof(Tregdiario), 1, f) <= 0 ){
			fclose(f);
			return 1;
		}
    }
    // no llega nunca acá, pero para q no salte el warning
    fclose(f);
    return 1;
}

void PedirFecha(int aA, long int *fecha){
    int EsBisiesto(int checkA){
		return ( ((checkA%4)==0 && (checkA%100)!=0) || ((checkA%100)==0 && (checkA%400)==0) );
	}
    int dA, mA;
    
    printf("Mes: ");
    scanf ("%d", &mA);
    // Def de meses
    if ( mA < 1 || mA > 12 ){
        do{
            printf ("Ingresar un mes válido: ");
            scanf ("%d", &mA);
        } while ( mA < 1 || mA > 12 );
    }
    
    printf ("Día: ");
    scanf ("%d", &dA);
    // Def de días
    if ( dA < 1 || dA > 31 ){
        do{
            printf ("Ingresar un día válido: ");
            scanf ("%d", &dA);
        } while ( dA < 1 || dA > 31 );
    }
    
    // Es bisiesto y puso una fecha inválida de febrero
    if ( EsBisiesto(aA) && mA == 2 && dA > 29 ) {
        do{
            printf ("Ingresar un día de febrero válido. El año ingresado es bisiesto: ");
            scanf ("%d", &dA);
        } while ( dA < 1 || dA > 29 );
	}
	
	// No es bisiesto y puso una fecha inválida de febrero
	if ( !EsBisiesto(aA) && mA == 2 && dA > 28 ) {
        do{
            printf ("Ingresar un día de febrero válido. El año ingresado no es bisiesto: ");
            scanf ("%d", &dA);
        } while ( dA < 1 || dA > 28 );
	}
	
	if ( (mA==4 || mA==5 || mA==6 || mA==9 || mA==11) && dA==31 ){
		do{
			printf ("Los meses 4, 5, 6, 9 y 11 tienen 30 días. Ingresar un día válido: ");
			scanf ("%d", &dA);
		} while ( (mA == 4 || mA == 5 || mA == 6 || mA == 9 || mA == 11) && dA == 31 );
	}
    
    *fecha = dA*1000000 + mA*10000 + aA;
}

void PedirAnio(int *anio){
	printf ("Año: ");
	scanf("%d", anio);
	if ( *anio < 1000 || *anio > 9999 ){
		do{
			printf ("Ingresar un año válido: ");
			scanf("%d", anio);
		} while ( *anio < 1000 || *anio > 9999);
	}
}

TData ArchArray(char nom[25]){
	TData registro;
    Tregdiario reg;
    int i;
    FILE *f;
    
    f = fopen(nom,"r+b");
    
    // Si lo abro y está vacio o todos borrados devuelvo el TData con cant = 0
    // sino devuelvo el TData con las cosas del archivo y el cant actualizado
    if ( ArchVacio(nom) ){
        registro.cant = 0;
    }else{
        i = 0; // inicializacion
        while ( fread(&reg, sizeof(Tregdiario), 1, f) > 0 && (i <= Max) ) {
            registro.a[i] = reg;
            i = i + 1;
        }
        registro.cant = i;
    }
    fclose(f);
    return registro;
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

void Suprimir(int anioEntry, char nom[20]){
	int PropEC(Tregdiario regArch, int fechaPedida){
		return ( regArch.ddmmyyyy == fechaPedida && !regArch.borrado );
	}
    long int fecha;
    Tregdiario rA;
    FILE* f;
    int rta;
   
    f = fopen(nom,"rb+");
    if ( ArchVacio(nom) ){
        printf ("No se puede suprimir porque el archivo está vacío o todos los registro están borrados.\nVuelve al menú principal. \n");
    }else{
		printf ("¿Desea suprimir un registro? 1/0: ");
		scanf("%d", &rta);
		if ( rta ){
			printf ("De que fecha es el registro que quiere suprimir?: \n");
			PedirFecha(anioEntry, &fecha);
			do{
			} while( fread(&rA, sizeof(Tregdiario), 1, f) > 0 && !PropEC(rA, fecha) );
			if ( PropEC(rA, fecha) ){
				rA.borrado = 1;
				fseek(f,(-1)*sizeof(Tregdiario), SEEK_CUR);
				fwrite(&rA, sizeof(Tregdiario), 1, f);
				printf("Suprimido con exito \n");
			}else{
				printf("No se encontró la fecha %ld para suprimir \n", fecha);
			}
        }else{
            printf("No se quiso suprimir nada. Vuelve al menú principal \n");
        }
    }
    fclose(f);
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
		printf ("Ingresar el porcentaje de humedad (de 0 a 100): ");
        scanf ("%d", &(*hA));
        if ( *hA < 0 || *hA > 100 ){
            do{
                printf ("Ingresar un porcentaje de humedad válido. Entre 0 y 100: ");
                scanf ("%d", &(*hA));
            } while ( *hA < 0 || *hA > 100 );
        }
    }
    void PedirDirViento(int *dvA){
		printf ("Ingresar la dirección del viento (de 0 a 360): ");
        scanf ("%d", &(*dvA));
        if ( *dvA < 0 || *dvA > 360 ){
            do{
                printf ("Ingresar una dirección de viento válida. Entre 0 y 360: ");
                scanf ("%d", &(*dvA));
            } while ( *dvA < 0 || *dvA > 360 );
        }
    }
    void PedirPresAtm(int *prA){
		printf ("Ingresar la presión atmosférica (de 900 a 3500): ");
        scanf ("%d", &(*prA));
        if ( *prA < 900 || *prA > 3500 ){
            do{
                printf ("Ingresar una presión atmosférica válida. Entre 900 y 3500: ");
                scanf ("%d", &(*prA));
            } while ( *prA < 900 || *prA > 3500 );
        }
    }
    void PedirVelocViento(int *wA){
		printf ("Ingresar la velocidad del viento (mayor que 0): ");
        scanf ("%d", &(*wA));
        if ( *wA <= 0 ){
            do{
                printf ("Ingresar una velocidad de viento válida. Debe ser positivo: ");
                scanf ("%d", &(*wA));
            } while ( *wA <= 0 );
        }
    }
    void PedirPrecPluv(int *ppA){
		printf ("Ingresar la precipitación pluvial (de 0 a 1000): ");
        scanf ("%d", &(*ppA));
        if ( *ppA < 0 || *ppA > 1000 ){
            do{
                printf ("Ingresar una precipitación pluvial válida. Entre 0 y 1000: ");
                scanf ("%d", &(*ppA));
            } while ( *ppA < 0 || *ppA > 1000 );
        }
    }
    FILE* fA;
    Tregdiario rA, captReg;
    int iguales;
   
    fA = fopen(nom, "r+b");
	PedirFecha(anioEntry, &rA.ddmmyyyy);
	iguales = 0;
	while ( fread(&captReg, sizeof(Tregdiario), 1, fA) > 0 && !iguales ){
		iguales = ( rA.ddmmyyyy == captReg.ddmmyyyy && !captReg.borrado );
	}
	if ( !iguales ){
        printf ("Ingresar la temperatura máxima de la fecha: ");
        PedirTemp(&rA.tmax);
        printf ("Ingresar la temperatura mínima de la fecha: ");
        PedirTemp(&rA.tmin);
        PedirHumedad(&rA.HUM);
        PedirPresAtm(&rA.PNM);
        PedirDirViento(&rA.DV);
        PedirVelocViento(&rA.FF);
        PedirPrecPluv(&rA.PP);
        rA.borrado = 0;
        fwrite(&rA, sizeof(rA), 1, fA);
    }else{
		printf ("Ya existe un registro presente con la fecha indicada. Vuelve al menú. \n");
	}
    fclose(fA);
}

void ModificarRegistro(int anioEntry, char nom[20]){
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
		printf ("Ingresar el porcentaje de humedad (de 0 a 100): ");
        scanf ("%d", &(*hA));
        if ( *hA < 0 || *hA > 100 ){
            do{
                printf ("Ingresar un porcentaje de humedad válido. Entre 0 y 100: ");
                scanf ("%d", &(*hA));
            } while ( *hA < 0 || *hA > 100 );
        }
    }
    void PedirDirViento(int *dvA){
		printf ("Ingresar la dirección del viento (de 0 a 360): ");
        scanf ("%d", &(*dvA));
        if ( *dvA < 0 || *dvA > 360 ){
            do{
                printf ("Ingresar una dirección de viento válida. Entre 0 y 360: ");
                scanf ("%d", &(*dvA));
            } while ( *dvA < 0 || *dvA > 360 );
        }
    }
    void PedirPresAtm(int *prA){
		printf ("Ingresar la presión atmosférica (de 900 a 3500): ");
        scanf ("%d", &(*prA));
        if ( *prA < 900 || *prA > 3500 ){
            do{
                printf ("Ingresar una presión atmosférica válida. Entre 900 y 3500: ");
                scanf ("%d", &(*prA));
            } while ( *prA < 900 || *prA > 3500 );
        }
    }
    void PedirVelocViento(int *wA){
		printf ("Ingresar la velocidad del viento (mayor que 0): ");
        scanf ("%d", &(*wA));
        if ( *wA <= 0 ){
            do{
                printf ("Ingresar una velocidad de viento válida. Debe ser positivo: ");
                scanf ("%d", &(*wA));
            } while ( *wA <= 0 );
        }
    }
    void PedirPrecPluv(int *ppA){
		printf ("Ingresar la precipitación pluvial (de 0 a 1000): ");
        scanf ("%d", &(*ppA));
        if ( *ppA < 0 || *ppA > 1000 ){
            do{
                printf ("Ingresar una precipitación pluvial válida. Entre 0 y 1000: ");
                scanf ("%d", &(*ppA));
            } while ( *ppA < 0 || *ppA > 1000 );
        }
    }
	int PropEC(Tregdiario reg, int fechaPedida){
		return ( reg.ddmmyyyy == fechaPedida && !reg.borrado );
	}
    long int fecha;
    FILE* f;
    Tregdiario regMod, regArch;
   
    f = fopen(nom,"r+b");
    if ( ArchVacio(nom) ){
        printf ("No se puede modificar porque el archivo está vacío o todos los registro están borrados.\nVuelve al menú principal. \n");
    }else{
		printf ("¿De que fecha es el registro que quiere modificar?: \n");
		PedirFecha(anioEntry, &fecha);
		do{
		} while( fread(&regArch, sizeof(Tregdiario), 1, f) > 0 && !PropEC(regArch, fecha) );
		if ( PropEC(regArch, fecha) ){
			fseek(f,(-1)*sizeof(Tregdiario), SEEK_CUR);
			printf ("Ingresar la temperatura máxima de la fecha: ");
			PedirTemp(&regMod.tmax);
			printf ("Ingresar la temperatura mínima de la fecha: ");
			PedirTemp(&regMod.tmin);
			PedirHumedad(&regMod.HUM);
			PedirPresAtm(&regMod.PNM);
			PedirDirViento(&regMod.DV);
			PedirVelocViento(&regMod.FF);
			PedirPrecPluv(&regMod.PP);
			regMod.ddmmyyyy = fecha;
			regMod.borrado = 0;
			fwrite(&regMod, sizeof(Tregdiario), 1, f);
			printf("Modificado con exito \n");
		}else{
			if ( regArch.ddmmyyyy == fecha && regArch.borrado ){
				printf ("La fecha a modificar está borrada. \n");
			}else{
				printf ("No se encontró la fecha a modificar. \n");
			}
		}
    }
    fclose(f);
}

void MostrarArchivo(char nom[25]){
    FILE* f;
    Tregdiario reg;
    int i = 1;
   
    f = fopen(nom ,"r+b");
    if ( ArchVacio(nom) ) {
        printf ("El archivo está vacío o todos sus registros están borrados. \n");
    }else{
        while ( fread(&reg, sizeof(Tregdiario), 1, f) > 0 ) {
            if ( !reg.borrado ){
				printf ("_____________________________\n");
				printf ("Registro nro %d: \n", i);
                i++;
                printf ("\n");
                printf ("Fecha: %ld \n", reg.ddmmyyyy);
                printf ("Temperatura máxima: %d \n", reg.tmax);
                printf ("Temperatura mínima: %d \n", reg.tmin);
                printf ("Porcentaje de humedad: %d \n", reg.HUM);
                printf ("Presión atmosférica: %d \n", reg.PNM);
                printf ("Dirección del viento: %d \n", reg.DV);
                printf ("Velocidad del viento: %d \n", reg.FF);
                printf ("Precipitación pluvial: %d \n", reg.PP);
                printf ("\n");
                // printf ("reg.borrado = %d \n", reg.borrado);
            }
        }
    }
    fclose(f);
}

int BuscaPosRecursiva(TData registro, int i, int fecha1){
    if ( i == registro.cant ){
        return -1;
    }else{
        if ( registro.a[i].ddmmyyyy == fecha1 ){
            return i;
        }else{
            return BuscaPosRecursiva(registro, i+1, fecha1);
        }
    }
}

void MostrarDatos_Pos(int i, TData registro){
    if ( i == -1 ){
        printf("No se encontró la fecha \n");
    }else{
        printf("¡Registro encontrado! \n");
        printf("Temp Máxima %d \n", registro.a[i].tmax);
        printf("Temp Mínima %d \n", registro.a[i].tmin);
        printf("Humedad %d \n", registro.a[i].HUM);
        printf("Presión atmosférica %d \n", registro.a[i].PNM);
        printf("Dirección del viento %d \n", registro.a[i].DV);
        printf("Velocidad de viento %d \n", registro.a[i].FF);
        printf("Precipitación anual %d \n", registro.a[i].PP);
    }
}

void VaciarListaConFict(Tnodo *q){
	Tnodo *aux, *aux2;
	
	aux = q->next;
	aux2 = aux;
	q->next = NULL;
	if ( aux != NULL ){
		while ( aux != NULL ){
			aux = aux->next;
			free(aux2);
			aux2 = aux;
		}
	}
}

void MostrarLSETempMax(Tnodo *q){
	while ( q->next != NULL ){
		q = q->next;
		printf ("Día registrado con temp máxima: %ld \n", q->info.ddmmyyyy);
		printf ("Temperatura máxima registrada: %d \n", q->info.tmax);
	}
}

void ListarTempMax(char nom[25], Tnodo* *s){
	FILE* f;
	Tnodo *aux, *nuevo;
	Tregdiario maxima, reg;
	
	f = fopen(nom, "r+b");
	*s = malloc (sizeof(Tnodo));
	(*s)->next = NULL;
	if ( ArchVacio(nom) ){
		printf ("El archivo está vacío \n");
	}else{
		do {
			fread(&reg, sizeof(Tregdiario), 1, f);
		} while ( reg.borrado );
		printf ("reg.tmax = %d \n", reg.tmax);
		maxima = reg;
		nuevo = malloc (sizeof(Tnodo));
		nuevo->info = maxima;
		nuevo->next = NULL;
		(*s)->next = nuevo;
		while ( fread(&reg, sizeof(Tregdiario), 1, f) > 0 ) {
			if ( maxima.tmax < reg.tmax && !reg.borrado ){
				maxima = reg;
				VaciarListaConFict(*s);
				*s = malloc (sizeof(Tnodo));
				(*s)->next = NULL;
				nuevo = malloc (sizeof(Tnodo));
				nuevo->info = maxima;
				nuevo->next = NULL;
				(*s)->next = nuevo;
			}else{
				if ( maxima.tmax == reg.tmax && !reg.borrado ){
					aux = malloc (sizeof(Tnodo));
					aux->info = reg;
					aux->next = NULL;
					nuevo->next = aux;
					nuevo = aux;
				}
			}
		}
	}
	fclose(f);
}

void OrdenarInsertionReves(TData *arr){
	int i, j;
	Tregdiario aux;
	
	for ( i = 1 ; i < arr->cant ; i++ ){
		aux = arr->a[i];
		for ( j = i - 1 ; j >= 0 && arr->a[j].PP < aux.PP ; j-- ){
			arr->a[j+1] = arr->a[j];
		}
		arr->a[j+1] = aux;
	}
}

void ListarPrecMax(char nom[25]){
	TData arregloPrecip;
	int i, aux;
	FILE* f;
	
	f = fopen(nom, "rb");
	if ( ArchVacio(nom) ){
		printf ("El archivo está vacío \n");
	}else{
		arregloPrecip = ArchArray(nom);
		OrdenarInsertionReves(&arregloPrecip);
		aux = 10;
		for ( i = 0 ; i < aux && i < arregloPrecip.cant ; i++ ){
			if ( !arregloPrecip.a[i].borrado ){
				printf ("Fecha: %ld \n", arregloPrecip.a[i].ddmmyyyy);
				printf ("Precipitación registrada: %d \n", arregloPrecip.a[i].PP);
			}else{
				aux++;
			}
		}
	}
	fclose(f);
}

void ListarMayMenVelViento(char nom[25]){
	TData arregloVientos;
	FILE* fA;
	int i, aux;
	
	fA = fopen(nom,"r+b");
	
	if ( ArchVacio(nom) ){
		printf ("El archivo está vacío \n");
	}else{
		arregloVientos = ArchArray(nom);
		OrdenarBubbleReves(&arregloVientos);
		aux = 10;
        for ( i = 0 ; i < aux && i < arregloVientos.cant ; i++ ){
			if ( !arregloVientos.a[i].borrado ){
				printf ("Fecha: %ld \n", arregloVientos.a[i].ddmmyyyy);
				printf ("Velocidad del viento registrada: %d \n", arregloVientos.a[i].FF);
			}else{
				aux++;
			}
		}
	}
	fclose(fA);
}

void OrdenarBubbleReves(TData *a){
	void Intercambiar(Tregdiario *x, Tregdiario *y){
		Tregdiario tmp;
		tmp = *x;
		*x = *y;
		*y = tmp;
	}
	int i, j;
	
	for ( i = 0 ; i < a->cant ; i++ ){
		for ( j = 0 ; j < (a->cant)-i-1 ; j++ ){
			if ( a->a[j].FF < a->a[j+1].FF ){
				Intercambiar(&(a->a[j]), &(a->a[j+1]));
			}
		}
	}
}

void CopiaSeguridad(char nom[25]){
	time_t t = time(NULL);
	struct tm *tm = localtime(&t);
	char hora[26];
	strftime(hora, sizeof(hora), "%c", tm);
	// hora tiene un formato de hora puesto, de tipo cadena
	FILE *gA, *fOld;
	char nomArch[25], extens[5];
	Tregdiario rA;
	int rta;
	
	fOld = fopen(nom, "r+b");
	if ( ArchVacio(nom) ){
		printf ("El archivo el cual se le realizará la copia de seguridad aún no tiene datos almacenados\n");
	}else{
		printf ("¿Realizar copia de seguridad? 1/0: ");
		scanf("%d", &rta);
		if ( rta ){
			printf ("Ingresar el nombre del archivo para la copia de seguridad (sin el .dat).\nSe concatenará la hora en que se realizó luego del nombre.\n");
			scanf("%[^\n]", nomArch);
			strcat(nomArch, "_");
			strcat(nomArch, hora);
			strcat(extens, ".dat");
			strcat(nomArch, extens);
			gA = fopen(nomArch, "w+b");
			while ( fread(&rA, sizeof(Tregdiario), 1, fOld) > 0 ){
				if ( !rA.borrado ){
					fwrite(&rA, sizeof(Tregdiario), 1, gA);
				}
			}
			fclose(gA);
			printf ("Copia de seguridad realizada con éxito. El archivo se llama: %s\n", nomArch);
		}else{
			printf ("Vuelve al menú principal. \n");
		}
	}
	fclose(fOld);
}
