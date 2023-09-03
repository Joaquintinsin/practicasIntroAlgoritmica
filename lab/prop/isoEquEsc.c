#include <stdio.h>

float a,b,c;	// entradas

int main(){
	printf("El programa definirá si un triángulo es equilatero, isósceles o escaleno. \n");
    printf("Ingrese el valor del lado A. \n");
    scanf("%f",&a);
    printf("Ingrese el valor del lado B. \n");
    scanf("%f",&b);
    printf("Ingrese el valor del lado C. \n");
    scanf("%f",&c);

    if ( a==b && b==c ){
		printf("El triangulo es equilatero. \n");
    }else{
		if ( a==b && b!=c ){
			printf("El triangulo es isosceles. \n");
		}else{
			printf("El triangulo es escaleno. \n");
		}
    }
    
	return 0;
}

