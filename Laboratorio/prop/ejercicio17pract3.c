#include <stdio.h>
#include <string.h>
#include <math.h>

float px, py;		// px y py hacen referencia a un punto cualquiera, siendo x e y puntos del eje cartesiano.
float cx, cy;		// cx y cy son las coordenadas del centro del circulo.
float r1x, r1y;	// r1x y r1y son las coordenadas de un vertice inferior izquierdo de un rectangulo.
float r2x, r2y;	// r2x y r2y son las coordenadas de un vertice superior derecho de un rectangulo, osea la diagonal de (r1x,r2y).
float r, d;		// r es el radio del circulo. d es la distancia del punto problema al radio.
int dentroCirc;	// var aux para almacenar 1 si el punto está dentro del circulo o 0 si no lo está.
int dentroRect;	// var aux para almacenar 1 si el punto está dentro del rectángulo o 0 si no lo está.
 
int main() {
		// Inicio de entradas
	printf("Ingrese un valor x de un punto cualquiera, pensando en los ejes cartesianos. \n");
	scanf("%f", &px);
	printf("Ingrese un valor y de un punto cualquiera, pensando en los ejes cartesianos. \n");
	scanf("%f", &py);
	printf("Ingrese un punto x que corresponda a un vertice inferior izquierdo de un rectangulo. \n");
	scanf("%f", &r1x);
	printf("Ingrese un punto y que corresponda a un vertice inferior izquierdo de un rectangulo. \n");
	scanf("%f", &r1y);
	printf("Ingrese un punto x que corresponda a un vertice superior derecho de un rectangulo. \n");
	scanf("%f", &r2x);
	printf("Ingrese un punto y que corresponda a un vertice superior derecho de un rectangulo. \n");
	scanf("%f", &r2y);
	printf("Ingrese un punto x del centro de un circulo. \n");
	scanf("%f", &cx);
	printf("Ingrese un punto y del centro de un circulo. \n");
	scanf("%f", &cy);
	printf("Por último, ingrese el valor del radio. \n");
	scanf("%f", &r);
		// Fin de entradas
	d = sqrt( (cx-px)*(cx-px) + (cy-py)*(cy-py) );
	
	// si la distancia entre el centro del circulo y el punto es menor o igual que el radio del circulo, el punto está adentro del circulo, sino no.
	if( d<=r ){
		dentroCirc = 1;	// Verdadero
	}else{
		dentroCirc = 0;	// Falso
	}
	
	/* (si la x del punto es mayor o igual al x del vertice inferior) y (menor o igual que el punto x del vertice superior)
	y también (la y del punto es mayor o igual al y del vertice inferior) y (menor o igual que el punto y del vertice superior)
	entonces está dentro del rectángulo. Si alguno de los conyuntos es falso todo será falso, por lo tanto está afuera. */
	if( (px>=r1x) && (px<=r2x) && (py>=r1y) && (py<=r2y) ){
		dentroRect = 1;	// Verdadero
	}else{
		dentroRect = 0;	// Falso
	}
	
	// Inicio de comparaciones, según la verdadera será el mensaje.
	if ( ( dentroCirc == 1 ) && ( dentroRect == 1 ) ){
		printf("El punto está adentro del circulo y del rectangulo. \n");
	}else{
		if ( ( dentroCirc == 1 ) && ( dentroRect == 0 ) ){
			printf("El punto está adentro del circulo, pero afuera del rectángulo. \n");
		}else{
			if ( ( dentroCirc == 0 ) && ( dentroRect == 1 ) ){
				printf("El punto está adentro del rectangulo, pero afuera del circulo. \n");
			}else{
				if( ( dentroCirc == 0 ) && ( ( dentroRect == 0 ) ) ){
					printf("El punto está afuera de ambas figuras. \n");
				}
			}
		}
	} // Fin de comparaciones
	return 0;
}
