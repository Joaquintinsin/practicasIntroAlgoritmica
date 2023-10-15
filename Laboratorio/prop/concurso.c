#include <stdio.h>
#include <string.h>

int main(){
	int corre1, corre2, corre3;	// Sumadores de puntos podria definirse 1 sola cte de 100
	int puntObt;
	char resp1[50], resp2[50], resp3[50];	// Respuestas

    printf("Ingrese la respuesta 1: ");
    scanf("%s", resp1);
    printf("Ingrese la respuesta 2: ");
    scanf("%s", resp2);
    printf("Ingrese la respuesta 3: ");
    scanf("%s", resp3);
    
    if( strcmp(resp1,"Donatelo") == 0 ){
        corre1 = 100;
    }else{
        corre1 = 0;
    }
    
    if ( strcmp(resp2,"LaPiedad") == 0 ){
        corre2 = 100;
    }else{
        corre2 = 0;
    }
    
    if( strcmp(resp3,"Rafael") == 0 ){
        corre3 = 100;
    }else{
        corre3 = 0;
    }

    puntObt = corre1 + corre2 + corre3;

    printf("El puntaje obtenido es %d. \n", puntObt);

    return 0;
}
