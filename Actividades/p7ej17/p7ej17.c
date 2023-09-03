// Corazon = Cáscara: Dada una matriz de [n x m] de enteros, con n >= 3
// y m >= 3, determinar si la sumatoria de las celdas límites (cáscara)
// es igual que la sumatoria las celdas del interior (todas menos las
// limites). Por ejemplo, para la siguiente matriz de (4x4). La respuesta
// es verdadero, ya que las celdas límites suman 11 al igual que las del interior.
#include <stdio.h>

#define NFilas 4
#define NColumnas 4

typedef struct {
	int a[NFilas][NColumnas];
	int cantFilas;
	int cantCol;
} TMatriz;

void CargarMatriz(TMatriz* matr);
int EsLimite(int n, int m);
int CorazonCascara(TMatriz k);

int main( int argc, char **argv ) {
	TMatriz matriz;
	
	CargarMatriz(&matriz);
	
	if ( CorazonCascara(matriz) ){
		printf ("La sumatoria de la cáscara coincide con la sumatoria del corazón \n");
	}else{
		printf ("La sumatoria no coincide. \n");
	}
	
	return 0;
}

void CargarMatriz(TMatriz* matr) {	// Accion CargarMatriz(resultado matr e TData)
	int i, j;
	
	printf ("Se va a cargar una matriz de %d x %d \n", NFilas, NColumnas);
	
	matr->cantFilas = NFilas;
	matr->cantCol = NColumnas;
	
	for (i=0 ; i < matr->cantFilas ; i++) {
		for (j=0 ; j < matr->cantCol ; j++) {
			printf ("Ingrese el componente de fila %d columna %d de la matriz: ", i, j);
			scanf ("%d", &matr->a[j][i]);
		}
	}
}

int EsLimite(int n, int m){	// Función EsLimite(dato n, m e Z) -> Lógico
	if ( n == 0 || n == NFilas-1 ||  m == 0 || m == NColumnas-1 ) {	// ( <- (n=1 o n=N) o (m=1 o m=M) )
		return 1;
	}else{
		return 0;
	}
}

int CorazonCascara(TMatriz k){	// Función CorazonCascara(dato k e TMatriz) -> Lógico
	int i, j;
	int resLim, resCor;
	
	resLim = 0;
	resCor = 0;
	
	for (i = 0 ; i < k.cantFilas ; i++) {
		for (j = 0 ; j < k.cantCol ; j++) {
			if ( EsLimite(i,j) ) {
				// printf ("i = %d - j = %d \n", i, j);
				resLim = resLim + k.a[j][i];
			}else{
				resCor = resCor + k.a[j][i];
			}
		}
	}
	
	// printf ("resLim = %d - resCor = %d \n", resLim, resCor);
	
	if ( resLim == resCor ) {	// (<- resLim = resCor)
		return 1;
	}else{
		return 0;
	}
}
