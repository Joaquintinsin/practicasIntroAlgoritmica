// No anda bien, tiene problemas por to los laos

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nombre[50];
	char telefono[25];
	char direccion[50];
	int edad;
} TEmpleado;

struct TDoblete{
	TEmpleado info;
	struct TDoblete *next;
};

void InsertarC(struct TDoblete *lista, TEmpleado elem);
void InsertarF(TEmpleado elem, struct TDoblete *q);
void Inicializar(struct TDoblete **lista);
void VaciarL(struct TDoblete *q);
void InsertarPos(int pos, TEmpleado elem, struct TDoblete *lista);
void EliminarC(struct TDoblete *lista);
void EliminarPos(int pos, struct TDoblete *lista);
void Mostrar(struct TDoblete *lista);
int Vacia(struct TDoblete *lista);
void DesplegarMenu();

int main( int argc, char **argv ) {
	struct TDoblete *sec;
	int opcion;
	int posicion;
	TEmpleado elemento;
	
	sec = NULL;
	
	do{
		DesplegarMenu();
		
		do{
			scanf ("%d", &opcion);
			if ( opcion <= 0 || opcion >= 10){
				printf ("Del 1 al 9. \n");
			}
		} while ( !( opcion >= 1 && opcion <= 9 ) );
		
		if ( opcion == 1 ){
			printf ("Opcion nro 1 \n");
			if ( Vacia(sec) ){
				printf ("Se debe Inicializar la lista primero (opcion 3) \n");
			}else{
				printf ("Ingresar el nombre del empleado a insertar a la cabecera de la lista: ");
				scanf ("%s", elemento.nombre);
				printf ("El nombre %s fue ingresado al comienzo. \n", elemento.nombre);
				
				printf ("Ingresar el telefono del empleado a insertar a la cabecera de la lista: ");
				scanf ("%s", elemento.telefono);
				printf ("El telefono %s fue ingresado al comienzo. \n", elemento.telefono);
				
				printf ("Ingresar la direccion del empleado a insertar a la cabecera de la lista: ");
				scanf ("%s", elemento.direccion);
				printf ("La direccion %s fue ingresado al comienzo. \n", elemento.direccion);
				
				printf ("Ingresar la edad del empleado a insertar a la cabecera de la lista: ");
				scanf ("%d", &elemento.edad);
				printf ("La edad %d fue ingresado al comienzo. \n", elemento.edad);
				
				InsertarC(sec, elemento);
			}
		}else{
			if ( opcion == 2 ){
				printf ("Opcion nro 2 \n");
				if ( Vacia(sec) ){
					printf ("Se debe Inicializar la lista primero (opcion 3) \n");
				}else{
					printf ("Ingresar el nombre del empleado a insertar al final de la lista: ");
					scanf ("%s", elemento.nombre);
					printf ("El nombre %s fue ingresado al final. \n", elemento.nombre);
					
					printf ("Ingresar el telefono del empleado a insertar al final de la lista: ");
					scanf ("%s", elemento.telefono);
					printf ("El telefono %s fue ingresado al final. \n", elemento.telefono);
					
					printf ("Ingresar la direccion del empleado a insertar al final de la lista: ");
					scanf ("%s", elemento.direccion);
					printf ("La direccion %s fue ingresado al final. \n", elemento.direccion);
					
					printf ("Ingresar la edad del empleado a insertar al final de la lista: ");
					scanf ("%d", &elemento.edad);
					printf ("La edad %d fue ingresado al final. \n", elemento.edad);
					
					InsertarF(elemento, sec);
				}
			}else{
				if ( opcion == 3 ){
					printf ("Opcion nro 3 \n");
					if ( Vacia(sec) ){
						Inicializar(&sec);
						printf ("La lista 'sec' fue inicializada. \n");
					}else{
						printf ("Ya existe una lista en el programa \n");
					}
				}else{
					if ( opcion == 4 ){
						printf ("Opcion nro 4 \n");
						if ( Vacia(sec) ){
							printf ("Se debe inicializar una lista primero (opcion 3) \n");
						}else{
							printf ("Ingresar la posición en la que quiere insertar un elemento: ");
							scanf ("%d", &posicion);
							printf ("Ingresar el nombre del empleado que quiere insertar en la posición %d de la lista: ", posicion);
							scanf ("%s", elemento.nombre);
							printf ("Ingresar el telefono del empleado que quiere insertar en la posición %d de la lista: ", posicion);
							scanf ("%s", elemento.telefono);
							printf ("Ingresar la direccion del empleado que quiere insertar en la posición %d de la lista: ", posicion);
							scanf ("%s", elemento.direccion);
							printf ("Ingresar la edad del empleado que quiere insertar en la posición %d de la lista: ", posicion);
							scanf ("%d", &elemento.edad);
							InsertarPos(posicion, elemento, sec);
							printf ("Empleado %s insertado en la posición %d correctamente. \n", elemento.nombre, posicion);
						}
					}else{
						if ( opcion == 5 ){
							printf ("Opcion nro 5 \n");
							if ( Vacia(sec) ){
								printf ("Se debe inicializar una lista primero (opcion 3) \n");
							}else{
								EliminarC(sec);
								printf ("Cabecera eliminada. \n");
							}
						}else{
							if ( opcion == 6 ){
								printf ("Opcion nro 6 \n");
								if ( Vacia(sec) ){
									printf ("Se debe inicializar una lista primero (opcion 3) \n");
								}else{
									printf ("Ingresar la posición en la que quiere eliminar un elemento: ");
									scanf ("%d", &posicion);
									EliminarPos(posicion, sec);
									printf ("El elemento de la posición %d fue eliminado. \n", posicion);
								}
							}else{
								if ( opcion == 7 ){
									printf ("Opcion nro 7 \n");
									if ( Vacia(sec) ){
										printf ("Se debe inicializar una lista primero (opcion 3) \n");
									}else{
										printf ("...Inicio Accion Mostrar... \n");
										Mostrar(sec);
										printf ("...Fin Accion Mostrar... \n");
									}
								}else{
									if ( opcion == 8 ){
										printf ("Opcion nro 8 \n");
										if ( Vacia(sec) ){
											printf ("Se debe inicializar una lista primero (opcion 3) \n");
										}else{
											VaciarL(sec);
											printf ("Vaciado de lista realizado. \n");
										}
									}else{
										printf ("Opcion nro 9 \n");
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

void InsertarC(struct TDoblete *lista, TEmpleado elem){	// Bien-Hecho con ficticio
	struct TDoblete *aux;
	
	aux = (struct TDoblete *) malloc(sizeof(struct TDoblete));
	aux->next = lista->next;
	aux->info = elem;
	lista->next = aux;
}

void InsertarF(TEmpleado elem, struct TDoblete *q){	// Bien-Hecho con ficticio
	struct TDoblete *aux, *aux2;
	
	aux = q;
	aux->next = q->next;
	
	while ( aux->next != NULL ){
		aux = aux->next;
	}
	
	aux2 = (struct TDoblete *) malloc(sizeof(struct TDoblete));
	aux2->next = NULL;
	aux2->info = elem;
	aux->next = aux2;
}

void Inicializar(struct TDoblete **lista){	// Bien-Hecho con ficticio
	*lista = (struct TDoblete *) malloc(sizeof(struct TDoblete));
	(*lista)->next = NULL;
}

void VaciarL(struct TDoblete *q){	// Revisar
	struct TDoblete *aux;
	
	if ( q != NULL ){
		do{
			aux = q;
			q = q->next;
			free(aux);
		} while ( q != NULL );
	}
}

void InsertarPos(int pos, TEmpleado elem, struct TDoblete *lista){	// Revisar (creo q bien)
	struct TDoblete *aux;
	int i;
	
	i = 0;
	aux = (struct TDoblete *) malloc(sizeof(struct TDoblete));
	aux = lista;
	
	while( aux->next != NULL && i < pos ){
		aux->next = aux->next;
		i++;
	}
	
	aux->info = elem;
}

void EliminarC(struct TDoblete *lista){	// Revisar
	struct TDoblete *aux;
	
	aux = lista;
	lista = lista->next;
	free(aux);
}

void EliminarPos(int pos, struct TDoblete *lista){	// Revisar
	struct TDoblete *aux, *aux2;
	int i;
	
	i=1;
	aux = lista;
	
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
		lista = NULL;
		free(aux);
	}
}

void Mostrar(struct TDoblete *lista){	// Revisar (consigna distinta a la 7)
	lista = lista->next;
	
	if ( lista == NULL ){
		printf ("La lista aún no tiene datos \n");
	}else{
		while ( lista != NULL ){
			printf("Nombre: %s \n", lista->info.nombre);
			printf("Telefono: %s \n", lista->info.telefono);
			printf("Direccion: %s \n", lista->info.direccion);
			printf("Edad: %d \n", lista->info.edad);
			
			lista = lista->next;
		}
	}
}

int Vacia(struct TDoblete *lista){	// Devuelve verdadero si la lista es nil. Si no es nil devuelve falso.
	if ( lista == NULL ){	// <-( lista = nil )
		return 1;
	}else{
		return 0;
	}
}

void DesplegarMenu(){
	printf ("\n");
	printf ("Principio del menú. \n");
	printf ("\n");
	printf ("Poner una opción del 1 al 9.\n");
	printf ("1: InsertarC. 	 \n");
	printf ("2: InsertarF. 	 \n");
	printf ("3: Inicializar. \n");
	printf ("4: InsertarPos. \n");
	printf ("5: EliminarC. 	 \n");
	printf ("6: EliminarPos. \n");
	printf ("7: Mostrar.	 \n");
	printf ("8: VaciarL. 	 \n");
	printf ("9: Salir.	 	 \n");
}
