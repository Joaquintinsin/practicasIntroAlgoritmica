#include <stdio.h>
#include <string.h>

char msje1[50];

int main() {
    printf("Ingresa tu nombre");
    scanf("%s", msje1);
    if(strcmp(msje1, "Maxi") == 0 ) { 
        //strcmp (o string compare) es una función que devuelve 0 si ambas cadenas son iguales
        printf( "Tenemos el mismo nombre :)" );
    }
    else {
        printf( "No tenemos el mismo nombre" );
    }
    return 0;
}