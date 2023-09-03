#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TCadena{
	char cadena[50];
} TCadena;

typedef struct TNodo{
	TCadena info;
	struct TNodo* next;
	struct TNodo* back;
} TNodo;

void EstadoInicial(TNodo* *q, TNodo* *u);	// Crea la lista que el enunciado propone como estado inicial
void InsertarSegunda(TNodo* q, TCadena elem, TNodo* *a);
void ModificarTercer(TNodo* q, TCadena elem, TNodo* *a);
void EliminarUltimo(TNodo* *u);
void MostrarLista(TNodo* q);

int main( int argc, char **argv ) {
	TNodo *r, *t, *s, *p;
	TCadena elIns;
	
	EstadoInicial(&r,&p);	// Carga la lista como lo dice el enunciado
	printf ("Inicio lista nro 1 \n");
 	MostrarLista(r);
	printf ("Fin lista nro 1 \n");
//	printf ("Ingresar la cadena a insertar en la 2da pos \n");
	strcpy(elIns.cadena, "Tito");	// scanf ("%s", elIns.cadena);
	InsertarSegunda(r, elIns, &t);
	printf ("Inicio lista nro 2 \n");
 	MostrarLista(r);
	printf ("Fin lista nro 2 \n");
//	printf ("Ingresar la cadena para modificar el tercer nodo \n");
	strcpy(elIns.cadena, "estás?");	// scanf ("%s", elIns.cadena);
	ModificarTercer(r, elIns, &s);
	printf ("Inicio lista nro 3 \n");
 	MostrarLista(r);
	printf ("Fin lista nro 3 \n");
	EliminarUltimo(&p);
	printf ("Inicio lista nro 4 \n");
	MostrarLista(r);
	printf ("Fin lista nro 4 \n");
	
	return 0;
}

void EstadoInicial(TNodo* *q, TNodo* *u){	// Crea la lista que el enunciado propone como estado inicial
	TNodo* aux;
	
	*q = NULL;
	*u = NULL;
	aux = malloc(sizeof(TNodo));
	strcpy(aux->info.cadena, "Hola");
	aux->back = NULL;
	aux->next = NULL;
	*q = aux;
	*u = aux;
	aux = malloc(sizeof(TNodo));
	strcpy(aux->info.cadena, "cómo");
	aux->back = *u;
	aux->next = NULL;
	(*u)->next = aux;
	*u = aux;
	aux = malloc(sizeof(TNodo));
	strcpy(aux->info.cadena, "te");
	aux->back = *u;
	aux->next = NULL;
	(*u)->next = aux;
	*u = aux;
	aux = malloc(sizeof(TNodo));
	strcpy(aux->info.cadena, "va?");
	aux->back = *u;
	aux->next = NULL;
	(*u)->next = aux;
	*u = aux;
}

void InsertarSegunda(TNodo* q, TCadena elem, TNodo* *a){
	TNodo* aux;
	*a = malloc (sizeof(TNodo));
	(*a)->info = elem;
	(*a)->next = q->next;
	(*a)->back = q;
	q->next = *a;
	aux = (*a)->next;
	aux->back = *a;
}

void ModificarTercer(TNodo* q, TCadena elem, TNodo* *a){
	TNodo *aux1;
	TNodo *aux2;
	aux1 = q->next;
	aux2 = aux1->next;
	*a = aux2->next;
	(*a)->info = elem;
}

void EliminarUltimo(TNodo* *u){
	TNodo* s;
	
	s = *u;
	*u = (*u)->back;
	(*u)->next = NULL;
	free(s);
}

void MostrarLista(TNodo* q){
	while ( q != NULL ){
		printf ("%s \n", q->info.cadena);
		q = q->next;
	}
}
