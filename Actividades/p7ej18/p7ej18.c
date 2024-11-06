// sin terminar.. falta el int main
#include <stdio.h>

#define M 5
#define N 5

typedef struct TMatriz{
	int mat[M][N];
} TMatriz;

typedef struct TData{
	TMatriz a;
	int row;
	int col;
} TData;

TMatriz Suma(TMatriz k1, TMatriz k2);

int main( int argc, char **argv ) {
	TData m1, m2, m3;
	
	printf ("filas \n");
	scanf ("%d", &m1.row);
	printf ("columnas \n");
	scanf ("%d", &m1.col);
	
	m2.row = m1.row;
	m2.col = m1.col;
	m3.row = m1.row;
	m3.col = m1.col;
	
	for (int i = 0 ; i < m1.row ; i++ ){
		for (int j = 0 ; j < m1.col ; j++ ){
			printf ("Valor de fila %d columna %d \n", i, j);
			scanf ("%d", &m1.a.mat[i][j]);
		}
	}
	
	for (int i = 0 ; i < m2.row ; i++ ){
		for (int j = 0 ; j < m2.col ; j++ ){
			printf ("Valor de fila %d columna %d \n", i, j);
			scanf ("%d", &m2.a.mat[i][j]);
		}
	}
	
	m3.a = Suma(m1.a, m2.a);
	
	for (int i = 0 ; i < m1.row ; i++ ){
		for (int j = 0 ; j < m1.col ; j++ ){
			printf ("M3: Valor en fila %d columna %d : %d \n", i, j, m3.a.mat[i][j]);
		}
	}
	
	return 0;
}

TMatriz Suma(TMatriz k1, TMatriz k2){
	int i, j;
	TMatriz k3;
	
	for ( i = 0 ; i < M ; i++ ){
		for ( j = 0 ; j < N ; j++ ){
			k3.mat[i][j] = k1.mat[i][j] + k2.mat[i][j];
		}
	}
	
	return k3;
}
