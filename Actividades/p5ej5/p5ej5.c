#include <stdio.h>
#include <math.h>

float MayorEntreDosNumeros(float a, float b);
float MayorEntreSeisNumeros(float x1, float x2, float x3, float x4, float x5, float x6);

int main( int argc, char **argv ) {
	float n1, n2, n3, n4, n5, n6;	// entradas
	float res=0;	// almacenador del casteo de la funcion y salida
	printf ("El programa dice cual es el mayor entre seis numeros. \n");
	printf ("Ingrese los 6 numeros. \n");
	scanf ("%f", &n1);
	scanf ("%f", &n2);
	scanf ("%f", &n3);
	scanf ("%f", &n4);
	scanf ("%f", &n5);
	scanf ("%f", &n6);
	
	res = MayorEntreSeisNumeros(n1,n2,n3,n4,n5,n6);
	
	/* otra solucion:
	res = MayorEntreDosNumeros(n1,n2);
	res = MayorEntreDosNumeros(res,n3);
	res = MayorEntreDosNumeros(res,n4);
	res = MayorEntreDosNumeros(res,n5);
	res = MayorEntreDosNumeros(res,n6);
	*/
	
	printf ("El mayor entre los seis nros digitados es %f. \n", res);
	// otra solucion: printf ("El mayor entre %f, %f, %f, %f, %f, %f es %f. \n", n1, n2, n3, n4, n5, n6, res);
	
	return 0;
}

float MayorEntreDosNumeros(float a, float b){
	float aux=0;
	aux = ( (a+b) + fabs(a-b) ) / 2;
	return aux;
}

float MayorEntreSeisNumeros(float x1, float x2, float x3, float x4, float x5, float x6){
	float aux=0;
	aux = MayorEntreDosNumeros(x1,x2);
	aux = MayorEntreDosNumeros(aux,x3);
	aux = MayorEntreDosNumeros(aux,x4);
	aux = MayorEntreDosNumeros(aux,x5);
	aux = MayorEntreDosNumeros(aux,x6);
	return aux;
}

