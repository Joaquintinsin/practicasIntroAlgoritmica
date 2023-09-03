// Swap
// Copyright (C) 2020 Ariel Ferreira Szpiniak, Guillermo A. Rojo <aferreira@exa.unrc.edu.ar> <grojo@exa.unrc.edu.ar>
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.

#include <stdio.h>
int a,b;
void Swap (int *x,int *y) {
    *x = (*x)+(*y);
    *y = (*x)-(*y);
    *x = (*x)-(*y);
}

int main()
{
printf("introduce el valor de la variable a ");
scanf("%i",&a);
printf("introduce el valor de la variable b ");
scanf("%i",&b);
Swap (&a, &b);
printf ("el valor de a es %d ", a);
printf ("el valor de b es %d ", b);
printf("\n introduce el valor de la variable a ");
scanf("%i",&a);
printf("introduce el valor de la variable b ");
scanf("%i",&b);
Swap (&a, &a);
printf ("el valor de a es %d ", a);
return 0;
}
