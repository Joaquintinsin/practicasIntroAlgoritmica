#include <stdio.h>

typedef struct{
	int grado;
	int min;
	int seg;
} TAngulo;
	TAngulo ang1, ang2;	// entradas
	TAngulo res;				// almacenador
	TAngulo cierreAngular; // salida
	
TAngulo TercerAngulo( TAngulo x, TAngulo y );

int main( int argc, char **argv ) {
	printf ("Etapa 1: Primer angulo \n");			// entrada de ang1
	
	printf ("Ingresar los grados del primer angulo \n");
	scanf ("%d",&ang1.grado);
	printf ("Ingresar los minutos del primer angulo \n");
	scanf ("%d",&ang1.min);
	printf ("Ingresar los segundos del primer angulo \n");
	scanf ("%d",&ang1.seg);
	
	
	printf ("Etapa 2: Segundo angulo \n");			// entrada de ang2
	
	printf ("ingresar los grados del segundo angulo \n");
	scanf ("%d",&ang2.grado);
	printf ("ingresar los minutos del segundo angulo \n");
	scanf ("%d",&ang2.min);
	printf ("ingresar los segundos del segundo angulo \n");
	scanf ("%d",&ang2.seg);
	
	res = TercerAngulo(ang1, ang2);
	
	cierreAngular.grado = 180 - res.grado;
	cierreAngular.min = 60 - res.min;
	cierreAngular.seg = 60 - res.seg;
	
	printf ("El tercer angulo vale %d grados, %d minutos, %d segundos \n", cierreAngular.grado, cierreAngular.min, cierreAngular.seg	);
	
	return 0;
}

TAngulo TercerAngulo( TAngulo x, TAngulo y ){
	TAngulo alma;
	int segundos;
	int minutos;
	int grados;
	
	segundos = x.seg + y.seg;
	minutos = x.min + y.seg;
	grados = x.grado + y.grado;
	
	if ( segundos >= 60 ){
		minutos++;
		segundos = segundos - 60;
	}
	if ( minutos >= 60 ){
		grados++;
		minutos = minutos - 60;
	}
	alma.grado = grados;
	alma.min = minutos;
	alma.seg = segundos;
	
	return alma;
}

