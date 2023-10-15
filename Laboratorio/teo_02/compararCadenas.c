#include <stdio.h>
#include <string.h>

char msje1[50];
char msje2[50];

int main(){
    printf("Ingresa una cadena: ");
    scanf("%s", msje1);
    printf("Ingresa otra: ");
    scanf("%s", msje2);
    if(strcmp(msje1, msje2) == 0 ){ 
        //strcmp (o string compare) es una función que devuelve 0 si ambas cadenas son iguales
        printf( "Las cadenas son iguales" );
    }else{
        printf( "Son distintos cadenas" );
    }
    return 0;
}
