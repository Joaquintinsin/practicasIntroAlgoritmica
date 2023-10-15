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
char car;
int i;
FILE* archivo;

int main(){
    archivo = fopen("test.txt","w");
    if(archivo!=NULL){
       for(i=1; i<=20; i++) {
         printf("ingrese un caracter: ");
         scanf("%c",&car);
         fputc(car,archivo);
         getchar();
       }; 
       fclose(archivo);
    }
    return 0;
}
