#include "arithmetic_2019.h" // Incluye la interfaz a implementar

// seccion de Implementacion (declaraciones privadas)
// a continuacion se implementan las funciones que podrán ser utilizadas desde los programas que incluyan a la biblioteca arithmetic
// también pueden agregarse otras funtion auxiliares, las cuales no serán vistas ni podrán ser utilizadas por otros programas
int is_prime( int n ) {
	int result = 1;
	
	for ( int i = 2; i < n; i++ ) {
		if ( !(n % i) ) {
			result = 0;
			break;
		}
	};

	return result;
}

int division( int dividend, int divisor, int * quotient ) {
	int remainder;
	
	remainder = dividend;
	*quotient  = 0;
	
	while ( remainder >= divisor ) {
		remainder -= divisor;
		(*quotient)++;
	}

	return remainder;
}

int factorial( int n ) {
	int result  = 1;
	
	if ( !n ) {
		return result;
	}

	do {
		result *= n--;
	} while ( n > 0 );

	return result;
}
