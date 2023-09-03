#include <stdio.h>
#include <string.h>

int dias;
int pasajeIda;
int precio;
int auxiliar;

int main(){
	printf("Ingrese 1 si quiere un pasaje de ida solamente. \n");
	printf("Si quiere uno de ida y vuelta ingrese un 2. \n");
	scanf("%d", &pasajeIda);
    if(pasajeIda == 1 ){ 
		auxiliar = 1;
    }else{
		if(pasajeIda == 2 ){ 
			auxiliar = 2;
		}else{
			printf("Incorrecto, ingrese un 1 o un 2. \n");
			return 0;
		}
	}
	
	printf("Ingresar en cuántos días va a viajar en avión. \n");
	scanf("%d", &dias);
	if( ( dias >= 30 ) && ( auxiliar == 1 ) ){
		precio = 4650;
	}else{
		if( ( dias <= 29 ) && ( dias >= 15 ) && ( auxiliar == 1 ) ){
			precio = 5350;
		}else{
			if( ( dias <= 14 ) && ( dias >= 1 ) && ( auxiliar == 1 ) ){
				precio = 6875;
			}else{
				if( ( dias >= 30 ) && ( auxiliar == 2 ) ){
					precio = 4650 * 2;
				}else{
					if( ( dias <= 29 ) && ( dias >= 15 ) && ( auxiliar == 2 ) ){
						precio = 5350 * 2;
					}else{
						if( ( dias <= 14 ) && ( dias >= 1 ) && ( auxiliar == 2 ) ){
							precio = 6875 * 2;
						}else{
							printf("No puso días válidos. Intentarlo de nuevo. \n");
							return 0;
						}
					}
				}
			}
		}
	}
	printf("Su pasaje cuesta: %d. \n", precio);
	return 0;
}
