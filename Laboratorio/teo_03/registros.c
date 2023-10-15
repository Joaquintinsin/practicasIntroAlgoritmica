#include <stdio.h>
#include <string.h>

typedef struct {
	char nombre[17]; //16 mas el caracter nulo o de fin de cadena '\0'
    char telefono[21];  //20 mas el caracter nulo o de fin de cadena '\0'
    char direccion[41]; //40 mas el caracter nulo o de fin de cadena '\0'
    int edad;
               }TEmpleado;

TEmpleado emp1;

int main(){
  printf("Ingrese Nombre: \n"); 
  fgets(emp1.nombre,17,stdin);
  
  printf("Ingrese Telefono: \n");
  fgets(emp1.telefono,21,stdin);
  
  printf("Ingrese Direccion: \n");
  fgets(emp1.direccion,41,stdin);
  
  printf("Ingrese Edad: \n");
  scanf("%d",&emp1.edad);
  
  
  printf("\nLos datos personales del empleado son: \n");
  printf("Nombre: %s \n", emp1.nombre);
  printf("Teléfono: %s \n", emp1.telefono);
  printf("Dirección: %s \n", emp1.direccion);
  printf("Edad: %d \n", emp1.edad);
  
  
  return 0;
}
