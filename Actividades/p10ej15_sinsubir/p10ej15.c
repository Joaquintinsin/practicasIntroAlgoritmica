// Después de Calcular() muestra dos veces el mismo empleado. Le pone sueldo solamente al último
// Arreglarrrr

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TPers{
	char ape[25];
	char nom[25];
	int antiguedad;	// Z+
	float basico;
	int borrado;	// Lógico
}TPers;

void LeerArchivo(char nomArc[50], FILE* *fA);
void Alta(char nomArc[25], FILE* *fA);
void Baja(char nomArc[25], FILE* *fA);
void Modificar(char nomArc[25], FILE* *fA);
void Listar(char nomArc[25], FILE *fA);
void Calcular(char nomArc[25], FILE* *fA);
void Salir(char nomArc[25], int *opc);

int main( int argc, char **argv ) {
	char nombreArchivo[25];
	FILE* f;
	int opcionEntry; // (0..6)
	
	strcpy(nombreArchivo,"personal.dat");
	LeerArchivo(nombreArchivo,&f);
	do{
		printf ("· Menú principal \n");
		printf ("  Seleccione una opción \n");
		printf ("\t1. Dar de alta un empleado. \n");
		printf ("\t2. Dar de baja un registro (por posición). \n");
		printf ("\t3. Modificar datos del empleado (por apellido). \n");
		printf ("\t4. Mostrar los datos de los empleados. \n");
		printf ("\t5. Calcular el sueldo de los empleados. \n");
		printf ("\t6. Salir. \n");
		do{
			printf ("\t Opcion: ");
			scanf("%d", &opcionEntry);
			if ( opcionEntry < 1 || opcionEntry > 6 ){
				printf ("Del 1 al 6 \n");
			}
		} while ( !( opcionEntry >= 1 && opcionEntry <= 6 ) );
		
		if ( opcionEntry == 1 ){
			printf("Opción 1: Dar de alta \n");
			Alta(nombreArchivo, &f);
		}
		if ( opcionEntry == 2 ){
			printf ("Opción 2: Dar de baja \n");
			Baja(nombreArchivo, &f);
		}
		if ( opcionEntry == 3 ){
			printf ("Opción 3: Modificar \n");
			Modificar(nombreArchivo, &f);
		}
		if ( opcionEntry == 4 ){
			printf ("Opción 4: Listar \n");
			Listar(nombreArchivo, f);
		}
		if ( opcionEntry == 5 ){
			printf ("Opción 5: Calcular \n");
			Calcular(nombreArchivo, &f);
		}
		if ( opcionEntry == 6 ){
			printf ("Opción 6: Salir \n");
			Salir(nombreArchivo, &opcionEntry);
		}
	} while ( !( opcionEntry == 6 ) );
	
	
	return 0;
}

void LeerArchivo(char nomArc[50], FILE* *fA){
	TPers pers;
	
	*fA = fopen(nomArc, "a+b");
	
	fread(&pers,sizeof(TPers),1,*fA);
	if ( feof(*fA) ){
		if ( !( pers.borrado ) ){
			printf ("Apellido del empleado: %s \n", pers.ape);
			printf ("Nombre del empleado: %s \n", pers.nom);
			printf ("Antiguedad del empleado: %d \n", pers.antiguedad);
			if ( pers.basico != -1 ){
				printf ("Sueldo del empleado: %f \n", pers.basico);
			}
		}
		fread(&pers,sizeof(TPers),1,*fA);
	}
}

void Alta(char nomArc[25], FILE* *fA){
	TPers pers;
	
	*fA = fopen(nomArc, "a+b");
	printf ("Ingresar apellido: ");
	scanf("%s", pers.ape);
	printf ("Ingresar nombre: ");
	scanf("%s", pers.nom);
	printf ("Ingresar antigüedad: ");
	scanf("%d", &pers.antiguedad);
	pers.basico = -1;
	pers.borrado = 0;	// Falso
	fwrite(&pers,sizeof(TPers),1,*fA);
	fclose(*fA);
	getchar();
}

void Baja(char nomArc[25], FILE* *fA){
	TPers pers;
	int posReg; // Natural
	
	printf("Ingrese la posición del registro que quiere dar de baja: ");
	do{
		scanf("%d", &posReg);
		if ( posReg <= 0 ){
			printf ("Debe ser un nro natural \n");
		}
	}while ( !( posReg > 0 ) );
	*fA = fopen(nomArc, "r+b");
	
	// fseek(*fA, 0, SEEK_END); sitúa el cursor de lectura/escritura al final del archivo.
	if ( posReg <= fseek(*fA, 0, SEEK_END) ){
		fseek(*fA, posReg, SEEK_END);
		fread(&pers,sizeof(TPers),1,*fA);
		if ( !( pers.borrado ) ){
			fseek(*fA, posReg, SEEK_END);
			pers.borrado = 1;
		}else{
			printf ("El registro ya está borrado \n");
		}
	}else{
		printf ("Posición inexistente \n");
	}
}

