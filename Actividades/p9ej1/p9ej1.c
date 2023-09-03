8#include <stdio.h>
#include <stdlib.h>

struct TNodo{
	int info;
	struct TNodo *next;
};

int main( int argc, char **argv ) {
	struct TNodo *q, *r, *t, *s, *p, *aux;	// La variable p no se usa, pero forma parte del ejercicio
	
	// Inicio Inciso a)
	q = (struct TNodo *) malloc (sizeof(struct TNodo));	// Obtener(q)
	q->info = 11;
	q->next = NULL;
	r = (struct TNodo *) malloc (sizeof(struct TNodo));	// Obtener(r)
	r->info = 20;
	r->next = NULL;
	q->next = r;
	t = r;
	r = (struct TNodo *) malloc (sizeof(struct TNodo));	// Obtener(r)
	r->info = 25;
	r->next = NULL;
	t->next = r;
	t = r;
	r = (struct TNodo *) malloc (sizeof(struct TNodo));	// Obtener(r)
	r->info = 14;
	r->next = NULL;
	t->next = r;
	
	// Inicio Inciso b)
	r = q;
	r = r->next;
	t = r->next;
	s = (struct TNodo *) malloc (sizeof(struct TNodo));	// Obtener(s)
	s->info = 3;
	s->next = r->next;
	r->next = s;
	p = t;
	t->info = 29;
	printf ("(^t).info vale %d \n", t->info);
	
	// Inicio Inciso c)
	aux = q;
	while ( aux != NULL ){
		printf ("(^aux).info vale %d \n", aux->info);
		aux = aux->next;
	}
	
	return 0;
}

