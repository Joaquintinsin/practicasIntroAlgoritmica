// Copyright (C) 2018 Ariel Ferreira Szpiniak <aferreira@exa.unrc.edu.ar>
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.

#include <stdio.h>
/* léxico */
int lado; 
int areaCuad;

/* función principal (main) en todo programa C */
int main(){
  scanf("%d",&lado); // dir de memoria de la var lado
  areaCuad = lado * lado;
  printf("%d",areaCuad );
/* otra forma: printf("El area es: %d \n",areaCuad );*/
  return 0;
}
