#include <stdio.h>
#include <stdlib.h>

struct TNodo{
	int info;
	struct TNodo* next;
};

int CantParesCola(struct TNodo *q, int cant);	// Pre: cant = 0 y LSE s/fict
int CantParesAumento(struct TNodo *q);	// LSE s/fict
void CargarLSE(struct TNodo* *q);

int main( int argc, char **argv ) {
	struct TNodo* sec;

	CargarLSE(&sec);
	printf ("Cant Pares Aumento: %d \n", CantParesAumento(sec) );
	printf("Cant Pares Cola: %d \n", CantParesCola(sec, 0) );
	
	return 0;
}

int CantParesCola(struct TNodo *q, int cant){
	if ( q == NULL ){
		return cant;
	}else{
		if ( ( q->info % 2 ) == 0 ){
			cant++;
		}
		return CantParesCola(q->next, cant);
	}
}

int CantParesAumento(struct TNodo *q){	// LSE s/fict
	if ( q == NULL ){
		return 0;
	}else{
		if ( ( q->info % 2 ) == 0 ){
			return 1 + CantParesAumento(q->next);
		}else{
			return CantParesAumento(q->next);
		}
	}
}

void CargarLSE(struct TNodo* *q){
	int opcion, elemento, i;
	struct TNodo* aux;
	struct TNodo* aux2;
	
	printf ("¿Cuántos elementos quiere cargar? ");
	scanf ("%d", &opcion);
	if ( opcion <= 0 ){
		*q = NULL;
	}else{
		if ( opcion >= 1 ){
			(*q) = malloc(sizeof(struct TNodo));
			aux2 = *q;
			printf ("Elemento: ");
			scanf ("%d", &elemento);
			(*q)->info = elemento;
			i = 2;
			
			while ( i <= opcion ){
				aux = malloc(sizeof(struct TNodo));
				printf ("Elemento: ");
				scanf ("%d", &elemento);
				aux->info = elemento;
				aux->next = NULL;
				aux2->next = aux;
				aux2 = aux;
				i++;
			}
		}
	}
}
