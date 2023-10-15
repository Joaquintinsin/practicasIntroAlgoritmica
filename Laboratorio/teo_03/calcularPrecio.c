// CalcularPrecio
// Copyright (C) 2021 Ariel Ferreira Szpiniak <aferreira@exa.unrc.edu.ar>
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.

#include <stdio.h> //CalcularPrecio

/* léxico */
float precioBruto;
float iva; 
float precioFinal;

/* función principal (main) en todo programa C */
void main(){
  scanf("%f",&precioBruto);
  scanf("%f",&iva);
  precioFinal = precioBruto+(precioBruto*iva)/100;
  printf("%f",precioFinal);
}
