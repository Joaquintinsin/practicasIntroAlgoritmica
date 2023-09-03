#include <stdio.h>

int AuxValAbs(int x);
// inciso a
int Potencia(int n, int e);
// inciso b
int Fibonacci(int n);
// inciso c
int Sumatoria(int n);
// inciso d
int Productoria(int n);

int main( int argc, char **argv ) {
	int opcion;
	printf ("1: Potencia \n");
	printf ("2: Fibonacci \n");
	printf ("3: Sumatoria \n");
	printf ("4: Productoria \n");
	do{
		scanf ("%d", &opcion);
	}while ( opcion < 1 || opcion > 4 );
	
	if ( opcion == 1 ){
		int base, exponente;
		printf ("base (se pasa a natural): ");
		scanf ("%d", &base);
		base = AuxValAbs(base);
		printf ("exponente (se pasa a natural): ");
		scanf ("%d", &exponente);
		exponente = AuxValAbs(exponente);
		
		long int res = Potencia(base, exponente);
		printf ("resultado: %ld \n", res);
	}else{
		if ( opcion == 2 ){
			int nroSucesion;
			printf ("Numero de la sucesion de fibonacci (se pasa a natural): ");
			scanf ("%d", &nroSucesion);
			nroSucesion = AuxValAbs(nroSucesion);
			
			long int res = Fibonacci(nroSucesion);
			printf ("resultado: %ld \n", res);
		}else{
			if ( opcion == 3 ){
				int numero;
				printf ("Numero para la sumatoria (se pasa a natural): ");
				scanf("%d", &numero);
				
				long int res = Sumatoria(numero);
				printf ("resultado: %ld \n", res);
			}else{
				int numero;
				printf ("Numero para la productoria (se pasa a natural): ");
				scanf("%d", &numero);
				
				long int res = Productoria(numero);
				printf ("resultado: %ld \n", res);
			}
		}
	}
	
	return 0;
}

int AuxValAbs(int x){
	if ( x < 0 ){
		return -x;
	}else{
		return x;
	}
}

int Potencia(int n, int e){
	if ( e == 0 ){
		return 1;
	}else{
		if ( e == 1 ){
			return n;
		}else{
			return (n * Potencia(n, e-1) );
		}
	}
}

int Fibonacci(int n){
	if ( n == 0 || n == 1 ){
		return n;
	}else{
		return Fibonacci(n-1) + Fibonacci(n-2);
	}
}

int Sumatoria(int n){
	if ( n == 0 ){
		return n;
	}else{
		return n + Sumatoria(n-1);
	}
}

int Productoria(int n){
	if ( n == 0 ){
		return 1;
	}else{
		if ( n%2 == 0 ){
			return n * Productoria(n-2);
		}else{
			return Productoria(n-1);
		}
	}
}
