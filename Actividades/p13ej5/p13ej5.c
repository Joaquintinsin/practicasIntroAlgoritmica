#include <stdio.h>

typedef struct TData{
	int m[12][31];
	int row, col; // (0..12) (0..31)
}TData;

void CargarMatriz(TData *q);

int main( int argc, char **argv ) {
	int i, j, max, dia, mes;
	TData lluvia;
	
	CargarMatriz(&lluvia);
	i = 0;
	j = 0;
	
	if ( i >= lluvia.row || j >= lluvia.col ){
		printf ("Matriz vacía \n");
	}else{
		max = lluvia.m[i][j];
		dia = j;
		mes = i;
		j = j + 1;
		while ( i < lluvia.row ){
			while ( j < lluvia.col ){
				if ( max < lluvia.m[i][j] ){
					max = lluvia.m[i][j];
					dia = j;
					mes = i;
				}
				j++;
			}
			j=0;
			i++;
		}
		printf ("Max: %d , Dia: %d , Mes: %d \n", max, dia+1, mes+1);
	}
	
	return 0;
}

void CargarMatriz(TData *q){
	printf ("¿Cuántos meses quiere cargar?: ");
	do{
		scanf ("%d", &q->row);
		if ( q->row < 0 || q->row > 12 ){
			printf ("Del 0 al 12 \n");
		}
	} while ( !( q->row >= 0 && q->row <= 12 ) );
	
	printf ("¿Cuántos dias quiere cargar?: ");
	
	do{
		scanf ("%d", &q->col);
		if ( q->col < 0 || q->col > 31 ){
			printf ("Del 0 al 31 \n");
		}
	} while ( !( q->col >= 0 && q->col <= 31 ) );
	
	for ( int i = 0 ; i < q->row ; i++ ){
		for ( int j = 0 ; j < q->col ; j++ ){
			printf ("Cargar la cant lluvia del dia %d y mes %d \n", j, i);
			scanf ("%d", &q->m[i][j]);
		}
	}
}
