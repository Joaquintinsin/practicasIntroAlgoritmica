#include "aritmetica.h" // Incluye la interfaz a implementar

// seccion de IMPLEMENTACION (declaraciones privadas)
// a continuacion se implementan las funciones que podrán ser utilizadas desde los programas que incluyan a la biblioteca aritmetica
// también pueden agregarse otras funtion auxiliares, las cuales no serán vistas ni podrán ser utilizadas por otros programas

int esPar(int n){
  if (n%2==0) { // % es el operador módulo, el resto de la división entera (mod)
    return 1; // algo distinto de 0 es verdadero
  } else {
    return 0; // 0 es falso
  }
}

int factorial(int n){
  int res=1;
  while(n>1){
    res=res*n;
    n--;
  }
  return res;
}

