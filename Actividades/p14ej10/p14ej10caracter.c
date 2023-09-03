// Implementación caracter a caracter
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
			if ( aux->next != NULL ){
				seg = aux->next->info;
			}else{
				seg = ' ';
			}
			if ( pri == 'a' && seg == ' ' ){
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
	
	*q = malloc(sizeof(TElem));
	aux = *q;
	printf ("¿Cargar caracter? 0 = No, Otro valor = Si \n");
	scanf("%d", &rta);
	
	while ( rta ){
		aux2 = malloc(sizeof(TElem));
		while ( getchar() != '\n' );	// evita tomar el enter como un caracter
		printf("Ingresar caracter: ");
		scanf("%[^\n]", &(aux2->info));
		aux2->next = NULL;
		aux->next = aux2;
		aux = aux2;
		printf ("¿Seguir cargando? 0 = No, Otro valor = Si \n");
		scanf("%d", &rta);
	}
}

/*
10) Dada una Lista simplemente encadenada (LSE con ficticio) de caracteres, donde las letras forman una frase. El puntero Cab que 
	apunta a la lista, desarrolle un algoritmo que cuente cuántos palabras terminan con la letra “a”. Cada nodo es de la forma 
	elem=<info ∈ Carater, next ∈ puntero de elem>.

Algoritmo PalabrasTermConA
Léxico
	TElem = < info ∈ Carater, next ∈ puntero de TElem >
	Acción CargarLista(resultado q e puntero a TElem)
	Léxico local
		aux, aux2 e puntero a TElem
		rta e Lógico
	Inicio
		Obtener(q)
		aux <-- q
		Entrada: rta	// ¿Cargar caracter?
		Mientras ( rta ) hacer
			Obtener(aux2)
			Entrada: (^aux2).info
			(^aux2).next <-- nil
			(^aux).next <-- aux2
			aux <-- aux2
		Fmientras
	Facción
	cab, aux e puntero a TElem
	pri, seg e Caracter
	contador e Z
Inicio
	CargarLista(cab)
	aux <-- cab
	Si ( (^aux).next = nil ) entonces
		Salida: "La lista está vacía"
	sino
		contador <-- 0												Funciona para frases empezadas en 'a'
		Repetir														aux <-- (^aux).next
			aux <-- (^aux).next										contador <-- 0
			pri <-- (^aux).info										seg <-- (^aux).info
			Si ( (^aux).next <> nil ) entonces						Si ( seg = 'a' ) entonces
				seg <-- (^(^aux).next).info							contador <-- contador + 1
			sino													Fsi
				seg <-- ' '											Mientras ( (^aux).next <> nil ) hacer
			Fsi															aux <-- (^aux).next
			Si ( pri = 'a' y seg = ' ' ) entonces							pri <-- seg
				contador <-- contador + 1							seg <-- (^aux).info
			Fsi															Si ( pri = ' ' y seg = 'a' ) entonces
		Hasta que ( (^aux).next = nil )									contador <-- contador + 1
		Salida: contador												Fsi
	Fsi																Fmientras
																	Salida: contador
Fin
*/
