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
char c;
FILE* archivo;
    
int main(){
    archivo = fopen("test.txt","r");
    if(archivo!=NULL){
	    while(fscanf(archivo,"%c",&c)!=EOF) 
            printf("%c",c);
        fclose(archivo);
    }
    return 0; 
}
