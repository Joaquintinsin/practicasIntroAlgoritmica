// Sin terminar
#include <stdio.h>

int main(){
    int dia, mes, anio;

    printf("Ingrese el dia:\n");
    scanf("%d", &dia);
    printf("Ingrese el mes:\n");
    scanf("%d",&mes);
    printf("Ingrese un anio:\n");
    scanf("%d",&anio);
    
    if ( dia == 31 || mes == 12){
        anio = anio +1;
        printf("El dia siguiente a la fecha ingresada es %d", anio);
    }else{
		 if (dia == 28 ){
			 
		}
	}
	return 0;
}

