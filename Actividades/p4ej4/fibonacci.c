#include <stdio.h>

int main(){	
	int n;			// Dato entrada, numero especifico de la sucesion de Fibonacci
	int i;				// Auxiliar iterativo
	int ac1, ac2;	// Resultados, acumuladores
	
	printf("Ingrese un número \n");
	scanf("%d",&n);
	
	ac1 = 0;
	ac2 = 1;
	
	// Inicio casos especiales
	if ( n == 0 ){
		printf("Nada");
		return 0;
	}else{
		if ( n == 1 ){
			printf("0");
			return 0;
		}else{
			if ( n == 2 ){
				printf ("0, 1.");
				return 0;
			}else{
				if ( n == 3 ){
					printf ("0, 1, 1.");
					return 0;
				}else{
					if ( n > 2 && n != 3 ){
						printf ("0, 1, ");
					}
				}
			}
		}
	}
	// Fin casos especiales
	
	for ( i=n ; i > 2 ; i--){
		if ( i%2 == 0 ){
			ac1 = ac1 + ac2;
			printf("%d, ", ac1);
		}else{
			ac2 = ac1 + ac2;
			printf("%d, ", ac2);
		}
	}
	
	return 0;
}
