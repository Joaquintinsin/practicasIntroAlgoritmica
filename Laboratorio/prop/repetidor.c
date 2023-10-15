#include <stdio.h>
#include <string.h>

int main() {
	char respuesta = 'n';
	do{
		printf ("Ingresar N o n si quiere salir. \n");
		scanf ("%s", &respuesta);
		while (getchar() != '\n');	
		// funcion que captura el caracter vacio. evita que el espacio sea otro scanf
	} while (! ( ( respuesta=='N' ) || ( respuesta=='n' ) ) ); // cualquir letra q no sea n repite
	printf ("Terminando. Nos vemos =) \n");
	
	return 0;
}

