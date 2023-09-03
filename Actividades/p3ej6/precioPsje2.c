// Implementación 2; forma alternativa y uso de constantes.
#include <stdio.h>
#include <string.h>

#define Precio30 4650;					// declaro precios constantes según los dias. de 30 en adelante 4650.
#define Precio29y15 5350;			// entre 29 y 15 vale 5350.
#define Precio14y1 6875;				// entre 14 y 1 vale 6875.
#define Precio30x2 4650 * 2;			// si es de ida y vuelta será el mismo precio por dos.
#define Precio29y15x2 5350 * 2;	// entre 29 y 15 dias el mismo precio por dos.
#define Precio14y1x2 6875 * 2;		// entre 14 y 1 dias el mismo precio por dos.
int diasQueFaltan;		// entrada; el usuario pone cuántos dias faltan para el vuelo
char idaOidaYv[11];	// entrada; el usuario pone si es ida o ida y vuelta
int precioPsje;			// almacenará cuánto va a costar el pasaje, para luego informarselo al usuario
int pasajeIda;			// almacena 1 si el pasaje es de ida, o 2 si es de ida y vuelta

int main(){
/* Inicio entrada cadena, almacena en idaOidaYv 1 si es ida o 2 si es idayvuelta. No se pudo espaciar porque toma
 * lo que sigue del espacio para el siguiente scanf y se rompe todo (que es para la cant de dias que faltan para el vuelo)*/
	printf("Ingrese 'ida' si quiere un pasaje solo de ida. \n");
	printf("Si quiere uno de ida y vuelta escriba 'idayvuelta'. \n");
	scanf("%s", idaOidaYv);
    if(strcmp(idaOidaYv, "ida") == 0 ){ 
        pasajeIda = 1;
    }else{
		if(strcmp(idaOidaYv, "idayvuelta") == 0 ){ 
			pasajeIda = 2;
		}else{
			printf("Vuelva a intentarlo. Ingrese 'ida' o 'idayvuelta'. \n");
			return 0;
		}
	}
// Fin de entrada de cadena.
// Inicio de entrada de días que faltan para el vuelo
	printf("Ingrese los dias que faltan para el vuelo. \n");
	scanf("%d", &diasQueFaltan);
// Fin de entrada de días. Inicio de comparaciones/operaciones e informe del resultado.
	if( ( pasajeIda == 1 ) ){ // Inicio de precios si el pasaje es solo de ida
		if( ( diasQueFaltan >= 30 ) ){
			precioPsje = Precio30;
		}else{
			if( ( diasQueFaltan <= 29 ) && ( diasQueFaltan >= 15 ) ){
				precioPsje = Precio29y15;
			}else{
				if( ( diasQueFaltan <= 14 ) && ( diasQueFaltan >= 1 ) ){
					precioPsje = Precio14y1;
				}else{
					printf("Solo puede sacar vuelos con al menos 1 día de antelación, vuelva a intentarlo. \n");
					return 0;
				}
			}
		}
	}else{ // Fin de precios de solo ida. Entra por acá si pasajeIda != 1. Entonces: Inicio de precios si es de ida o vuelta.
		if( ( diasQueFaltan >= 30 ) ){
			precioPsje = Precio30x2;
		}else{
			if( ( diasQueFaltan <= 29 ) && ( diasQueFaltan >= 15 ) ){
				precioPsje = Precio29y15x2;
			}else{
				if( ( diasQueFaltan <= 14 ) && ( diasQueFaltan >= 1 ) ){
					precioPsje = Precio14y1x2;
				}else{
					printf("Solo puede sacar vuelos con al menos 1 día de antelación, vuelva a intentarlo. \n");
					return 0;
				}
			}
		} // Fin de precios de ida y vuelta.
	} // Cierre de bloque de primer if 
	printf("Su pasaje cuesta: %d. \n", precioPsje);
	return 0;
}
