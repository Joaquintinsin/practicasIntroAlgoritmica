#include <stdio.h>
#include "arithmetic_2019.h" // no va entre < > sino que va entre " " porque es una biblioteca nueva

int main() {
	int q = 0;
	
	printf( "is %i prime? %i\n", 13, is_prime( 13 ) );
	printf( "is %i prime? %i\n", 12, is_prime( 12 ) );
	
	printf( "%i! = %i\n", 0, factorial( 0 ) );
	printf( "%i! = %i\n", 7, factorial( 7 ) );
	
	printf( "%i (remainder) + %i (divisor) * %i (quotient) = %i (dividend)\n", division( 17, 3, &q), 3, q, 17 );
	printf( "%i (remainder) + %i (divisor) * %i (quotient) = %i (dividend)\n", division( 12, 4, &q), 4, q, 12 );

	return 0;
}
