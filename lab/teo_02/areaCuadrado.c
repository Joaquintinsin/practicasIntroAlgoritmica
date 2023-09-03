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
/* Variables globales */
int lado; 
int areaCuad;

int main(){
  scanf("%d",&lado);
  areaCuad = lado * lado;
  printf("El area es: %d \n",areaCuad );
  return 0;
}

