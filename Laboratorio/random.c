#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int r;
int rDiez;
int dado;

int main()
{

	srand(time(0));   // Inicializacion del random, SOLO SE LLAMA UNA VEZ AL COMIENZO

	r = rand();      // Retorna un numero al azar entre 0 y RAND_MAX (constante de sistema)
	rDiez = rand() % 10; //Retorna un numero al azar entre 0 y 9
	dado = rand() % 6 + 1; //Retorna un numero al azar entre 1 y 6 (entre 0 y 5 y le sumo uno)

	printf("El primer numero es %d \nEl segundo numero (del 0 al 9) es: %d \nY el resultado de tirar el dado es: %d\n", r, rDiez, dado);
	return 0;
}
