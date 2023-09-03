#include <stdio.h>
#include <stdlib.h>

struct TNodo{
	int info;
	struct TNodo* next;
	struct TNodo* back;
};

void InicializarLDEFicticio(struct TNodo* *puntIni, struct TNodo* *puntFin);
void EstadoInicial(struct TNodo* puntIni, struct TNodo* puntFin);
void MostrarLdeSinFicticio(struct TNodo* q);

int main( int argc, char **argv ) {
	struct TNodo* q;
	struct TNodo* u;
	struct TNodo* s;
	struct TNodo* r;
	struct TNodo* t;
	
	InicializarLDEFicticio(&q, &u);
	EstadoInicial(q, u);
	
	MostrarLdeSinFicticio(q);
	
	s = q;
	s = s->next;
	r = malloc (sizeof(struct TNodo));
	t = malloc (sizeof(struct TNodo));
	r->info = 8;
	r->back = s;
	r->next = s->next;
	s->next->back = r;
	s->next = r;
	s = s->next;
	t->info = 12;
	t->back = s;
	t->next = s->next;
	s->next->back = t;
	s->next = t;
	
	MostrarLdeSinFicticio(q);
	
	return 0;
}

void InicializarLDEFicticio(struct TNodo* *puntIni, struct TNodo* *puntFin){
	*puntIni = malloc(sizeof(struct TNodo));
	*puntFin = malloc(sizeof(struct TNodo));
	(*puntIni)->next = *puntFin;
	(*puntFin)->next = NULL;
	(*puntIni)->back = NULL;
	(*puntFin)->back = *puntIni;
}

void EstadoInicial(struct TNodo* puntIni, struct TNodo* puntFin){
	struct TNodo* aux;
	
	puntIni->info = 7;
	
	aux = malloc(sizeof(struct TNodo));
	aux->info = 1;
	aux->next = puntFin;
	aux->back = puntIni;
	puntIni->next = aux;	// Va en la tercer posición: entre 7 y 20
	puntFin->back = aux;
	
	aux = malloc(sizeof(struct TNodo));
	aux->info = 20;
	aux->next = puntFin;
	aux->back = puntIni->next;
	puntIni->next->next = aux;	// Va en la tercer posición: entre 1 y 5
	puntFin->back = aux;
	
	puntFin->info = 5;
}

void MostrarLdeSinFicticio(struct TNodo* q){
	printf ("\n");
	printf ("Inicio Accion Mostrar LDE Sin Ficticio \n");
	int i;
	
	i = 0;
	
	while ( q != NULL ){
		printf ("Elemento nro %d : %d \n", i, q->info);
		q = q->next;
		i++;
	}
	
	if ( i == 0 ){
		printf ("La lista está vacía. \n");
	}
	printf ("Fin Accion Mostrar LDE Sin Ficticio \n");
}
