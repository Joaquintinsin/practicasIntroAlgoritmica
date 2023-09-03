#include <stdio.h>

int main(){
	#define hrsMax 40 // constante
    #define salariohrs 10 // constante
    int hrsTrabajadas, salario;
    printf("Ingrese las horas trabajadas: ");
    scanf("%d", &hrsTrabajadas); // %d vas a querer guardar algo de tipo INT , y donde en una variable ya declarada
    printf("\n");
    if ( hrsTrabajadas <= hrsMax ){
        salario = hrsTrabajadas * salariohrs;
    }else{
        salario = hrsMax * salariohrs + (hrsTrabajadas - hrsMax) * 15;
    }
    printf("EL SALARIO TOTAL ES: %d", salario);
	return 0;
}
