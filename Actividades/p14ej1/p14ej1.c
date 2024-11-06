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
	scanf(" %c", &c);
	CantIguales(c, &igu);
	CantDistintos(c, &dist);
	printf ("Iguales: %d \n", igu);
	printf ("Distintos: %d \n", dist);
	
	return 0;
}

void CargarArchivo (FILE* *fA){
	char cA;
	
	*fA = fopen("secu.txt", "a+");
	if (*fA == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

	printf ("Ingresar caracteres, finalizar con un + \n");
	do{
		while ( getchar() != '\n' );
		scanf(" %c", &cA);
		if ( cA != '+')
			fputc(cA, *fA);
	} while ( !( cA == '+' ));
	fclose(*fA);
}

void CantIguales(char cA, int *iguales){
	FILE* fA;
	char copy;
	
	fA = fopen ("secu.txt", "r");
	if (fA == NULL) {
        printf("El archivo está vacío o no se pudo abrir\n");
        return;
    }
    *iguales = 0;
    while ((copy = fgetc(fA)) != EOF) {
        if (copy == cA) {
            (*iguales)++;
        }
    }
	fclose(fA);
}

void CantDistintos(char cA, int* distintos){
	FILE* fA;
	char copy;
	
	fA = fopen("secu.txt", "r");
	if (fA == NULL) {
        printf("El archivo está vacío o no se pudo abrir\n");
        return;
    }
    
    *distintos = 0;
    while ((copy = fgetc(fA)) != EOF) {  // Leer hasta el final del archivo
        if (copy != cA) {
            (*distintos)++;
        }
    }
	fclose(fA);
}
