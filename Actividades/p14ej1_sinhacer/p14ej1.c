#include <stdio.h>

void CargarArchivo (FILE* *fA);
void CantIguales(char cA, int *iguales);
void CantDistintos(char cA, int* distintos);

int main( int argc, char **argv ) {
	FILE* f;
	char c;
	int igu, dist;
	
	CargarArchivo(&f);
	printf ("Ingresar caracter a comparar \n");
	while ( getchar() != '\n' );
	scanf ("%s", &c);
	CantIguales(c, &igu);
	CantDistintos(c, &dist);
	printf ("Iguales: %d \n", igu);
	printf ("Distintos: %d \n", dist);
	
	return 0;
}

void CargarArchivo (FILE* *fA){
	char cA;
	
	*fA = fopen("secu.txt", "a+");
	printf ("Ingresar caracteres, finalizar con un + \n");
	do{
		while ( getchar() != '\n' );
		scanf ("%s", &cA);
		if ( cA != '+')
			fputc(cA, *fA);
	} while ( !( cA == '+' ));
	fclose(*fA);
}

void CantIguales(char cA, int *iguales){
	FILE* fA;
	char copy;
	
	fA = fopen ("secu.txt", "r+b");
	if ( !fA ){
		printf ("El archivo está vacío \n");
	}else{
		*iguales = 0;
		fscanf(fA, "%c", &copy);
		printf ("valor de copy: %c", copy);
		while ( !(feof(fA)) ){
			if ( copy == cA ){
				iguales++;
			}
			fscanf(fA, "%c", &copy);
		}
	}
	fclose(fA);
}

void CantDistintos(char cA, int* distintos){
	FILE* fA;
	char copy;
	
	fA = fopen("secu.txt", "r+b");
	fscanf(fA, "%c", &copy);
	if ( feof(fA) ){
		printf ("El archivo está vacío \n");
	}else{
		*distintos = 0;
		while ( !(feof(fA)) ){
			if ( copy != cA ){
				distintos++;
			}
			fscanf(fA, "%c", &copy);
		}
	}
	fclose(fA);
}
