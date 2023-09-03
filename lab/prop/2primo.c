#include <stdio.h>
#include <math.h>

int main(){
	int num;
	int resRaiz;
	int i;
	int primo;

	do{
		printf ("Ingrese un numero entero positivo y te diré si es primo o no. \n");
		scanf ("%d",&num);
	}while ( num <= 0 );
	
	i = 2;
	resRaiz = sqrt(num);
	
	if ( num == 1 || num == 2 || num == 3 ){
		primo = 1;
	}else{
		if ( ( num%2 ) == 0 ){
			primo = 0;
		}else{
			primo = 1;
			while ( i <= resRaiz && primo){
				if ( ( num%i ) != 0 ){
					primo = 1;
				}else{
					primo = 0;
				}
				i = i + 1;
			}
		}
	}
	
	if (primo){
		printf("Es un número primo. \n");
	}else{
		printf("No es un número primo. \n");
	}

	return 0;
}

