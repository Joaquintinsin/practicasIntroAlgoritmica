#include <stdio.h>

#define NMax 7
int notas[NMax];	// definicion clasica
int n;
int i;

int main( int argc, char **argv ) {
	i = 0;
	while ( i < NMax ){
		scanf ("%d", &n);
		notas[i] = n;
		i++;
	}
	return 0;
}

