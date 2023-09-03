// Arreglado 23/09. Capaz el EliminarPos todavía tenga problemas. El resto anda como debe.
// Arreglado 02/09. EliminarPos ahora anda bien :)
#include <stdio.h>
#include <stdlib.h>

struct TDoblete{
	int info;
	struct TDoblete *next;
};

void InsertarC(struct TDoblete **lista, int elem);
void InsertarF(struct TDoblete **lista, int elem);
void Inicializar(struct TDoblete **lista);
void VaciarL(struct TDoblete **lista);
void InsertarPos(int pos, int elem, struct TDoblete **lista);
void EliminarC(struct TDoblete **lista);
void EliminarPos(int pos, struct TDoblete **lista);
void Mostrar(struct TDoblete *lista);
void DesplegarMenu();

int main( int argc, char **argv ) {
	struct TDoblete *sec;
	int opcion;
	int posicion;
	int elemento;
	
	Inicializar(&sec);
	
	do{
		DesplegarMenu();
		
		scanf ("%d", &opcion);
		
		if ( opcion == 1 ){
			printf ("Ingresar un número entero a insertar a la cabecera de la lista: ");
			scanf ("%d", &elemento);
			InsertarC(&sec, elemento);
		}
		if ( opcion == 2 ){
			printf ("Ingresar un número entero a insertar al final de la lista: ");
			scanf ("%d", &elemento);
			InsertarF(&sec, elemento);
		}
		if ( opcion == 3 ){
			printf ("Ingresar la posición en la que quiere insertar un elemento: ");
			scanf ("%d", &posicion);
			printf ("Ingresar el elemento que quiere insertar en la posición %d de la lista: ", posicion);
			scanf ("%d", &elemento);
			InsertarPos(posicion, elemento, &sec);
		}
		if ( opcion == 4 ){
			EliminarC(&sec);
		}
		if ( opcion == 5 ){
			printf ("Ingresar la posición en la que quiere eliminar un elemento: ");
			scanf ("%d", &posicion);
			EliminarPos(posicion, &sec);
		}
		if ( opcion == 6 ){
			Mostrar(sec);
		}
		if ( opcion == 7 ){
			VaciarL(&sec);
		}
		if ( opcion >= 8 || opcion <= 0){
			printf ("Entró al Otros \n");	// Salir del programa...
		}
	} while ( (opcion > 0) && (opcion < 8) );
	
	return 0;
}

void InsertarC(struct TDoblete **lista, int elem){
	struct TDoblete* aux;
	
	if ( *lista == NULL ){
		*lista = (struct TDoblete *) malloc(sizeof(struct TDoblete));
		(*lista)->next = NULL;
		(*lista)->info = elem;
	}else{
		aux = (struct TDoblete *) malloc(sizeof(struct TDoblete));
		aux->info = elem;
		aux->next = *lista;
		*lista = aux;
	}
	printf ("El número %d fue ingresado al comienzo. \n", (*lista)->info);
}

void InsertarF(struct TDoblete **lista, int elem){
	struct TDoblete *aux, *aux2;
	
	if ( *lista == NULL ){	// Inserción en lista vacía.
		printf ("La lista está vacía, se insertará al comienzo \n");
		InsertarC(lista, elem);
	}else{
		aux = malloc (sizeof(struct TDoblete));
		aux2 = *lista;
		while ( aux2->next != NULL ){
			aux2 = aux2->next;
		}
		aux->info = elem;
		aux->next = NULL;
		aux2->next = aux;
		printf ("Número %d insertado en la lista \n", aux->info);
		// printf ("Lista apunta a %p y aux apunta a %p \n", lista, aux->next);
	}
}

void Inicializar(struct TDoblete **lista){
	*lista = NULL;
}

void VaciarL(struct TDoblete **lista){
	struct TDoblete *aux;
	
	if ( *lista != NULL ){
		do{
			aux = *lista;
			*lista = (*lista)->next;
			free(aux);
		} while ( !( *lista == NULL ) );
		printf ("Vaciado de lista realizado. \n");
	}else{
		printf ("La lista ya estaba vacía. \n");
	}
}

void InsertarPos(int pos, int elem, struct TDoblete **lista){
	struct TDoblete *aux, *aux2;
	int i;
	
	if ( *lista == NULL || pos == 1 ){
		printf("Se insertará al comienzo \n");
		InsertarC(lista, elem);
	}else{
		i = 2;
		aux = *lista;
		
		while ( aux->next != NULL && i < pos ){
			aux = aux->next;
			i++;
		}
		
		if ( aux == NULL ){
			printf ("No se alcanzó la posición. Se insertará al final \n");
			InsertarF(lista, elem);
		}else{
			aux2 = malloc(sizeof(struct TDoblete));
			aux2->info = elem;
			aux2->next = aux->next;
			aux->next = aux2;
			printf ("Elemento %d en la posición %d insertado correctamente. \n", elem, pos);
		}
	}
}

void EliminarC(struct TDoblete **lista){
	struct TDoblete *aux;
	
	if ( *lista == NULL ){
		printf ("Imposible eliminar. La lista ya está vacía \n");
	}else{
		aux = *lista;
		*lista = (*lista)->next;
		free(aux);
		printf ("Cabecera eliminada. \n");
	}
}

void EliminarPos(int pos, struct TDoblete **lista){
	struct TDoblete *aux, *aux2;
	int i, cantElem;
	
	if ( *lista == NULL ){
		printf ("Imposible eliminar. La lista está vacía \n");
	}else{
		if ( pos <= 1 ){
			EliminarC(lista);
		}else{
			i = 2;
            cantElem = 0;
			aux = *lista;
			
			while( aux != NULL && i <= pos){
				aux = aux->next;
				i++;
                cantElem++;
			}
			
			if ( aux != NULL ){
				aux2 = *lista;
				while ( aux2->next != aux ){
					aux2 = aux2->next;
				}
				aux2->next = aux->next;
				free(aux);
			}else{
                if ( cantElem < pos ){
                    printf ("No se eliminó nada porque la posición supera a la cantidad de elementos \n");
                    return;
                }else{
                    aux = *lista;
                    i = 2;
                    while ( i < pos ){
                        aux = aux->next;
                    }
                    free(aux);
                }
			}
		}
		printf ("El elemento de la posición %d fue eliminado. \n", pos);
	}
}

void Mostrar(struct TDoblete *lista){
	if ( lista == NULL ){
		printf ("La lista está vacía \n");
	}else{
		printf ("-·- Inicio Accion Mostrar -·- \n");
		
		while ( lista != NULL ){
			printf("%d \n", lista->info);
			lista = lista->next;
		}
		printf ("_._ Fin Accion Mostrar _._ \n");
	}
}

void DesplegarMenu(){
	printf ("·\tPrincipio del menú. \n");
	printf ("\n");
	printf ("Poner una opción del 1 al 7. Cualquier otro valor termina el programa. \n");
	printf ("1: InsertarC. 	 \n");
	printf ("2: InsertarF. 	 \n");
	printf ("3: InsertarPos. \n");
	printf ("4: EliminarC. 	 \n");
	printf ("5: EliminarPos. \n");
	printf ("6: Mostrar.	 \n");
	printf ("7: VaciarL. 	 \n");
	printf ("\tOpción: ");
}
