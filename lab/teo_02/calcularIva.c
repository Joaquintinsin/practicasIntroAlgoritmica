// Copyright (C) 2015 Ariel Gonzalez <agonzalez@dc.exa.unrc.edu.ar>
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.

#include <stdio.h>
/* Define una constante */
#define Iva 21

/* Variables */
float precioBruto;       //variable dato
float precioFinal;	//variable resultado

int main(){
  //Se debe utilizar como separador de decimales el punto (no la coma)
  scanf("%f",&precioBruto);
  precioFinal = precioBruto + (precioBruto*Iva)/100;
  printf("El precio final es: %f \n", precioFinal);
  return 0;
}