void Modificar(char nomArc[25], FILE* *fA){
	typedef enum TEnum{
		Nombre, Antiguedad //, Basico, Borrado
	}TEnum;
	typedef enum TRta{
		Si, No
	}TRta;
	
	TEnum modify;
	char apellido[25];
	TRta rta;
	TPers emp;
	int aux;
	
	printf ("¿Desea modificar? Si/No: \n");
	printf ("Enumerado... 0=Si, 1=No \n");
	scanf("%u", &rta);
	if ( rta == Si ){
		printf ("Ingrese el apellido del empleado que quiere modificar: ");
		scanf("%s", apellido);
		*fA = fopen(nomArc, "r+b");
		aux = 1;
		
		fread(&emp,sizeof(TPers),1,*fA);
		while ( !( feof(*fA) ) ){
			aux++;
			fread(&emp,sizeof(TPers),1,*fA);
			if ( strcmp(apellido, emp.ape) == 0 ){
				aux = 1;
				fseek(*fA, 0, ftell(*fA)-1);
				do{
					printf("¿Qué quiere modificar?: \n");
					printf ("Enumerado... 0=Nombre, 1=Antiguedad \n");
					scanf("%u", &modify);
					if ( modify == Nombre ){
						scanf("%s", emp.nom);
						fwrite(&emp,sizeof(emp),1,*fA);
						fseek(*fA, 0, ftell(*fA)-1);	// IrPos(fA, PosicionActual(fA)-1)
					}else{
						if ( modify == Antiguedad ){
							scanf("%d", &emp.antiguedad);
							fwrite(&emp,sizeof(emp),1,*fA);
							fseek(*fA, 0, ftell(*fA)-1);	// IrPos(fA, PosicionActual(fA)-1)
						}else{
							/*
							if ( modify == Basico ){
								scanf("%f", &emp.basico);
								fwrite(&emp,sizeof(emp),1,*fA);
								fseek(*fA, 0, ftell(*fA)-1);	// IrPos(fA, PosicionActual(fA)-1)
							}else{
								scanf("%d", &emp.borrado);
								fwrite(&emp,sizeof(emp),1,*fA);
								fseek(*fA, 0, ftell(*fA)-1);	// IrPos(fA, PosicionActual(fA)-1)
							}
							*/
						}
					}
					printf ("¿Desea seguir modificando? Si/No \n");
					printf ("Enumerado... 0=Si, 1=No \n");
					scanf("%u",&rta);
				}while ( !( rta == No ) );
			}
		}
		fseek(*fA, 0, SEEK_END); // sitúa el cursor de lectura/escritura al final del archivo.
		if ( aux > ftell(*fA) ){
			printf ("Apellido inexistente. \n");
		}
		fclose(*fA);
	}else{
		printf ("No se quiso modificar nada. \n");
	}
}

void Listar(char nomArc[25], FILE *fA){
	TPers emp;
	
	fA = fopen(nomArc, "r+b");
	fread(&emp,sizeof(emp),1,fA);
	if ( !( feof(fA) ) ){
		while ( !( feof(fA) ) ){
			if ( !( emp.borrado ) ){
				printf ("Apellido del empleado: %s \n", emp.ape);
				printf ("Nombre del empleado: %s \n", emp.nom);
				printf ("Antigüedad del empleado: %d \n", emp.antiguedad);
				if ( emp.basico != -1 ){
					printf ("Sueldo del empleado: %f \n", emp.basico);
				}else{
					printf ("El empleado %s %s aún no tiene asignado un sueldo. \n", emp.nom, emp.ape);
				}
			}
			fread(&emp,sizeof(emp),1,fA);
		}
	}else{
		printf ("El archivo está vacío \n");
	}
	fclose(fA);
}

void Calcular(char nomArc[25], FILE* *fA){
	#define MontoConvenio 30
	float sueBas;
	TPers emp;
	
	*fA = fopen(nomArc,"a+b");
	fseek(*fA, 0, SEEK_SET);	// Abro en modo a: me voy al último. Vuelvo al princpio
	printf ("Ingrese el sueldo básico común para todos los empleados: ");
	scanf ("%f", &sueBas);
	fread(&emp,sizeof(emp),1,*fA);
	while ( !feof(*fA) ){
		emp.basico = sueBas + ( MontoConvenio * emp.antiguedad );
		fseek(*fA, ftell(*fA)-1, SEEK_CUR);	// IrPos( fA, PosicionActual(fA) - 1 )
		fwrite(&emp, sizeof(emp), 1, *fA);
		fread(&emp,sizeof(emp),1,*fA);
	}
	fclose(*fA);
}

void Salir(char nomArc[25], int *opc){
	typedef enum TRta{
		Si, No
	}TRta;
	TRta rta;
	
	printf("¿Terminar el programa? Si/No \n");
	printf ("Enumerado... 0=Si, 1=No \n");
	scanf("%u", &rta);
	if ( rta == Si ){
		printf ("Salida exitosa. \nEl archivo que contiene los datos del programa se llama %s. \n", nomArc);
	}else{
		*opc = 0;
		printf ("Vuelve al menú de opciones. \n");
	}
}
