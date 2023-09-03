/* 
 * Algoritmo TercerLseOrdenada
 * Funciona parcialmente cuando L1: {1, 2} y L2: {1, 2} porque L3: {1, 1, 2, 2} o L1: {1, 1} y L2: {2, 2} porque L3: {1, 1, 2, 2} o L1: {1, 2} y L2: {2, 3} porque L3: {1, 2, 2, 3}
 * = [ (L1 : {x, y} : (x<=y)) ^ (L2 : {z, w} : ((z=x) v (z=y) v (w=x) v (w=y) v (w=z))) ] --> ( L3 : {x, y, z, w} : (x<=y ^ (z=x) v (z=y) v (w=x) v (w=y) v (w=z)) )
 * En teoría siguen ordenados.
 * El <= se lo cambié por < cuando compara los elementos para evitar justamente eso, pero parece que no es suficiente.
 * 
 * p9ejExt.c
 * 
 */

#include <stdio.h>
#include <stdlib.h>

struct TNodo{
	int info;
	struct TNodo* next;
} TNodo;

void Cargar1(struct TNodo* *l1);
void Cargar2(struct TNodo* *l2);
void Cargar3(struct TNodo* l1, struct TNodo* l2, struct TNodo* *l3);
void MostrarLse(struct TNodo* q);
void MostrarLseFicticio(struct TNodo* q);

int main(int argc, char **argv) {
	struct TNodo* lse1;
	struct TNodo* lse2;
	struct TNodo* lse3;
	
	Cargar1(&lse1);
	MostrarLse(lse1);
	Cargar2(&lse2);
	MostrarLse(lse2);
	Cargar3(lse1, lse2, &lse3);
	MostrarLseFicticio(lse3);
	
	return 0;
}

void Cargar1(struct TNodo* *l1){
	char opcion;
	
	void ContinuarInsertando(struct TNodo* acL1){
		struct TNodo* aux;
		struct TNodo* aux2;
		char opcion;
		
		do{
			printf ("¿Seguir cargando? S/N \n");
			scanf ("%c", &opcion);
			
			if ( opcion != 's' && opcion != 'S'  && opcion != 'n' && opcion != 'N' ){
				while ( opcion != 's' && opcion != 'S'  && opcion != 'n' && opcion != 'N' ){
					printf ("Poner S o s para seguir cargando. Para terminar poner N o n \n");
					scanf ("%s", &opcion);
				}
			}
			
			if ( opcion == 's' || opcion == 'S' ){
				aux = acL1;
				while ( aux->next != NULL ){
					aux = aux->next;
				}
				aux2 = malloc(sizeof(struct TNodo));
				printf ("Insertar elemento: \n");
				scanf ("%d", &aux2->info);
				aux2->next = NULL;
				aux->next = aux2;
			}
		} while ( !( opcion == 'n' || opcion == 'N' ) );
		printf ("Fin de la carga \n");
	}
	
	printf ("Cargar lista 1. Debe ser ordenada \n");
	printf ("¿Cargar? S/N \n");
	do{
		scanf ("%c", &opcion);
		if ( !( opcion == 's' || opcion == 'S'  || opcion == 'n' || opcion == 'N' ) ){
			printf ("Poner S, s, N o n \n");
			scanf ("%s", &opcion);
		}
	} while ( !( opcion == 's' || opcion == 'S'  || opcion == 'n' || opcion == 'N' ) );
	
	if ( opcion == 'S' || opcion == 's' ){
		// Inserta 1 vez sí o sí...
		*l1 = malloc (sizeof(struct TNodo));
		printf ("Insertar elemento (primera posición): \n");
		scanf ("%d", &(*l1)->info);
		(*l1)->next = NULL;
		// Un ciclo que primero pregunta si quiere seguir cargando. Si es afirmativo, lo inserta al final. Cuando no quiere más pone n o N y sale...
		ContinuarInsertando(*l1);
	}else{
		*l1 = NULL;
	}
}

