// notas
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
Algoritmo Notas
Léxico
  Max = 250
  TElem = (1..10)
  TNumeros = arreglo[1..Max] de TElem
  TData = <m e TNumeros, cant e (0..Max)>
  misNotas e TData
  Acción CargarNotas (resultado notas e TData)
  Léxico local
    i e Z 
  Inicio
    // cantidad de notas a cargar
    Entrada:notas.cant
    para (i<--1, i<=notas.cant, i<--i+1) hacer
      // obtener cada nota
         Entrada:notas.m[i]
    fpara
  Facción
Inicio
  CargarNotas(misNotas)
Fin
*/
// Notas Ejemplo VIII
#include <stdio.h> 
#include <string.h>
#define Max 250
typedef struct {
    	        int m[Max]; 	
	        int cant;
               }TData;
TData misNotas;
void cargarNotas(TData *notas);

int main(){
	cargarNotas(&misNotas);
}

void cargarNotas(TData *notas){
	int i;
 	// cantidad de notas a cargar
 	printf("Ingrese cantidad de elementos: ");
  	scanf("%d",&notas->cant);
 	printf("Ingrese %d números\n",notas->cant);
 	for(i=0;i<(*notas).cant;i++){
          scanf("%d",&notas->m[i]);
	}
// el codigo (comentado) que sigue puede usarse para comprobar que las notas se guardaron correctamente. Luego debe borrarse.
//	printf("Lo ingresado es: \n");
// 	for(i=0;i<(*notas).cant;i++){
//        printf("posicion %d es %d\n", i,notas->m[i]);
//	}
}
