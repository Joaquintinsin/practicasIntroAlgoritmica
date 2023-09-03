#include <stdio.h>

int mes; 	// Entrada, el usuario pone el mes que quiere saber los dias
int dia; 	// Resultado, informa si tiene 30, 31 o 28 en caso de febrero unicamente

int main(){
	printf("Ingrese un mes en número, le diré cuántos días tiene en un año no bisiesto. \n");
	printf("Si se ingresan letras entra en un ciclardium infinitardium anachi \n");
	scanf("%d",&mes);
	
	// Inicio Defensa
	while (mes <=0 || mes >=13){
			printf("Ingrese un mes válido. \n");
			scanf("%d",&mes);
	}
	// Fin Defensa
	// Inicio Asignaciones
	if (mes == 2){
		dia = 28;
	}else{
		if (mes == 1 || mes == 3 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
			dia = 31;
		}else{
			dia = 30;
		}
	}
	// Fin Asignaciones
	
	if (mes == 4){
		printf("Abril, el mejor mes del año, tiene %d dias \n", dia);
	}else{
		printf("El mes %d tiene %d dias \n", mes, dia);
	}
	
	return 0;
}

