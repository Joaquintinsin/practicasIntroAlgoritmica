#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int Buscar(char nombreEmpleado[50], struct TDoblete *lista);
void MuestraReg(int posRegistro, struct TDoblete *lista);
void Mostrar(struct TDoblete *lista);
int Vacia(struct TDoblete *lista);
void DesplegarMenu();

int main( int argc, char **argv ) {
	struct TDoblete *sec;
	int opcion;
	int posicion;
	TEmpleado elemento;
	
	sec = NULL;

	Inicializar(&sec);
	printf ("La lista 'sec' fue inicializada. \n");
	
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
			printf ("Ingresar el nombre del empleado a insertar a la cabecera de la lista: ");
			scanf ("%s", elemento.nombre);
			
			printf ("Ingresar el telefono del empleado a insertar a la cabecera de la lista: ");
			scanf ("%s", elemento.telefono);
			
			printf ("Ingresar la direccion del empleado a insertar a la cabecera de la lista: ");
			scanf ("%s", elemento.direccion);
			
			printf ("Ingresar la edad del empleado a insertar a la cabecera de la lista: ");
			scanf ("%d", &elemento.edad);

			printf("El empleado a insertar tiene esta pinta: \n");
			printf("Nombre empleado: %s \n", elemento.nombre);
			printf("Telefono empleado: %s \n", elemento.telefono);
			printf("Direccion empleado: %s \n", elemento.direccion);
			printf("Edad empleado: %d \n", elemento.edad);
			
			InsertarC(sec, elemento);
		}else if ( opcion == 2 ){
			printf ("Opcion nro 2 \n");
			printf ("Ingresar el nombre del empleado a insertar al final de la lista: ");
			scanf ("%s", elemento.nombre);
			
			printf ("Ingresar el telefono del empleado a insertar al final de la lista: ");
			scanf ("%s", elemento.telefono);
			
			printf ("Ingresar la direccion del empleado a insertar al final de la lista: ");
			scanf ("%s", elemento.direccion);
			
			printf ("Ingresar la edad del empleado a insertar al final de la lista: ");
			scanf ("%d", &elemento.edad);

			printf("El empleado a insertar tiene esta pinta: \n");
			printf("Nombre empleado: %s \n", elemento.nombre);
			printf("Telefono empleado: %s \n", elemento.telefono);
			printf("Direccion empleado: %s \n", elemento.direccion);
			printf("Edad empleado: %d \n", elemento.edad);
			
			InsertarF(elemento, sec);
		}else if ( opcion == 3 ){
			printf ("Opcion nro 3 \n");
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
		}else if ( opcion == 4 ){
			printf ("Opcion nro 4 \n");
			if ( Vacia(sec) ){
				printf ("La lista esta vacia\n");
			}else{
				EliminarC(sec);
				printf ("Cabecera eliminada. \n");
			}
		}else if ( opcion == 5 ){
			printf ("Opcion nro 5 \n");
			if ( Vacia(sec) ){
				printf ("La lista esta vacia\n");
			}else{
				printf ("Ingresar la posición en la que quiere eliminar un elemento: ");
				scanf ("%d", &posicion);
				EliminarPos(posicion, sec);
			}
		}else if ( opcion == 6 ){
			printf ("Opcion nro 6 \n");
			if ( Vacia(sec) ){
				printf ("La lista esta vacia\n");
			}else{
				printf ("...Inicio Accion Mostrar... \n");
				Mostrar(sec);
				printf ("...Fin Accion Mostrar... \n");
			}
		}else if ( opcion == 7 ){
			printf ("Opcion nro 7 \n");
			if ( Vacia(sec) ){
				printf ("La lista esta vacia\n");
			}else{
				VaciarL(sec);
				printf ("Vaciado de lista realizado. \n");
			}
		}else if ( opcion == 8 ){
			printf ("Opcion nro 8 \n");
			if ( Vacia(sec) ){
				printf ("La lista esta vacia\n");
			}else{
				printf ("Ingresar el nombre del empleado que quiere buscar en la lista: ");
				scanf ("%s", elemento.nombre);
				int posBuscarEmpleado = Buscar(elemento.nombre, sec);
				if (posBuscarEmpleado != -1) {
					MuestraReg(posBuscarEmpleado, sec);
				} else {
					printf ("No hay empleados con ese nombre en la lista");
				}
			}
		}else{
			printf ("Opcion nro 9 \n");
			printf ("Otros \n");
			printf ("Fin del programa \n");
		}
	} while ( !( opcion >= 9 ) );

	return 0;
}

