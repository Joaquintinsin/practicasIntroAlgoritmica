// Actividad; Implementación del Ejercicio 9 de la práctica 6. AyP 2022; Joaquín Pablo Tissera
#include <stdio.h>
#include <math.h>

typedef struct {	// Defino tipo estructurado TPunto (afuera del int main para que las acciones puedan leerlo correctamente).
	float x;
	float y;
} TPunto;

void CargarCoordenadas(TPunto *che);
void RecibirCirculo(TPunto *che, float *rad);
void Pertenece(TPunto che, TPunto ehc, float rad, int *res);
void MostrarResultado(int res);

int main( int argc, char **argv ) {
	// Léxico
	TPunto coordCirc;
	TPunto puntoProbl;
	float radio;		
	int resultado;	// Booleano del casteo de la accion Pertenece. Almacena 1 si es verdadero, 0 si es falso.

	// Inicio
	CargarCoordenadas(&puntoProbl);
	RecibirCirculo(&coordCirc, &radio);
	Pertenece(coordCirc, puntoProbl, radio, &resultado);
	MostrarResultado(resultado);
	// Fin

	return 0;
}

void CargarCoordenadas(TPunto *che) {	// Acción CargarCoordenadas (resultado che e TPunto)
	printf ("Ingresar la coordenada x de un punto: ");
	scanf ("%f", &(che->x) );
	printf ("Ingresar la coordenada y de un punto: ");
	scanf ("%f", &(che->y) );
}

void RecibirCirculo(TPunto *che, float *rad) { // Acción RecibirCirculo (resultado che e TPunto, rad e R)
	printf ("Ingresar la coordenada x del centro de un círculo: ");
	scanf ("%f", &(che->x) );
	printf ("Ingresar la coordenada y del centro de un círculo: ");
	scanf ("%f", &(che->y) );
	printf ("Ingresar el radio del círculo: ");
	scanf ("%f", rad );
}

void Pertenece(TPunto che, TPunto ehc, float rad, int *res) { // Acción Pertenece (dato che, ehc e TPunto, rad e R, resultado res e Lógico)
	float distRadioAlPunto; // Lexico local
	
	distRadioAlPunto = sqrt( pow( ( ehc.x - che.x ), 2) + pow( ( ehc.y - che.y ), 2) );
	
	if ( rad >= distRadioAlPunto ) {
		*res = 1;
	} else {
		*res = 0;
	}
}

void MostrarResultado(int res) {	// Acción MostrarResultado(dato res e Lógico)
	if (res == 1) {
		printf ("Verdadero; el punto pertenece al circulo \n");
	} else {
		printf ("Falso; el punto no pertenece al circulo \n");
	}
}
