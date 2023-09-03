// GuardarNotasV2
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
Algoritmo GuardarNotasV2 - definicion usando TArreglo
Léxico
  NMax = 7
  TArreglo = arreglo [1..NMax] de Z+
  notas e TArreglo // variable de tipo arreglo
  n e  Z+ // variable
  i e Z // Z+ o subrango de 1 a NMax+1
Inicio
  i <-- 1 
  mientras i<=NMax hacer
    Entrada: n      
    notas[i] <-- n  //almacena
    i <-- i+1	
  fmientras
Fin
*/
// GuardarNotasV2 - definicion usando TArreglo
#include <stdio.h>
#define NMax 7
typedef int TArreglo [NMax];
TArreglo notas;
int n;
int i;

int main(){
 	i=0;
 	while(i<NMax){
 	  scanf("%d",&n);
 	  notas[i]=n;
	  i++;
 	}
// el codigo (comentado) que sigue puede usarse para comprobar que las notas se guardaron correctamente. Luego debe borrarse.
// 	i=0;
// 	while(i<NMax){
// 	  printf("%d",notas[i]);
//	  i++;
// 	}
return 0;
}