void Inicializar(struct TDoblete **lista){
	if (*lista == NULL){
		*lista = (struct TDoblete *) malloc(sizeof(struct TDoblete));
		(*lista)->next = NULL;
	} else {
		printf("Ya existe una lista \n");
	}
}

void InsertarC(struct TDoblete *lista, TEmpleado elem){
	struct TDoblete *aux;
	
	aux = (struct TDoblete *) malloc(sizeof(struct TDoblete));
	aux->next = lista->next;
	aux->info = elem;
	lista->next = aux;
}

void InsertarF(TEmpleado elem, struct TDoblete *q){
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

void VaciarL(struct TDoblete *q){
	struct TDoblete *aux;

	while (q->next != NULL) {
		aux = q->next;
		q->next = aux->next;
		free(aux);
	}
}

void InsertarPos(int pos, TEmpleado elem, struct TDoblete *lista){
	struct TDoblete *aux;
	int i;
	
	i = 0;
	aux = lista;
	
	while( aux->next != NULL && i < pos ){
		aux = aux->next;
		i++;
	}

	if (i == pos) {
		struct TDoblete *nuevoNodo = (struct TDoblete *) malloc(sizeof(struct TDoblete));
		nuevoNodo->info = elem;
		nuevoNodo->next = aux->next;
		aux->next = nuevoNodo;
		printf ("Empleado %s insertado en la posición %d correctamente. \n", elem.nombre, pos);
	} else {
		printf("\n !!! \n Posicion %d fuera de los limites \n !!! \n", pos);
	}
}

void EliminarC(struct TDoblete *lista){
	struct TDoblete *aux;
	
	aux = lista->next;
	lista->next = aux->next;
	free(aux);
}

void EliminarPos(int pos, struct TDoblete *lista){
	struct TDoblete *aux, *aux2;
	int i;
	
	i=1;
	aux = lista;
	
	while( i < pos && aux->next != NULL ){
		aux = aux->next;
		i++;
	}
	
	if ( aux->next != NULL ){
		aux2 = aux->next;
		aux->next = aux2->next;
		free(aux2);
		printf ("El elemento de la posición %d fue eliminado. \n", pos);
	}else{
		printf("\n !!! \n Posicion %d fuera de los limites \n !!! \n", pos);
	}
}

int Buscar(char nombreEmpleado[50], struct TDoblete *lista) {
	int pos = 0;
	lista = lista->next;

	if (lista == NULL) {
		printf ("La lista aún no tiene datos \n");
	} else {
		while (lista != NULL) {
			pos++;
			if (strcmp(lista->info.nombre, nombreEmpleado) == 0) {
				return pos;
			}
			lista = lista->next;
		}
	}
	return -1;
}

void MuestraReg(int posRegistro, struct TDoblete *lista) {
	int i = 0;
	while (lista != NULL && i < posRegistro) {
		lista = lista->next;
		i++;
	}
	printf("Empleado encontrado. Mostrando datos \n");
	printf("Nombre: %s \n", lista->info.nombre);
	printf("Telefono: %s \n", lista->info.telefono);
	printf("Direccion: %s \n", lista->info.direccion);
	printf("Edad: %d \n", lista->info.edad);
}

void Mostrar(struct TDoblete *lista){
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
	lista = lista->next;

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
	printf ("3: InsertarPos. \n");
	printf ("4: EliminarC. 	 \n");
	printf ("5: EliminarPos. \n");
	printf ("6: Mostrar.	 \n");
	printf ("7: VaciarL. 	 \n");
	printf ("8: MostrarReg.	 \n");
	printf ("9: Salir.	 	 \n");
}
