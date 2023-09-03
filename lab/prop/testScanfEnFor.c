#include <stdio.h>

void TestScanfEnFor();

int main( int argc, char **argv ) {
	
	TestScanfEnFor();
	
	return 0;
}

// Acción que modela un para en donde el paso es una entrada de una variable.
void TestScanfEnFor(){
	int n;
	scanf("%d", &n);
	for (int i = 0 ; i != n ; scanf("%d", &n) )
		printf("Se pudo. i = %d , n = %d \n", i, n);
	printf ("Arafue \n");
}
