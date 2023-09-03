/* Algoritmo EnfrentarL1yL2
 * 
 * Funciona incorrectamente: Voltea la primer lista bien, la inserta bien, pero con la 2da lista
 * ya no la inserta de manera correcta. Parece que luego de la primera lista la segunda quedó
 * dando vueltas por algún lado, aunque las acciones son las mismas que insertar la primera...
 * 17/09: 
 * Corregidas Cargar1 y Cargar2; cambie %c por %s
 * Corregida MostrarLdeFicticio; la condicion de iteración es != u, del ultimo ficticio
 * Agregados printf en el main mostrando qué lista muestra
 * Funciona parcialmente. Con listas de distintos tamaños no corre el programa...
 * 
 */

#include <stdio.h>
#include <stdlib.h>

struct TSimple{
	int info; // Supongo info e Z. Cambiarlo según lo que haga falta. Revisar los %d si se cambia.
	struct TSimple* next;
} TSimple;

struct TNodo{
	int info; // Supongo info e Z. Cambiarlo según lo que haga falta. Revisar los %d si se cambia.
	struct TNodo* next;
	struct TNodo* back;
} TNodo;

void Cargar1(struct TSimple* *l1);
void Cargar2(struct TSimple* *l2);
struct TSimple* VoltearL1(struct TSimple* l1);
void MostrarLse(struct TSimple* q);
void MostrarLdeFicticio(struct TNodo* q, struct TNodo* u);

int main( int argc, char **argv ) {
	struct TSimple* lse1;
	struct TSimple* lse2;
	struct TSimple* l1volt;
	struct TSimple* aux;
	struct TNodo* puntIni;
	struct TNodo* puntFin;
	struct TNodo* aux2;
	
	Cargar1(&lse1);
	printf ("Lse1: \n");
	MostrarLse(lse1);
	
	Cargar2(&lse2);
	printf ("Lse2: \n");
	MostrarLse(lse2);
	
	l1volt = VoltearL1(lse1);
	printf ("L1 volteada: \n");
	MostrarLse(l1volt);
	
	puntIni = malloc(sizeof(struct TNodo));
	puntFin = malloc(sizeof(struct TNodo));
	puntIni->next = puntFin;
	puntFin->next = NULL;
	puntIni->back = NULL;
	puntFin->back = puntIni;
	aux = l1volt;
	
	while ( aux != NULL ){
		aux2 = malloc(sizeof(struct TNodo));
		aux2->info = aux->info;
		aux2->next = puntFin;
		aux2->back = (aux2->next)->back;
		puntFin->back = aux2;
		(aux2->back)->next = aux2;
		aux = aux->next;
		aux2 = NULL;
	}	// Primer lista puesta como triplete
	
	aux = lse2;
	
	while ( aux != NULL ){
		aux2 = malloc(sizeof(struct TNodo));
		aux2->info = aux->info;
		aux2->next = puntFin;
		aux2->back = (aux2->next)->back;
		puntFin->back = aux2;
		(aux2->back)->next = aux2;
		aux = aux->next;
		aux2 = NULL;
	}
	
	MostrarLdeFicticio(puntIni, puntFin);
	
	return 0;
}

