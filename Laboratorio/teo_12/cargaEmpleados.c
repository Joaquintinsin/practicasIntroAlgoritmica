// CargaEmpleados
// Copyright (C) 2018 Ariel Ferreira Szpiniak
// <aferreira@exa.unrc.edu.ar>
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.

#include <stdio.h>
#include <string.h>
#define Max 20
struct empleado{
	char nombre[100];
	char telefono[100];
	char direccion[100];
	int edad;
};
struct data{
	int cant;
	struct empleado a[Max]; 	
};
int main(){
  struct data datosEmpleados;
  int i;
  datosEmpleados.cant=15;
  for (i=0; i<datosEmpleados.cant; i++){ 
    printf("Ingrese nombre: \n ");
    scanf("%s",datosEmpleados.a[i].nombre);
    printf("Ingrese tel:\n ");
    scanf("%s",datosEmpleados.a[i].telefono);
    printf("Ingrese dir:\n ");     
    scanf("%s",datosEmpleados.a[i].direccion);
    printf("Ingrese edad:\n "); 
    scanf("%d",&(datosEmpleados.a[i].edad));
  }
return 0;
}