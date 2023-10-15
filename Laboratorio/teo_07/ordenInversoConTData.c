// ordenInverso 
// Copyright (C) 2021 Ariel Ferreira Szpiniak <aferreira@exa.unrc.edu.ar>
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.
/* 
Algoritmo OrdenInverso
Léxico
  Max = 150
  TElem = Z
  TNumeros = arreglo[1..Max] de TElem
  TData = <d e TNumeros, cant e (0..Max)>
  datos e TData
  i e Z 
Inicio
  i <-- 1 
  Entrada:datos.cant
  mientras i <= datos.cant hacer
    Entrada:datos.d[i]
    i <-- i+1	
  fmientras
  // informar Los datos ingresados del último al primero
  i <-- datos.cant 
  mientras i >= 1 hacer
   Salida:datos.d[i]
   i <-- i-1
  fmientras
Fin
*/
// OrdenInverso Ejemplo VII 
#include <stdio.h> 
#include <string.h>
#define Max 150
typedef struct {
    	        int d[Max]; 	
	        int cant;
               }TData;
TData datos;
int i;

int main(){
 	i=0;
 	printf("Ingrese cantidad de elementos: ");
 	scanf("%d",&datos.cant);
 	printf("Ingrese %d numeros\n",datos.cant);
 	while(i<datos.cant){
 	  scanf("%d",&datos.d[i]);
	  i++;
 	}
 	i=datos.cant-1;
 	while(i>=0){
   	  printf("elemento en la posicion %d es %d\n", i,datos.d[i]);
 	  i--;
 	}
return 0;
}
