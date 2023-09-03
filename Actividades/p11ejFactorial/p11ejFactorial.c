#include <stdio.h>

unsigned long long Factorial(int n);
unsigned long long FactorialC(int n, unsigned long long res);

int main( int argc, char **argv ) {
	int aumentoCola, n;
	unsigned long long result;
	
	printf("Recursion en aumento o en cola? 1/2 \n");
	scanf("%d", &aumentoCola);
	
	if ( aumentoCola == 1 ){
		printf ("En aumento... Poner el número que quiere factorial \n");
		scanf("%d", &n);
		result = Factorial(n);
		printf ("Resultado: %lld \n", result);
	}else{
		if ( aumentoCola == 2 ){
			printf ("En cola... Poner el número que quiere factorial \n");
			scanf("%d", &n);
			result = 1;
			result = FactorialC(n, result);
			printf ("Resultado: %lld \n", result);
		}
	}
	
	return 0;
}

unsigned long long Factorial(int n){
	if ( n == 1 || n == 0 ){
		return 1;
	}else{
		return n * Factorial(n-1);
	}
}

unsigned long long FactorialC(int n, unsigned long long res){
	if ( n == 1 || n == 0 ){
		return res;
	}else{
		return FactorialC(n-1, n * res);
	}
}
