// Edit 24/09: Funciona correctamente

#include <stdio.h>
#include <stdlib.h>

typedef struct TLluvia{
	char localidad[50];
	float lluviaAnual;
	int lluviaMinima;	//Z+
	float lluviaMaxima;
}TLluvia;

struct TElem{
	TLluvia info;
	struct TElem* next;
};

void Cargar1(struct TElem* *l1);
int CantLoc(struct TElem* q);

int main( int argc, char **argv ) {
	struct TElem* cab;
	struct TElem* aux;
	int cantLoc;
	float sumAnual, promedioLluvia;
	
	Cargar1(&cab);
	
	if ( cab != NULL ){
		aux = cab;
		cantLoc = CantLoc(cab);
			// printf("cant loc = %d \n", cantLoc);
		sumAnual = 0;
		promedioLluvia = 0;
		
		while ( aux != NULL ){
			sumAnual = aux->info.lluviaAnual + sumAnual;
			aux = aux->next;
		}
			// printf("sum anual = %f \n", sumAnual);
		if ( cantLoc != 0 ){
			promedioLluvia = sumAnual / cantLoc;
			printf("Promedio total de lluvias entre todas las localidades: %f \n", promedioLluvia);
			aux = cab;
		
			while ( aux != NULL ){
				if ( aux->info.lluviaMinima < promedioLluvia ){
					printf ("La localidad %s tiene una lluvia menor al promedio total \n", aux->info.localidad);
				}
				aux = aux->next;
			}
		
		}else{
			printf("No hay localidades \n");
		}
	}else{
		printf ("No se cargó la lista \n");
	}
	return 0;
}

void Cargar1(struct TElem* *l1){
	char opcion;
	
	void ContinuarInsertando(struct TElem* acL1){
		struct TElem* aux;
		struct TElem* aux2;
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
				aux2 = malloc(sizeof(struct TElem));
				
				printf ("Insertar localidad: \n");
				scanf ("%s", aux2->info.localidad);
				
				printf ("Insertar lluvia anual: \n");
				scanf ("%f", &aux2->info.lluviaAnual);
				
				printf ("Insertar lluvia mínima (entero positivo): \n");
				scanf ("%d", &aux2->info.lluviaMinima);
				
				printf ("Insertar lluvia máxima: \n");
				scanf ("%f", &aux2->info.lluviaMaxima);
				
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
		*l1 = malloc (sizeof(struct TElem));
		printf ("Insertar elemento (primera posición): \n");
		
		printf ("Insertar localidad: \n");
		scanf ("%s", (*l1)->info.localidad);
		
		printf ("Insertar lluvia anual: \n");
		scanf ("%f", &(*l1)->info.lluviaAnual);
		
		printf ("Insertar lluvia mínima (entero positivo): \n");
		scanf ("%d", &(*l1)->info.lluviaMinima);
		
		printf ("Insertar lluvia máxima: \n");
		scanf ("%f", &(*l1)->info.lluviaMaxima);
		
		(*l1)->next = NULL;
		// Un ciclo que primero pregunta si quiere seguir cargando. Si es afirmativo, lo inserta al final. Cuando no quiere más pone n o N y sale...
		ContinuarInsertando(*l1);
	}else{
		*l1 = NULL;
	}
}

int CantLoc(struct TElem* q){
	int i;
	struct TElem* s;
	
	s = q;
	i = 0;
	while ( s != NULL ){
		i++;
		s = s->next;
	}
	return i;
}
