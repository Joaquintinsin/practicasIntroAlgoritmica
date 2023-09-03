#include <stdio.h>
int x, n;

int main() 	{
	   printf("Ingrese un número: \n");
	   scanf("%d", &x); 

	   if(x < 0) {
	     n = -x;
	     printf("El valor absoluto de %d es %d. \n", x, n);
	   }else{	
	     printf("El valor absoluto de %d es %d. \n", x, x);
	   }

	   return 0;
	}
