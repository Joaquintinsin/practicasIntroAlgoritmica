#include <stdio.h>

int a, b;
int PonerEn34();

int main( int argc, char **argv ) {
	do{
		printf ("Poner un valor entero a la variable 'a' distinto de 34: ");
		scanf("%d", &a);
	} while ( a == 34 );
	printf ("Valor de la variable 'a' antes de la invocacion: %d \n", a);
	b = PonerEn34();
	printf ("Valor de la variable 'a' desps de la invocacion: %d \n", a);
	printf ("Valor de la variable 'b': %d \n", b);
	
	return 0;
}

int PonerEn34(){
	a = 34;
	return a;
}
