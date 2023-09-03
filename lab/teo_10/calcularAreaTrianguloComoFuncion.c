// CalcularAreaTriánguloComoFuncion
// Copyright (C) 2018 Ariel Ferreira Szpiniak <aferreira@exa.unrc.edu.ar>
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.

// CalcularAreaTriángulo
#include <stdio.h>
float base, altura;	//base y altura del triangulo
float area;  	//area del triangulo
void ObtenerDatos(float *b, float *h);
float CalcArea(float b, float h);
void InformarArea(float a);
int main(){
    ObtenerDatos(&base, &altura);
    area = CalcArea(base, altura);
    InformarArea(area);
    return 0;
}
void ObtenerDatos(float *b, float *h){
    do {
        printf("Ingrese la base: \n ");
        scanf("%f",&(*b));
    } while ((*b)<=0); 
    do {
        printf("Ingrese el altura: \n");
        scanf("%f",&(*h));	
    } while ((*h)<=0);
}
float CalcArea(float b, float h){
    return (b*h)/2;
}
void InformarArea(float a){
    printf("El area del triangulo es: %f \n",a);
}