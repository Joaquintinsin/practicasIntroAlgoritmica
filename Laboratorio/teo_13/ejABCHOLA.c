//Ej 3
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

// Con esta funcion anadimos la palagra HOLA 
void AnadirPalabraHola(TelemCar **primero);
 
//Recorre la lista y muestra el contenido del campo info de cada doblete
void MostrarLista(TelemCar *primero);

int main() { 
  TelemCar *q, *r, *w, *x;
  
  r = NULL; 
  w = NULL; 
  x = NULL;
  q = NULL; 
  AnadirPalabraHola(&q); 
  MostrarLista(q); 
  r=(TelemCar *) malloc(sizeof(TelemCar));
  r->info='C';
  r->next=q;
  q=r;
  w=(TelemCar *) malloc(sizeof(TelemCar));
  w->info='B';
  w->next=q;
  q=w;
  x=(TelemCar *) malloc(sizeof(TelemCar));
  x->info='A';
  x->next=q;
  q=x;
  MostrarLista(q); 
  // agregar aquí el código para eliminar el doblete que contiene la letra 'A'
  // volver a mostrar la lista aquí
  return(0); 
}

// Con esta funcion anadimos la palagra HOLA 
void AnadirPalabraHola(TelemCar **primero) { 
  TelemCar *nuevo; 

  /* reservamos memoria para el nuevo elemento */ 
  nuevo = (TelemCar *) malloc (sizeof(TelemCar)); 
  if (nuevo==NULL) printf( "No hay memoria disponible!\n"); 
  else {
    nuevo->info='A'; 
    nuevo->next=NULL; 
    *primero=nuevo;
    nuevo = (TelemCar *) malloc (sizeof(TelemCar)); 
    nuevo->info='L'; 
    nuevo->next=*primero; 
    *primero=nuevo;
    nuevo = (TelemCar *) malloc (sizeof(TelemCar)); 
    nuevo->info='O'; 
    nuevo->next=*primero;
    *primero=nuevo;
    nuevo = (TelemCar *) malloc (sizeof(TelemCar)); 
    nuevo->info='H'; 
    nuevo->next=*primero;
    *primero=nuevo;
  }     
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

