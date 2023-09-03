// valorAbsoluto2
// Copyright (C) 2021 Ariel Ferreira Szpiniak <aferreira@exa.unrc.edu.ar>
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.

#include <stdio.h>
/* Variables */
int num; //variable para almacenar el numero a analizar
int valAbs; //variable para almacenar resultado del valor absoluto

int main(){
  printf("Ingrese un numero entero: ");
  scanf("%d",&num);
  valAbs=num;
  if (num <=0) {
    //num es negativo
    valAbs=num*(-1); // valAbs=-num
  } 
  printf ("Valor absoluto es: %d\n", valAbs);
  return 0;
}

