#include <stdio.h>

int main( int argc, char **argv ) {
	char car;
	
	printf ("Ingrese el caracter que quiere saber que numero vale en ASCII: ");
	car = getchar();
	// scanf ("%[^\n]", &car);
	printf ("El valor del caracter %c en ASCII es %d \n", car, car);
	
	return 0;
}

