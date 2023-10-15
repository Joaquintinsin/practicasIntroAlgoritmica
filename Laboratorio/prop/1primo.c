#include <stdio.h>
#include <string.h>

int entry;
int aux;
int i;
char respuesta[50];

int main(){
	do{
		printf ("Ingrese un numero entero positivo y te diré si es primo o no. \n");
		scanf ("%d",&entry);
	}while (entry<=0);
	
	for ( i=0;i<=entry;i++ ){
		if ( entry == 1 || entry == 2 ){
			aux = 1;
		}else{
			if ( ( /*entry%entry )==0 &&*/ i != 0 ) ){
				if ( ( entry%2 )==0 ){
					aux = 2;
				}else{
					if ( ( entry%2 )!=0 && entry != i && i !=1 && ( entry%i )==0 ){
						aux = 2;
					}else{
						aux = 1;
					}
				}
			}
		}
	}
	
	if( aux == 2 ){
		printf ("El número %d no es un número primo. \n", entry);
	}else{
		printf ("El número %d es efectivamente un numero primo. \n", entry);
	}
	return 0;
}

