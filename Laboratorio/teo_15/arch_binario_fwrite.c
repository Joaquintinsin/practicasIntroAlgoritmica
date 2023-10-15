// Copyright (C) 2021 Ariel Ferreira Szpiniak, Cesar Cornejo
// <aferreira@exa.unrc.edu.ar>, <ccornejo@dc.exa.unrc.edu.ar >
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.

#include <stdio.h>
#include <string.h>
  
typedef struct {
  char nombre[30]; 
  int edad;
} TAlumno;
TAlumno alumno; 
char nom[30];
FILE *f; 
int i;

int main() {
  f=fopen("alumnos.dat","w"); 
  if(f!=NULL){
    for(i=1; i<=2; i++) {
     printf("ingrese nombre: ");
     scanf("%s",nom);
     strcpy(alumno.nombre,nom);
     printf("ingrese edad: ");
     scanf("%d",&alumno.edad);
     fwrite(&alumno,sizeof(alumno),1,f);
     getchar();
    } 
  };
  fclose(f);
  return 0; 
}