void Cargar2(struct TNodo* *l2){
	char opcion;
	
	void ContinuarInsertando(struct TNodo* acL2){
		struct TNodo* aux;
		struct TNodo* aux2;
		char opcion;
		
		do{
			printf ("¿Seguir cargando? S/N \n");
			scanf ("%c", &opcion);
			
			if ( opcion != 's' && opcion != 'S'  && opcion != 'n' && opcion != 'N' ){
				while ( opcion != 's' && opcion != 'S'  && opcion != 'n' && opcion != 'N' ){
					printf ("Poner S o s para seguir cargando. Para terminar poner N o n \n");
					scanf ("%s", &opcion);
				}
			}
			
			if ( opcion == 's' || opcion == 'S' ){
				aux = acL2;
				while ( aux->next != NULL ){
					aux = aux->next;
				}
				aux2 = malloc(sizeof(struct TNodo));
				printf ("Insertar elemento: \n");
				scanf ("%d", &aux2->info);
				aux2->next = NULL;
				aux->next = aux2;
			}
		} while ( !( opcion == 'n' || opcion == 'N' ) );
		printf ("Fin de la carga \n");
	}
	
	printf ("\nCargar lista 2. Debe ser ordenada \n");
	printf ("¿Cargar? S/N \n");
	do{
		scanf ("%c", &opcion);
		if ( !( opcion == 's' || opcion == 'S'  || opcion == 'n' || opcion == 'N' ) ){
			printf ("Poner S, s, N o n \n");
			scanf ("%s", &opcion);
		}
	} while ( !( opcion == 's' || opcion == 'S'  || opcion == 'n' || opcion == 'N' ) );
	
	if ( opcion == 'S' || opcion == 's' ){
		// Inserta 1 vez sí o sí...
		*l2 = malloc (sizeof(struct TNodo));
		printf ("Insertar elemento (primera posición): \n");
		scanf ("%d", &(*l2)->info);
		(*l2)->next = NULL;
		// Un ciclo que primero pregunta si quiere seguir cargando. Si es afirmativo, lo inserta al final. Cuando no quiere más pone n o N y sale...
		ContinuarInsertando(*l2);
	}else{
		*l2 = NULL;
	}
}

void Cargar3(struct TNodo* l1, struct TNodo* l2, struct TNodo* *l3){
	struct TNodo* q;
	struct TNodo* r;
	struct TNodo* s;
	struct TNodo* t;
	
	*l3 = malloc (sizeof(struct TNodo));
	(*l3)->next = NULL;
	
	if ( l1 == NULL || l2 == NULL ){			// Según
		if ( l1 != NULL && l2 == NULL ){		//		( l1 = nil o l2 = nil): Según
			(*l3)->next = l1;							//										( l1 <> nil y l2 = nil ): (^l3).next <-- l1
		}else{
			if ( l1 == NULL && l2 != NULL ){	//										( l1 = nil y l2 <> nil ): (^l3).next <-- l2
				(*l3)->next = l2;
			}else{											//										Otros: Salida: "Las dos listas están vacías"
				printf ("Las dos listas están vacías \n");
			}
		}														//									Fsegún
	}else{
		q = malloc(sizeof(struct TNodo));
		q->next = NULL;
		if ( l1 != NULL ){
			s = l1;
			while ( s != NULL ){
				t = q;
				while ( t->next != NULL ){
					t = t->next;
				}
				r = malloc(sizeof(struct TNodo));
				r->info = s->info;
				r->next = NULL;
				t->next = r;
				r = NULL;
				s = s->next;
			}
		}
		if ( l2 != NULL ){
			s = l2;
			while ( s != NULL ){
				t = q;
				while ( t->next != NULL ){
					t = t->next;
				}
				r = malloc(sizeof(struct TNodo));
				r->info = s->info;
				r->next = NULL;
				t->next = r;
				r = NULL;
				s = s->next;
			}
		}
		s = q->next;
		t = s;
		do{
			while ( t != NULL ){
				if ( t->info < s->info ){
					r = malloc(sizeof(struct TNodo));
					r->info = s->info;
					s->info = t->info;
					t->info = r->info;
					free(r);
				}
				t = t->next;
			}
			s = s->next;
			t = s;
		} while ( !( t == NULL ) );
		(*l3)->next = q->next;
	}
}

void MostrarLse(struct TNodo* q){
	printf ("Inicio Accion Mostrar LSE Sin Ficticio \n");
	int i;
	
	i = 0;
	
	while ( q != NULL ){
		printf ("Elemento nro %d : %d \n", i, q->info);
		q = q->next;
		i++;
	}
	
	if ( i == 0 ){
		printf ("La lista está vacía \n");
	}
	printf ("Fin Accion Mostrar LSE Sin Ficticio \n");
	printf ("\n");
}

void MostrarLseFicticio(struct TNodo* q){
	printf ("\n");
	printf ("Inicio Accion Mostrar LSE Con Ficticio \n");
	int i;
	
	i = 0;
	q = q->next;
	
	while ( q != NULL ){
		printf ("Elemento nro %d : %d \n", i, q->info);
		q = q->next;
		i++;
	}
	
	if ( i == 0 ){
		printf ("La tercer lista está vacía. \n");	// Debería haber saltado que las dos listas están vacías antes, por el Según de Cargar3. Lo hace correctamente.
		printf ("Por lo tanto la Lista 1 y la Lista 2 también lo están. \n");
	}
	printf ("Fin Accion Mostrar LSE Con Ficticio \n");
}
