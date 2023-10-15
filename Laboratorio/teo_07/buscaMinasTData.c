// buscaMinas 
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
Algoritmo Juego2 - Ejemplo V
Léxico
  Fil = 16
  Col = 30
  TMina = arreglo[1..Fil, 1..Col] de (0..9)
  i, j e Z // o subrango   
  TData = <m e TMina, cantFila e (0..Fil), cantCol e (0..Col) //tipo
  buscaMinas e TData // variable
Inicio
  buscaMinas.cantFila<--2
  buscaMinas.cantCol<--30
  para (i<--1, i<=buscaMinas.cantFila, i<--i+1)  hacer
    para (j<--1, j<=buscaMinas.cantCol, j<--j+1)  hacer
      Entrada: buscaMinas.m[i,j] 
    fpara
  fpara
  para (i<--1, i<=buscaMinas.cantFila, i<--i+1)  hacer
    para (j<--1, j<=buscaMinas.cantCol, j<--j+1)  hacer
      Salida: buscaMinas.m[i,j] 
    fpara
  fpara
Fin
*/
#include <stdio.h> // Ejemplo V
#include <string.h>
#define Fil 16
#define Col 30
typedef struct {
	  int m[Fil][Col]; 	
	  int cantFila;
	  int cantCol;
       }TData;
TData buscaMinas;
int i,j;
int main(){
  buscaMinas.cantFila=2;
  buscaMinas.cantCol=3;
  for(i=0;i<buscaMinas.cantFila;i++){
    for(j=0;j<buscaMinas.cantCol;j++){
        scanf("%d",&buscaMinas.m[i][j]);
    }
  }
  for(i=0;i<buscaMinas.cantFila;i++){
    for(j=0;j<buscaMinas.cantCol;j++){
        printf("%d",buscaMinas.m[i][j]);
    }
  }
return 0;
}
