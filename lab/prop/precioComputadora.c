// se puede plantear con un si entonces sino, si se quiere mostrar solo la que vale menos
#include <stdio.h>

float precio1,precio2;			// Dato de entrada de alguna de las tiendas
float costeEnvio1,costeEnvio2;	// Auxiliar; almacena el coste de envio de los precios
float pFinal1,pFinal2;			// Resultados de los precios finales

int main(){
	do{
	printf("En la tienda oficial la computadora cuesta: \n");
	scanf("%f",&precio1);
	}while (!(precio1>0));
	
	do{
	printf("En otra página la computadora cuesta: \n");
	scanf("%f",&precio2);
	}while (!(precio2>0));
	
	costeEnvio1 = precio1 / 100;
	costeEnvio2 = precio2 / 100;
	
	pFinal1 = precio1 + costeEnvio1;
	pFinal2 = precio2 + costeEnvio2;
	
	printf("En la tienda oficial la computadora, con envío y todo, cuesta: %f. \n", pFinal1);
	printf("En la página alternativa la computadora cuesta, con envío y todo: %f. \n", pFinal2);
	
	return 0;
}

