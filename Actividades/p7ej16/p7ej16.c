#include <stdio.h>

#define NMax 20
#define MMax 30

typedef struct {
	int a[NMax][MMax];
	int cantFilas;
	int cantCol;
} TData;

void CargarMatriz(TData* matr);
int SumarMatrices(TData k);		// Inciso 16 a)	[Checked]
int SumarEscalera(TData k);		// Inciso 16 b) [Checked {cambia el algoritmo; k[i][j] por k[j][i]}]
void MostrarDiagonal(TData k);	// Inciso 16 c) [Checked]
void MostrarMatriz(TData matr);

int main( int argc, char **argv ) {
	TData matriz;
	int sumaEscalera;
	
	CargarMatriz(&matriz);
	
	// printf ("Inicio inciso A: \n");
	SumarMatrices(matriz);
	
		// printf ("Inicio inciso B: \n");
	sumaEscalera = SumarEscalera(matriz);
	printf ("La suma de la matriz de forma escalonada es de: %d \n", sumaEscalera);
	
		// printf ("Inicio inciso C: \n");
	MostrarDiagonal(matriz);
	
	MostrarMatriz(matriz);
	
	return 0;
}

void CargarMatriz(TData* matr) {	// Accion CargarMatriz(resultado matr e TData)
	int i, j;
	
	printf ("Ingrese cuántas filas tiene la matriz: ");
	scanf ("%d", &matr->cantFilas);
	printf ("Ingrese cuántas columnas tiene la matriz: ");
	scanf ("%d", &matr->cantCol);
	
	for (i=0 ; i < matr->cantFilas ; i++) {
		for (j=0 ; j < matr->cantCol ; j++) {
			printf ("Ingrese el componente de fila %d columna %d de la matriz: ", i, j);
			scanf ("%d", &matr->a[i][j]);
		}
	}
}

int SumarMatrices(TData k) {	// Inciso A	[Checked]
	int i, j;
	int sumador;
	
	sumador = 0;
	for (i=0 ; i < k.cantFilas/2 ; i++) {
		for (j=0 ; j < (k.cantCol/2)+1 ; j++) {
			sumador = k.a[i][j] + sumador;
		}
	}
	
	printf ("La cant sumada de (la mitad de las filas + la mitad de las columnas mas uno) es: %d \n", sumador);
	
	return sumador;
}

int SumarEscalera(TData k) {	// Inciso B	[Checked= cambia el algoritmo; k[i][j] por k[j][i] ]
	int i, j;
	int sumador;
	
	sumador = 0;
	for (j=0 ; j < k.cantFilas ; j++) {
		for (i=0 ; i <= j ; i++) {
			sumador = sumador + k.a[j][i];
		}
	}
	
	return sumador;
}

void MostrarDiagonal(TData k) {	// Inciso C [Checked]
	int i, j;
	
	j = 0;
	printf("Inicio Accion MostrarDiagonal: \n");
	for (i=k.cantFilas-1 ; i >= 0 ; i--) {
		printf("Componente de fila: %d y columna: %d = %d \n", i, j, k.a[i][j]);
		j++;
	}
	printf("Fin Accion MostrarDiagonal. \n");
}

void MostrarMatriz(TData matr) {
	int i, j;
	
	for (i=0 ; i < matr.cantFilas ; i++) {
		for (j=0 ; j < matr.cantCol ; j++) {
			printf ("El componente de fila %d columna %d de la matriz es: %d \n", i, j, matr.a[i][j]);
		}
	}
}
