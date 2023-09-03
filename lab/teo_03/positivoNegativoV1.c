// positivoNegativoV1
// Copyright (C) 2018 Ariel Ferreira Szpiniak <aferreira@exa.unrc.edu.ar>
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.

#include <stdio.h>
/* Lexico */
int  num; //variable con el numero a analizar
int resultado;// variable para informar
int main(){
  printf("Ingrese un numero entero: ");
  scanf("%d",&num);
  if (num<0) {
    //num es negativo
    resultado=0;
  }
  else {
    //num es positivo
    resultado=1;
  } 
  return 0;
}