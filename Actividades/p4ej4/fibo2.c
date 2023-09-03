#include <stdio.h>

int main() {
    int n, fibn0, fibn1, i, aux;
    printf("Ingrese su numero\n");
    scanf("%d", &n);
    
    fibn0 = 1;
    fibn1 = 1;

    aux = 0;

    i = 2;
	
    for(i=1; i <= n; i++){
    aux = fibn1;
    fibn1 = fibn1 + fibn0;
    fibn0 = aux;
    printf("Fib(%d) = %d\n", n, fibn1);
    }
    return 0;
}
