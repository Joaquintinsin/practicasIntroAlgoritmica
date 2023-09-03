#include <stdio.h>
#include <stdlib.h>

typedef struct TDoblete{
	int info;
	struct TDoblete *next;
} TDoblete;

void InsertarC(TDoblete **lista, int elem);
void InsertarF(int elem, TDoblete *lista);
void Inicializar(TDoblete **lista);
void VaciarL(TDoblete **lista);
void InsertarPos(int pos, int elem, TDoblete **lista);
void EliminarC(TDoblete **lista);
void EliminarPos(int pos,  TDoblete **lista);
void Mostrar(TDoblete *lista);
void DesplegarMenu();

int main( int argc, char **argv ) {
	TDoblete *sec;
	int opcion;
	int posicion;
	int elemento;
	
	do{
		DesplegarMenu();
		
		do{
			scanf ("%d", &opcion);
			if ( opcion <= 0 ){
				printf ("Del 1 en adelante locura \n");
			}
		} while ( !( opcion > 0 ) );
		
		if ( opcion == 1 ){
			printf ("Ingresar un número entero a insertar a la cabecera de la lista: ");
			scanf ("%d", &elemento);
			if ( sec != NULL ){
				InsertarC(&sec, elemento);
				printf ("El número %d fue ingresado al comienzo. \n", elemento);
			}else{
				Inicializar(&sec);
				printf ("La lista 'sec' fue inicializada. \n");
				InsertarC(&sec, elemento);
				printf ("El número %d fue ingresado al comienzo. \n", elemento);
			}
		}else{
			if ( opcion == 2 ){
				printf ("Ingresar un número entero a insertar al final de la lista: ");
				scanf ("%d", &elemento);
				InsertarF(elemento, sec);
				printf ("El número %d fue ingresado al final. \n", elemento);
			}else{
				if ( opcion == 3 ){
					Inicializar(&sec);
					printf ("La lista 'sec' fue inicializada. \n");
				}else{
					if ( opcion == 4 ){
						printf ("Ingresar la posición en la que quiere insertar un elemento: ");
						scanf ("%d", &posicion);
						printf ("Ingresar el elemento que quiere insertar en la posición %d de la lista: ", posicion);
						scanf ("%d", &elemento);
						InsertarPos(posicion, elemento, &sec);
						printf ("Elemento %d en la posición %d insertado correctamente. \n", elemento, posicion);
					}else{
						if ( opcion == 5 ){
							EliminarC(&sec);
							printf ("Cabecera eliminada. \n");
						}else{
							if ( opcion == 6 ){
								printf ("Ingresar la posición en la que quiere eliminar un elemento: ");
								scanf ("%d", &posicion);
								EliminarPos(posicion, &sec);
								printf ("El elemento de la posición %d fue eliminado. \n", posicion);
							}else{
								if ( opcion == 7 ){
									printf ("...Inicio Accion Mostrar... \n");
									Mostrar(sec);
									printf ("...Fin Accion Mostrar... \n");
								}else{
									if ( opcion == 8 ){
										VaciarL(&sec);
										printf ("Vaciado de lista realizado. \n");
									}else{
										printf ("Entró al Otros \n");	// nada...
									}
								}
							}
						}
					}
				}
			}
		}
		
	} while ( !( opcion >= 9 ) );
	
	return 0;
}

void InsertarC(TDoblete **lista, int elem){
	TDoblete *aux;
	
	aux = (TDoblete *) malloc(sizeof(TDoblete));
	aux->next = (*lista)->next;
	aux->info = elem;
	*lista = aux;
}

void InsertarF(int elem, TDoblete *lista){
	TDoblete *aux, *aux2;
	
	aux = lista;
	aux->next = lista->next;
	
	while ( aux->next != NULL ){
		aux = aux->next;
	}
	
	aux2 = (TDoblete *) malloc(sizeof(TDoblete));
	aux2->next = NULL;
	aux2->info = elem;
	aux->next = aux2;
}

void Inicializar(TDoblete **lista){
	*lista = (TDoblete *) malloc(sizeof(TDoblete));
	(*lista)->next = NULL;
}

void VaciarL(TDoblete **lista){
	TDoblete *aux;
	
	if ( *lista != NULL ){
		do{
			aux = *lista;
			*lista = (*lista)->next;
			free(aux);
		} while ( *lista != NULL );
	}
}

void InsertarPos(int pos, int elem, TDoblete **lista){
	TDoblete *aux;
	int i;
	
	i = 1;
	aux = (TDoblete *) malloc(sizeof(TDoblete));
	aux = *lista;
	
	while( i != pos && aux->next != NULL ){
		aux->next = aux->next;
		i++;
	}
	
	aux->info = elem;
}

void EliminarC(TDoblete **lista){
	TDoblete *aux;
	
	aux = *lista;
	*lista = (*lista)->next;
	free(aux);
}

void EliminarPos(int pos, TDoblete **lista){
	TDoblete *aux, *aux2;
	int i;
	
	i = 1;
	aux = *lista;
	
	while( i < pos || aux->next != NULL ){
		aux = aux->next;
		i++;
	}
	
	if ( aux->next != NULL ){
		aux2 = aux;
		aux = aux->next;
		aux2->next = aux->next;
		free(aux);
	}else{
		*lista = NULL;
		free(aux);
	}
}

void Mostrar(TDoblete *lista){
	TDoblete *aux;
	
	aux = lista;
	
	if ( aux != NULL ){
		while ( aux->next != NULL ){
			printf("%d \n", aux->info);
			aux = aux->next;
		}
	}
}

void DesplegarMenu(){
	printf ("\n");
	printf ("Principio del menú. \n");
	printf ("\n");
	printf ("Poner una opción del 1 al 9. Poner 9 o más si quiere salir. \n");
	printf ("1: InsertarC. 	 \n");
	printf ("2: InsertarF. 	 \n");
	printf ("3: Inicializar. \n");
	printf ("4: InsertarPos. \n");
	printf ("5: EliminarC. 	 \n");
	printf ("6: EliminarPos. \n");
	printf ("7: Mostrar.	 \n");
	printf ("8: VaciarL. 	 \n");
}
