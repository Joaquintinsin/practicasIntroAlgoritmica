// Implementación con cadena
#include <stdio.h>
#include <stdlib.h>

typedef struct TElem{
	char info;
	struct TElem* next;
}TElem;

void CargarLista(TElem* *q);

int main( int argc, char **argv ) {
	TElem* cab;
	TElem* aux;
	char pri;
	char seg;
	int contador;
	
	CargarLista(&cab);
	aux = cab;
	if ( aux->next == NULL ){
		printf ("La lista está vacía \n");
	}else{
		contador = 0;
		do{
			aux = aux->next;
			pri = aux->info;
			// printf("pri 1: %c \n", pri);
			if ( aux->next != NULL && aux->next->info != '\0' ){	
				seg = aux->next->info;
				// printf("seg: %c \n", pri);
			}else{
				// si llega a nil o si toca la marca real (\0) en el arreglo de caracteres
				// a seg le pone un espacio
				seg = ' ';
			}
			if ( pri == 'a' && seg == ' ' ){
				// printf("pri 2: %c \n", pri);
				contador++;
			}
		} while ( !( aux->next == NULL ) );
		printf("Salida: contador = %d", contador);
	}
	
	return 0;
}

void CargarLista(TElem* *q){
	TElem* aux;
	TElem* aux2;
	int rta; // Lógico
	char str[226];
	int i = 0;
	
	*q = malloc(sizeof(TElem));
	aux = *q;
	printf ("¿Cargar frase? 0 = No, Otro valor = Si \n");
	scanf("%d\n", &rta);
	
	if ( rta ){
		printf("Ingresar frase: ");
		scanf("%[^\n]", str);	// termina en \0...
		// for ( i = 0 ; i < 20 ; i++) printf("str %d: %c \n", i, str[i]);
		while ( str[i] == ' ' || str[i] != '\0' ){
			// printf("str %d: %c \n", i, str[i]);
			aux2 = malloc(sizeof(TElem));
			aux2->info = str[i];
			aux2->next = NULL;
			aux->next = aux2;
			aux = aux2;
			i++;
		}
	}
}
