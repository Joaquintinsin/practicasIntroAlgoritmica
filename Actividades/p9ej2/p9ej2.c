// Funciona. Raro pero funciona. 16/09
	// Funciona correctamente.  17/09

#include <stdio.h>
#include <stdlib.h>

struct TElemCar{
	char info;
	struct TElemCar *next;
};

void CrearPal4(struct TElemCar* *s);

int main( int argc, char **argv ) {
	struct TElemCar *sec, *q, *r, *w, *x, *aux;
	
	sec = NULL;
	CrearPal4(&sec);
	q = sec;
	r = (struct TElemCar *) malloc (sizeof(struct TElemCar));
	r->info = 'C';
	r->next = q;
	q = r;
	w = (struct TElemCar *) malloc (sizeof(struct TElemCar));
	w->info = 'B';
	w->next = q;
	q = w;
	x = (struct TElemCar *) malloc (sizeof(struct TElemCar));
	x->info = 'A';
	x->next = q;
	q = x;
	sec = q;
	
	aux = sec;
	while ( aux != NULL ){
		printf ("(^aux).info vale %c \n", aux->info);
		aux = aux->next;
	}
	
	return 0;
}

void CrearPal4(struct TElemCar* *s){
	struct TElemCar *nuevo, *aux;
	int longitud;
	
	*s = malloc (sizeof(struct TElemCar)); // Obtener(s)
	printf ("letra numero 1: \n");
	scanf("%s", &(*s)->info);
	(*s)->next = NULL;
	
	longitud = 2;
	
	aux = *s;
	
	while ( longitud <= 4 ){
		nuevo = malloc (sizeof(struct TElemCar)); // Obtener(nuevo)
		printf ("letra numero %d: \n",longitud);
		scanf("%s", &nuevo->info);
		nuevo->next = aux->next;
		aux->next = nuevo;
		aux = aux->next;
		longitud++;
		
	}
}
