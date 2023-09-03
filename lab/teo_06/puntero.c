// puntero
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
int base; // 2 bytes
float prom; //4 bytes
char op1, op2; //1 byte c/u
int *pBase;

int main(){
  base= 5;
  pBase = &base;
  printf("Valor de base es: %d \n", base);
  printf("Direccion de base es: %p \n", &base);
  printf("Valor del puntero pBase es: %p \n", pBase);
  printf("Valor que apunta el puntero pBase es: %d \n", *pBase);
  printf("Direccion del puntero pBase es: %p \n", &pBase);
  return 0;
}
