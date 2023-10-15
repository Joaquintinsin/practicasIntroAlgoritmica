// quedó sin hacer pero definiendo tipo registro y tipo enumerado. 
#include <stdio.h>

typedef enum{
	basto, copa, oro, espada
} TPalo;
// también: enum TPalo{basto, copa, oro, espada}; pero se tiene q poner enum siempre, como el struct

typedef struct{
	int valor;
	TPalo palo;	// tengo que aclarar que TPalo es enum, sino me tira error. cada vez q lo quiera usar: enum TPalo
} TCarta;

int main() {
	TCarta carta1, carta2, carta3;	// entradas
	int cantPuntos;
	int Puntos(TCarta carta1, TCarta carta2, TCarta carta3);
	
	
	return 0;
}

int Puntos(TCarta carta1, TCarta carta2, TCarta carta3){
	int puntos = 0;
	TPalo palo = basto;
	if ( carta1.palo == carta2.palo || carta1.palo == carta3.palo || carta2.palo == carta3.palo){
		puntos = carta1.valor + carta2.valor;
	}
	return puntos;
}
