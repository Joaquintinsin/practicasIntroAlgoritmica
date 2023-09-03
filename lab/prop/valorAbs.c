#include <stdio.h>

int main() {
    int x;
    int y;

	printf("Ingrese un nro. \n");
	scanf("%d", &x);
	
	y = x;
	
	if ( x <= 0 ) {
		x = -x;
		printf("El módulo de %d es %d", y, x);
	}else{
		printf("El módulo de %d es %d", y, x);
	}
        
    return 0;
}
