#include <stdio.h> 
#include <string.h>
/* Variables */
char nombre[17]; //16 mas el caracter nulo o de fin de cadena '\0'
char telefono[21]; //20 mas el caracter nulo o de fin de cadena '\0'
char direccion[41]; //40 mas el caracter nulo o de fin de cadena '\0'
int edad;

int main(){
  printf("\n Ingrese Nombre: "); 
  fgets(nombre,17,stdin);
  printf("\n Ingrese Telefono: ");
  fgets(telefono,21,stdin);
  printf("\n Ingrese Direccion: ");
  fgets(direccion,41,stdin);
  printf("\n Ingrese Edad: ");
  scanf("%d",&edad);
  printf("\n Los datos personales del empleado son: \n");
  printf("\n Nombre: %s \n", nombre);
  printf("\n Telefono: %s \n", telefono);
  printf("\n Direccion: %s \n", direccion);
  printf("\n Edad: %d \n", edad);
  return 0;
}

