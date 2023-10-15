#include <stdio.h>

int Bisiesto(int anio);

int main(){
	int entryValue=1;
	
	do{
		
		if (entryValue >= 1){
			printf ("Ingrese un año. \n");
			scanf ("%d",&entryValue);
		}else{
			printf ("El año debe ser de 1 en adelante. \n");
			scanf ("%d",&entryValue);
		}
		
	} while ( ! ( entryValue >= 1 ) );

	if ( Bisiesto ( entryValue ) == 1 ) {
		printf ("Es un año bisiesto. \n");
    }else{
        printf ("No es un año bisiesto \n");
    }

	return 0;
}

int Bisiesto(int anio){
	
	if ( ( (anio%4)==0  && (anio%100) != 0 ) || ( (anio%100)==0 && (anio%400)==0 ) ) {
		return 1;
    }else{
        return 0;
    }

}

