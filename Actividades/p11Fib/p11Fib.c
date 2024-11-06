#include <stdio.h>

int Fib(int n);
int FibC(int n);

int main( int argc, char **argv ) {
	int entry;
	scanf("%d", &entry);
	
	printf ("Res Fib Cola %d \n", FibC(entry) );
	printf ("Res Fib %d \n", Fib(entry) );
	
	return 0;
}

int Fib(int n){
	if ( n == 0 || n == 1 ){
		return n;
	}else{
		return Fib(n-1) + Fib(n-2);
	}
}

int FibCAux(int n, int a, int b) {
	if (n == 0) {
		return a;
	} else if (n == 1) {
		return b;
	} else {
		return FibCAux(n - 1, b, a + b);
	}
}

int FibC(int n){
	return FibCAux(n,0,1);
}
