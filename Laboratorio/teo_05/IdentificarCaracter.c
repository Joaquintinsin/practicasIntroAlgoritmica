#include <stdio.h>
// para que el codigo sea mas legible, cuando hay varias funciones, se estila colocar solo  
// los perfiles aquí, a modo de lexico global, y luego del main la implementacion de cada una.
char letra;
int esMayuscula(char c);// primera versión usando variable local
int esMayuscula2(char c);// segunda versión sin variable local
int esMayuscula3(char c);// tercera versión sin variable local y sin if
char aMinuscula(char c);
int esVocal(char c);

int main(){
  printf("\n Ingrese caracter: ");
  scanf("%c",&letra);
  
  if (esMayuscula(letra)){
      printf("\n El caracter ingresado (%c) es una mayuscula", letra);
  }else{
      printf("\n El caracter ingresado (%c) es una minuscula", letra);  
  }
  if (esVocal(letra)){
      printf("\n El caracter ingresado (%c) es una vocal", letra);
  }else{
      printf("\n El caracter ingresado (%c) NO es una vocal", letra);  
  }
  
  
  if (esMayuscula2(letra)){
      printf("\n El caracter ingresado (%c) es una mayuscula", letra);
  }else{
      printf("\n El caracter ingresado (%c) es una minuscula", letra);  
  }
  if (esVocal(letra)){
      printf("\n El caracter ingresado (%c) es una vocal", letra);
  }else{
      printf("\n El caracter ingresado (%c) NO es una vocal", letra);  
  }
  
  
  if (esMayuscula3(letra)){
      printf("\n El caracter ingresado (%c) es una mayuscula", letra);
  }else{
      printf("\n El caracter ingresado (%c) es una minuscula", letra);  
  }
  if (esVocal(letra)){
      printf("\n El caracter ingresado (%c) es una vocal", letra);
  }else{
      printf("\n El caracter ingresado (%c) NO es una vocal", letra);  
  }
  
  
  return 0;
}
// fin del main
// implementacion completa de cada una funcion mencionada en el lexico global.
int esMayuscula(char c){
int aux;    
  if ((c >= 'A') && (c <= 'Z')){
    aux=1;
  }else{
    aux=0;
  }
  return (aux);
}

int esMayuscula2(char c){
  if ((c >= 'A') && (c <= 'Z')){
    return(1);
  }else{
    return (0);
  }
}

int esMayuscula3(char c){
  return ((c >= 'A') && (c <= 'Z'));
}

char aMinuscula(char c){
// si un caracter esta comprendido entre A y Z, se le suma la diferencia entre los ASCII de las minúsculas 
// y las mayúsculas ( 97 - 65 = 32 ) para a minuscula
  return (c + ('a'-'A'));
}

int esVocal(char c){
 char minus;
 if (esMayuscula(c)){
    minus = aMinuscula(c);
 }else{
	minus = c;
 }
 return ((minus == 'a') || (minus == 'e') || (minus == 'i') || (minus == 'o') || (minus == 'u')); 
}

