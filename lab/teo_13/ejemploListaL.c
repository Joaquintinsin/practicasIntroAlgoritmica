// Copyright (C) 2021 Cesar Cornejo
// <ccornejo@dc.exa.unrc.edu.ar>
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

/*
Ejemplo creando type Lista
*/

struct TNodo {
        int info;
        struct TNodo *next;
};

struct lista {
        struct TNodo *head;
};

//Crea un nodo
struct TNodo* CrearNodo();

//Inserta un nodo al comienzo de la lista
void InsertarC(struct lista *l);

//Muestra la lista
void MostrarLista(struct lista l);

//Muestra menu
void MostrarMenu();

int main() {
	int opcion;
	struct lista l;
	(l.head)=NULL;
	MostrarMenu();
	scanf("%d",&opcion);
	while(opcion == 1 || opcion == 2){
		if (opcion == 1){
			InsertarC(&l);
		}else{
			if (opcion == 2){
				MostrarLista(l);
			}
		}
		MostrarMenu();
		scanf("%d",&opcion);
	}
	return 0;
}

//Crea un nodo
struct TNodo* CrearNodo() {
	struct TNodo * nuevo;
	nuevo = (struct TNodo *) malloc (sizeof(struct TNodo *));
	if (nuevo==NULL){
	 	exit(EXIT_FAILURE); 
	}
	else {
	  printf("Numero: "); fflush(stdout);
	  scanf("%d",&nuevo->info);
	  nuevo->next = NULL;
	  return nuevo;
	}
}

//Inserta un nodo al comienzo de la lista
void InsertarC(struct lista *l) {
	struct TNodo * nuevo;
	nuevo = CrearNodo();
	if (l->head==NULL) {
		//primer elemento
	 	l->head = nuevo;
	}
	else {
		nuevo->next = (l->head);	 
		l->head = nuevo;
	}
}

//Muestra la lista
void MostrarLista(struct lista l) {
    int i=0;
    printf("\nMostrando la lista completa:\n");
    while (l.head!=NULL) {
          printf( "Numero: %d \n", l.head->info);
          l.head = l.head->next;
          i++;
    }
    if (i==0) printf( "\nLa lista esta vacia!!\n" );
}

//Muestra menu
void MostrarMenu() {
      printf("\n\nMenu:\n=====\n\n");
      printf("1.- Anadir Inicio\n");
      printf("2.- Mostrar lista\n");
      printf("Otro valor.- Salir\n\n");
      printf("Escoge una opcion: ");
      fflush(stdout);
 }
