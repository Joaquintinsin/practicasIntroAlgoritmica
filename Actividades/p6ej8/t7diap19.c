// Se desea poder almacenar 7 notas de un estudiante e informarlas.
// Ejemplo GestionarNotas, diapositiva 19 de la práctica 7 (arreglos unidimensionales).
#include <stdio.h>

#define NMax 7
int notas[NMax];
int i;
	
int main( int argc, char **argv ) {
	i = 1;
	while ( i <= NMax ){
		printf ("Ingrese la nota %d del alumno: ", i);
		scanf ("%d", &notas[i] );
		i++;
	}
	
	i = 1;
	while ( i <= NMax ){
		// printf ("%d", notas[i] );
		printf ("La nota nro %d del alumno es %d \n", i, notas[i] );
		i++;
	}
	
	return 0;
}

