//No funca

#include <stdio.h>

int Fib(int n);
int FibC(int n);

int main( int argc, char **argv ) {
	int entry;
	scanf("%d", &entry);
	
	printf ("Res Fib %d \n", Fib(entry) );
	printf ("Res Fib Cola %d \n", FibC(entry) );
	
	return 0;
}

int Fib(int n){
	if ( n == 0 || n == 1 ){
		printf ("Fib \n");
		printf ("%d \n", n);
		return n;
	}else{
		printf ("Fib \n");
		printf ("%d \n", Fib(n-1)+Fib(n-2) );
		return Fib(n-1) + Fib(n-2);
	}
}

int FibCAux(int n, int m, int x){
	if ( n == 0 || n == 1 ){
		printf ("Fib Cola \n");
		printf ("%d \n", n);
		return n;
	}else{
		printf ("Fib Cola \n");
		printf ("%d \n", FibCAux(n-1, 0, 1)+FibCAux(n-2, 0, 1) );
		return FibCAux(n-1, x, n) + FibCAux(n-2, x, n);
	}
}

int FibC(int n){
	return FibCAux(n,1,0);
}
