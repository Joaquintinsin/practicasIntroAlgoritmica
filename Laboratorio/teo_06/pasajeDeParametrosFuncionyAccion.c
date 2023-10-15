// pasajeDeParametrosFuncionyAccion
// Copyright (C) 2020 Ariel Ferreira Szpiniak <aferreira@exa.unrc.edu.ar>
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.

#include <stdio.h>
int s1, s2, resultado;
int funcionSuma(int a, int b);
void accionSuma(int x, int y, int *res);

int main(){
  printf("Ingrese el primer valor para sumar: ");
  scanf("%i",&s1);
  printf("Ingrese el segundo valor para sumar: ");
  scanf("%i",&s2);
  printf("Llamamos a funcionSuma (pasaje por dato) \n");
  printf("Valor de s1: %i, valor de s2: %i\n",s1,s2);
  resultado = funcionSuma(s1,s2);
  printf("Resultado de la funcionSuma: %i\n",resultado);
  printf("Llamamos a la accionSuma con s1 y s2, ");
  printf("y el resultado lo guardamos usando un puntero a entero llamado res \n");  
  printf("Valor de s1: %i, valor de s2: %i\n",s1,s2);
  accionSuma(s1,s2,&resultado);
  printf("Resultado de la accionSuma: %i\n",resultado);
  printf("Valor de la posicion en memoria de la variable resultado: %p\n",&resultado);
  return 0;
}

int funcionSuma(int a, int b){
  return a+b;
}

void accionSuma(int x, int y, int *res){
  *res = x+y;
}

