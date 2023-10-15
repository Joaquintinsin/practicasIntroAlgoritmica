//ProSumEjemplo1
// Copyright (C) 2020 Ariel Ferreira Szpiniak <aferreira@exa.unrc.edu.ar>
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.

#include <stdio.h> 
float bb, cc, dd, pp;
void ProSum(float x, float z, float *w, float *prom){
  float a; 	

  x = x+1;
  a = (*w)*2;
  *w = x+z+(*w)+a;
  z = z/2;
  *prom = (*w)/4;
}

int main()
{
    dd=80;
    cc=3;
    bb=0;
    ProSum(dd,cc,&bb,&pp);
    printf("los valores de prosum son: %f %f \n",bb,pp);
    return 0;
}
