#include <stdio.h>
#include "aritmetica.h" 
// aritmetica.h va entre " " para indicarle al compilador que se trata de algo creador por el programador
// los < > se usan cuando se trata de un archivo propio del compilador (en este caso una librería).
int num;
int main()
{
  num=13;
  if (esPar(num)) { // 0 es falso
   printf("%i es par? Si\n", num);
  } else {
     printf("%i es par? No\n", num);
  } 
  num=0;
  printf("%i!=%i\n", 0, factorial(num));
  num=5;
  printf("%i!=%i\n", 5, factorial(num));
  num=7;
  printf("%i!=%i\n", 7, factorial(num));
  return 0;
}
