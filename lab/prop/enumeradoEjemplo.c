/* 
 * No funciona directamente. No delimita que el scaneo por teclado sea solamente rojo (o 1)
 * ni azul ni verde etc... La idea de presentar el tipo enumerado se refleja correctamente (creo)
 * también se puede hacer enum NombreTipo { cosa1, cosa2, etc };
 * pero cuando se tenga que usar una variable por ejemplo como parametro, se debe poner enum antes que
 * el nombre del tipo, por ej; enum NombreTipo variable < 1; y se arrastra el enum espacio nombre...
 * entonces queda más engorroso...
*/
#include <stdio.h>

typedef enum { Rojo, Azul, Verde, Amarillo } TColor;
// typedef enum { Rojo = 1, Azul = 2, Verde = 3, Amarillo = 4 } TColor;

int main( int argc, char **argv ) {
	TColor color;
	char res[10];
	scanf ("%s", &color);
	for (int i = 1; i <= 10; i++){
		res[i] = color;
	}
	printf ("color es: %s \n", &color);
	printf ("res es: %s \n", &res);
	
	return 0;
}

