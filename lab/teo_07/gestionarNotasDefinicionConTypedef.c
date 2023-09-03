// GestionarNotas
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
Algoritmo GestionarNotas
Léxico
  NMax = 7
  TArreglo = arreglo [1..NMax] de Z+ 
  notas e TArreglo  // variable
  i e Z
Inicio
  i <-- 1 
  mientras i<=NMax hacer
    Entrada: notas[i] //almacena 
    i <-- i+1	
  fmientras
  i <-- 1 
  mientras i<=NMax hacer
   Salida: notas[i] // informa
   i <-- i+1         
  fmientras
Fin
*/
// GestionarNotas
#include <stdio.h>
#define NMax 7
typedef int TArreglo [NMax];
TArreglo notas;
int i;

int main(){
 	i=0;
 	while(i<NMax){
 	  scanf("%d",&notas[i]);
	  i++;
 	}

 	i=0;
 	while(i<NMax){
 	  printf("%d",notas[i]);
	  i++;
 	}
return 0;
}

