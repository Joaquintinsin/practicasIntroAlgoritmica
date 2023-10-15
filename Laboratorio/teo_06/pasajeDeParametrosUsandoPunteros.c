// pasajeDeParametrosUsandoPunteros_2022
// controlando datos de entrada Reales positivos
// Copyright (C) 2022 Ariel Ferreira Szpiniak <aferreira@exa.unrc.edu.ar>
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.
// Los pasajes por resultado y dato-resultado (por copis), no existen en C, 
// por ese motivo se se simulan utilizando las direcciones de memoria de las
// variables, mediante punteros (*).

#include <stdio.h>
float base, altura;	//base y altura del triangulo
float area;  	//area del triangulo

void ObtenerDatos(float *x, float *y);
void CalcularAreaTriangulo(float baseTri, float alturaTri, float *areaTri);
void InformarResultados(float a);

int main(){
  ObtenerDatos(&base, &altura);
  CalcularAreaTriangulo(base, altura, &area);
  InformarResultados(area);
  return 0;
}
 
void ObtenerDatos(float *x, float *y){
// controlando que x e y sean reales positivos y distintos de 0
  do {
    printf("Ingrese la base: ");
    scanf("%f",&(*x));
    printf("Ingrese el altura: ");
    scanf("%f",&(*y));	
  } while ((*x<=0)||(*y<=0));
}

void CalcularAreaTriangulo(float baseTri, float alturaTri, float *areaTri){
    *areaTri = (baseTri*alturaTri)/2;
}
void InformarResultados(float a){
    printf("El area del triangulo es: %f \n",a);
}
