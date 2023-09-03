#include <stdio.h>
#include <string.h>

void Cargar(float *a, float *b, char *f);
void Calcular(float a, float b, char f, float *area);
void Mostrar(float a, float b, char f, float area);

int main(){
	float x, y, sup;	// variables del lexico local, usadas en el algoritmo principal.
	char z;

	Cargar(&x, &y, &z);
	Calcular(x, y, z, &sup);
	Mostrar(x, y, z, sup);
	return 0;
}

void Cargar(float *a, float *b, char *f){
	printf("Ingrese una t si es un triángulo y una r si es un rectángulo. \n");
	do{
		scanf("%s", &(*f));
		if ( *f == 'r' ){
			printf("Ingrese el 1er y 2do lado. \n");
			scanf("%f", &(*a) );
			scanf("%f", &(*b) );
		}else{
			if ( *f == 't' ){
				printf("Ingrese la base del triángulo y la altura del triángulo. \n");
				scanf("%f", &(*a) );
				scanf("%f", &(*b) );
			}
		}
	}while ( *f !='t' && *f !='r' );
}

void Calcular(float a, float b, char f, float *area){
	if ( f == 'r' ){
		*area = a * b;
	}else{
		*area = a * b / 2;
	}
}

void Mostrar(float a, float b, char f, float area){
	char msge[100];
	if ( f == 'r' ){
		strcpy(msge,"El área del rectángulo dado por los lados ");
	}else{
		strcpy(msge,"El área del triángulo dado por la altura y la base ");
	}
	printf("%s %.2f %.2f es %.2f \n", msge, a, b, area);
}
