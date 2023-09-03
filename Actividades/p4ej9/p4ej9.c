/*
· Un contador tiene que realizar el balance de un negocio. Su secretario ha preparado una lista de
números que resumen el resultado de las facturas de todo el mes. En el listado aparecen números
positivos (las ganancias) y negativos (las pérdidas). Puedas ayudar al contador sumando solo los valores
que son negativos y descartando los positivos. El final de la lista se indica con un 999999. Usar un
mientras.
 */
#include <stdio.h>

#define FinLista 99999

int main(){
	float nroResumen;
	float ganancias, perdidas;
	int i;
	
	perdidas = 0;
	ganancias = 0;
	i = 1;
	
	printf ("Nro %d del resumen \n", i);
	scanf ("%f", &nroResumen);
	if ( nroResumen < 0 ){
		perdidas = nroResumen + perdidas;
	}else{
		if ( nroResumen > 0 && nroResumen != 99999 ){
			ganancias = nroResumen + ganancias;
		}
	}
	
	while ( nroResumen != FinLista ){
		i++;
		printf ("Nro %d del resumen \n", i);
		scanf ("%f", &nroResumen);
		if ( nroResumen < 0 ){
			perdidas = nroResumen + perdidas;
		}else{
			if ( nroResumen > 0 && nroResumen != 99999 ){
				ganancias = nroResumen + ganancias;
			}
		}
	}
	
	printf ("El balance negativo del negocio es %2.0f \n", perdidas);
//	printf ("El balance positivo del negocio es %2.0f \n", ganancias);
	
	return 0;
}

