/* Realizar una acción carga() que permita cargar caracteres en una lista simplemente 
 * encadenada. Cada nodo contiene sólo un carácter. Luego desarrolle una acción que permita 
 * sacar por la salida todos los caracteres que sigan a la primera x cargada en la lista. 
 * Hacer un algoritmo que implemente las acciones y las utilice en su cuerpo principal. */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct TNodo{
	char info;
	struct TNodo* next;
} TNodo;

void Inicializar (TNodo* *q);
void MostrarLSEcF (TNodo* q);
void Carga (TNodo *q);
FILE* SaveFile (TNodo *q);
void MostrarDespX (TNodo *q);

int main( int argc, char **argv ) {
	TNodo* sec;
	FILE* file;
	char c;
	
	Inicializar(&sec);
	Carga(sec);
	MostrarLSEcF(sec);
	file = SaveFile(sec);
	MostrarDespX(sec);
	
	// MostrarArchivo(file)
	file = fopen("CierreP13.txt", "r");
	fread(&c, sizeof(c), 1, file);
	
	if ( feof(file) ){
		printf ("Archivo vacío \n");
	}else{
		// int i = 1;
		printf ("MostrarArchivo: \n");
		
		do{
			printf ("%c", c);
			fread(&c, sizeof(c), 1, file);
			// i++;
		} while ( !feof(file) );
	}
	
	fclose(file);
	
	return 0;
}

void Inicializar (TNodo* *q){
	*q = (TNodo *) malloc (sizeof(TNodo));
	(*q)->next = NULL;
}

void MostrarLSEcF (TNodo* q){
	q = q->next;
	
	if ( q ){	// Si ( q <> nil ) entonces
		int i = 1;
		
		while ( q ){	// Mientras ( q <> nil ) hacer
			printf ("Caracter %d: %c \n", i, q->info);
			i++;
			q = q->next;
		}
	}else{
		printf ("La lista está vacía \n");
	}
}

void Carga (TNodo *q){
	TNodo *aux2;
	char cA;
	
	aux2 = NULL;
	
	do{	// Repetir Hasta que ( cA = '*')
		printf ("Cargar lista. Poner un * para detener \n");
		scanf("%s", &cA);
		
		if ( cA != '*' ){
			aux2 = (TNodo *) malloc (sizeof(TNodo));
			aux2->info = cA;
			aux2->next = NULL;
			q->next = aux2;
			q = aux2;
		}
	} while ( !(cA == '*') );
}

FILE* SaveFile (TNodo *q){
	FILE* f;
	
	f = fopen ("CierreP13.txt", "w");
	q = q->next;
	
	while ( q ){	// Mientras ( q <> nil ) hacer
		errno = fputc(q->info, f);	// probando errno xd
		// errno = fwrite(&(q->info), sizeof(q->info), 1, f); // probando errno xd
		// errno = fprintf (f, "%c", q->info);	// probando errno xd
		q = q->next;
	}
	
	/*	printf ("%d errno \n", errno);
	char haberche[50];
	perror(haberche);
	printf ("Error description is : %s \n", strerror(errno));*/
	
	fclose(f);
	
	return f;
}

void MostrarDespX (TNodo *q){
	char lookingFor;
	
	q = q->next;
	
	if ( !q ){	// Si ( q = nil ) entonces
		printf ("MostrarDespX: Lista vacía \n");
	}else{
		// scanf ("%s", lookingFor); = Entrada: lookingFor
		// while(getchar() != '\n');
		// funcion que capura el caracter "\n" (enter) para que no quede guardado en la cadena.
		lookingFor = 'x';
	
		while ( q && ( q->info != lookingFor ) ){	// Mientras ( q <> nil y (^q).info <> lF ) hacer
			q = q->next;
		}
	
		if ( q ){	// Si ( q <> nil ) entonces
			q = q->next;
			int i = 1;
	
			while ( q ){	// Mientras ( q <> nil ) hacer
				printf ("Caracter nro %d después de la letra %c pedida: %c \n", i, lookingFor, q->info);
				q = q->next;
				i++;
			}
		}else{
			printf ("No se encontraron 'x' en la lista \n");
		}
	}
}
