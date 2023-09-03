#include <stdio.h>

int main( int argc, char **argv ) {
	int cotaSup;		// cantidad de iteraciones del para
	int i;					// variable de control del para
	int s;				// sumatoria
	
	scanf("%d", &cotaSup);
	
	s = 0;
	i = 0;

	while ( i <= cotaSup ) {
		s = s + i;
		i = i + 1;
	}

		/* Hecho con for:
		for ( i = 0; i <= cotaSup; i++){
			s = s + i;
		}
		*/
	
	printf("La suma de los %d primeros numeros naturales es %d \n", cotaSup, s);
	
	return 0;
}

