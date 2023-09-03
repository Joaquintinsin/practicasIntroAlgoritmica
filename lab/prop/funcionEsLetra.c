#include <stdio.h>

int EsLetra(char ch);

int main( int argc, char **argv ) {
	char letra;
	int alma;
	scanf("%c", &letra);
	alma = EsLetra(letra);
	printf("%d", alma);
	
	return 0;
}

int EsLetra(char ch){
	int EsMayuscula(char c){
		if ( c >= 'A' && c <= 'Z' ){
			return 1;
		}else{
			return 0;
		}
	}
	int EsMinuscula(char c){
		if ( c >= 'a' && c <= 'z' ){
			return 1;
		}else{
			return 0;
		}
	}
	
	if ( EsMayuscula(ch) + EsMinuscula(ch) >= 1 ){	// si suma al menos 1, significa que una de las dos funciones devuelve 1. por lo tanto, es una letra minuscula o mayuscula en su defecto. siendo al menos 1 verdadera, el caracter ingresado es letra, por lo tanto la funcion devuelve verdadero(1), en otro caso devuelve falso (0).
		return 1;
	}else{
		return 0;
	}
	
}

