//Implementación del Ej2, con el agredo de función para mostrar la lista (MostrarLista)
// Copyright (C) 2021 Ariel Ferreira Szpiniak
// <aferreira@exa.unrc.edu.ar>
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.

#include <stdio.h>
#include <stdlib.h>
// Creando type TelemCar
typedef struct Tdoblete {
                 char info;
                 struct Tdoblete *next;
}TelemCar; // tipo

//Recorre la lista y muestra el contenido del campo info de cada doblete
void MostrarLista(TelemCar *primero);

int main() { 
  TelemCar *nuevo, *sec;
  
  nuevo=NULL; 
  sec=NULL; 
  nuevo=(TelemCar *) malloc (sizeof(TelemCar)); 
  nuevo->info='A'; 
  nuevo->next=NULL; 
  sec=nuevo;
  nuevo=(TelemCar *) malloc (sizeof(TelemCar)); 
  nuevo->info='L'; 
  nuevo->next=sec; 
  sec=nuevo;
  nuevo=(TelemCar *) malloc (sizeof(TelemCar)); 
  nuevo->info='O'; 
  nuevo->next=sec;
  sec=nuevo;
  nuevo=(TelemCar *) malloc (sizeof(TelemCar)); 
  nuevo->info='H'; 
  nuevo->next=sec;
  sec=nuevo;
  MostrarLista(sec); 
  return(0); 
}

void MostrarLista(TelemCar *primero) { 
  TelemCar *auxiliar; /* lo usamos para recorrer la lista */ 
  int i; 
 
  i=0; 
  auxiliar=primero; 
  printf("\nMostrando la lista completa:\n"); 
  while (auxiliar!=NULL) { 
    printf("%c",auxiliar->info); 
    auxiliar=auxiliar->next; 
    i++; 
  } 
  printf("\n");
  if (i==0) printf( "\nLa lista esta vacia!\n" ); 
} 

