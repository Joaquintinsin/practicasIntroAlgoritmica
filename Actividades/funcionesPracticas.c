#include <stdio.h>

// Devuelve el argumento incrementado una unidad
int Inc(int x);
// Devuelve el cubo del argumento
long Cubo(int a);
// Devuelve verdadero solo si el argumento es par
int Par(int x);
// Devuelve verdadero si el primer parámetro es múltiplo del segundo parámetro
int Multiplo(int a, int x);
// Devuelve la potencia del primer parámetro elevado al segundo parámetro.
long Potencia(int a, int x);

int main( int argc, char **argv ) {
	int aa, xx;
	
	scanf("%d",&aa);
	scanf("%d",&xx);
	
	printf("potencia: %ld \n", Potencia(aa,xx));
	
	return 0;
}

int Inc(int x){
	return (x + 1);
}

long Cubo(int a){
	return (a*a*a);
}

int Par(int x){
	return ( x%2 == 0 );
}

int Multiplo(int a, int x){
	return ( a%x == 0 );
}

long Potencia(int a, int x){ 
	if ( x <= 0 ) {
		return 1;
	}
	long res = 1;
    while ( x > 0 ) {
        res *= a;
        x--;
    }
    return res;
}
