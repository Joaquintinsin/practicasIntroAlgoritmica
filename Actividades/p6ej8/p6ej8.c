#include <stdio.h>

typedef struct{
	float x,y;
} TPunto;

typedef struct{
	float a,b;
} TRecta;

void CargarCoordenadas(TPunto *che);
void CargarCoeficientes(TRecta *recta);
void EstaEnLaRecta(TRecta recta, TPunto punto, int *res);

int main( int argc, char **argv ) {
	TPunto coord;
	TRecta coeficientes;
	int pertenece;
	
	CargarCoordenadas(&coord);
	CargarCoeficientes(&coeficientes);
	EstaEnLaRecta(coeficientes, coord, &pertenece);
	
	if (pertenece == 1){
		printf ("<El punto pertenece a la recta> \n");
	}else{
		printf ("		>El punto no está en la recta< \n");
	}
	
	return 0;
}

void CargarCoordenadas(TPunto *che){
	printf("Introduzca los puntos coordenados, primero el x luego el y \n");
	scanf("%f", &(che->x) );
	scanf("%f", &(che->y) );
}

void CargarCoeficientes(TRecta *recta){
	printf("Introduzca los puntos de una recta, primero el a luego el b \n");
	scanf("%f", &(recta->a) );
	scanf("%f", &(recta->b) );
}

void EstaEnLaRecta(TRecta recta, TPunto punto, int *res){
	if (recta.a * punto.x + recta.b == punto.y){
		*res = 1;
	}else{
		*res = 0;
	}
}