void Cargar1(struct TSimple* *l1){
	char opcion;
	
	void ContinuarInsertando(struct TSimple* acL1){
		struct TSimple* aux;
		struct TSimple* aux2;
		char opcion;
		
		do{
			printf ("¿Seguir cargando? S/N \n");
			scanf ("%s", &opcion);
			
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
				aux2 = malloc(sizeof(struct TSimple));
				printf ("Insertar elemento: \n");
				scanf ("%d", &aux2->info);
				aux2->next = NULL;
				aux->next = aux2;
			}
		} while ( !( opcion == 'n' || opcion == 'N' ) );
		printf ("Fin de la carga \n");
	}
	
	printf ("Cargar lista 1. \n");
	printf ("¿Cargar? S/N \n");
	do{
		scanf ("%s", &opcion);
		if ( !( opcion == 's' || opcion == 'S'  || opcion == 'n' || opcion == 'N' ) ){
			printf ("Poner S, s, N o n \n");
			scanf ("%s", &opcion);
		}
	} while ( !( opcion == 's' || opcion == 'S'  || opcion == 'n' || opcion == 'N' ) );
	
	if ( opcion == 'S' || opcion == 's' ){
		// Inserta 1 vez sí o sí...
		*l1 = malloc (sizeof(struct TSimple));
		printf ("Insertar elemento (primera posición): \n");
		scanf ("%d", &(*l1)->info);
		(*l1)->next = NULL;
		// Un ciclo que primero pregunta si quiere seguir cargando. Si es afirmativo, lo inserta al final. Cuando no quiere más pone n o N y sale...
		ContinuarInsertando(*l1);
	}else{
		*l1 = NULL;
	}
}

void Cargar2(struct TSimple* *l2){
	char opcion;
	
	void ContinuarInsertando(struct TSimple* acL2){
		struct TSimple* aux;
		struct TSimple* aux2;
		char opcion;
		
		do{
			printf ("¿Seguir cargando? S/N \n");
			scanf ("%s", &opcion);
			
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
				aux2 = malloc(sizeof(struct TSimple));
				printf ("Insertar elemento: \n");
				scanf ("%d", &aux2->info);
				aux2->next = NULL;
				aux->next = aux2;
			}
		} while ( !( opcion == 'n' || opcion == 'N' ) );
		printf ("Fin de la carga \n");
	}
	
	printf ("\nCargar lista 2. \n");
	printf ("¿Cargar? S/N \n");
	do{
		scanf ("%s", &opcion);
		if ( !( opcion == 's' || opcion == 'S'  || opcion == 'n' || opcion == 'N' ) ){
			printf ("Poner S, s, N o n \n");
			scanf ("%s", &opcion);
		}
	} while ( !( opcion == 's' || opcion == 'S'  || opcion == 'n' || opcion == 'N' ) );
	
	if ( opcion == 'S' || opcion == 's' ){
		// Inserta 1 vez sí o sí...
		*l2 = malloc (sizeof(struct TSimple));
		printf ("Insertar elemento (primera posición): \n");
		scanf ("%d", &(*l2)->info);
		(*l2)->next = NULL;
		// Un ciclo que primero pregunta si quiere seguir cargando. Si es afirmativo, lo inserta al final. Cuando no quiere más pone n o N y sale...
		ContinuarInsertando(*l2);
	}else{
		*l2 = NULL;
	}
}

struct TSimple* VoltearL1(struct TSimple* l1){
	struct TSimple* q;
	struct TSimple* t;
	struct TSimple* s;
	
	q = l1;
	if ( q != NULL ){
		while ( q->next != NULL ){
			q = q->next;
		}
		t = q;
		s = l1;
		do{
			while ( s->next != q ){
				s = s->next;
			}
			q->next = s;
			q = l1;
			while( q->next != s ){
				q = q->next;
			}
			s->next = q;
			s = l1;
		} while ( !( s == l1 && q == l1 ) );
		q->next = NULL;
		return t;
	}else{
		return q;
	}
}

void MostrarLse(struct TSimple* q){
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

void MostrarLdeFicticio(struct TNodo* q, struct TNodo* u){
	printf ("\n");
	printf ("Inicio Accion Mostrar LDE Con Ficticio \n");
	int i;
	
	i = 0;
	q = q->next;
	
	while ( q != u ){
		printf ("Elemento nro %d : %d \n", i, q->info);
		q = q->next;
		i++;
	}
	
	if ( i == 0 ){
		printf ("La tercer lista está vacía. \n");
		printf ("Por lo tanto la Lista 1 y la Lista 2 también lo están. \n");
	}
	printf ("Fin Accion Mostrar LDE Con Ficticio \n");
}
