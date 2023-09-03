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
Algoritmo GestionarNotas // definicion basica, sin usar TArreglo y con variable auxiliar (n)
Léxico
  NMax = 7
  notas e arreglo [1..NMax] de Z+ // variable de tipo arreglo
  n e  Z+ // variable
  i e Z // Z+ o subrango de 1 a NMax+1
Inicio
  i <-- 1 
  mientras i<=NMax hacer
    Entrada: n      
    notas[i] <-- n  //almacena
    i <-- i+1	
  fmientras
  i <-- 1 
  mientras i<=NMax hacer
   n <-- notas[i] 
   Salida: n // informa
   i <-- i+1         
  fmientras
Fin
*/
// GestionarNotas - definicion basica, sin usar TArreglo
#include <stdio.h>
#define NMax 7
int notas[NMax]; // definición clásica
int n;
int i;

int main(){
 	i=0;
 	while(i<NMax){
 	  scanf("%d",&n);
 	  notas[i]=n;
	  i++;
 	}
 	i=0;
 	while(i<NMax){
 	  n=notas[i];
 	  printf("%d",n);
	  i++;
 	}
return 0;
}

