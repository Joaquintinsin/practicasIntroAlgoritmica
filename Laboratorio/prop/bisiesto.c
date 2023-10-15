#include <stdio.h>

int main(){
	int x;

    printf("Ingresa un año. \n");
    scanf("%d",&x);

    if ( ( (x%4)==0  && (x%100) != 0 ) || ( (x%100)==0 && (x%400)==0 ) ) {
        printf ("Es un año bisiesto. \n");
    }else{
        printf ("No es un año bisiesto \n");
    }
    
	return 0;
}

