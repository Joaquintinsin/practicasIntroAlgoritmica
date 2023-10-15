#include <stdio.h>
#include <string.h>

void PedirUsuario(char *a);
void CrearContrasenia(char* a[50]);

int main() {
	char username[100];
	char password[50];
	PedirUsuario(username);
	CrearContrasenia(&password);
		// printf("%s", password);	// Imprime cualquier cosa (la primer letra solamente); la contraseña no se está guardando correctamente
	return 0;
}

void PedirUsuario(char *a){
	printf("Ingrese un nombre de usuario: ");
	scanf("%s", a);
	printf("\n·	El nombre de usuario ingresado es: %s \n", a);
}

void CrearContrasenia(char* a[50]){	// Accion CrearContrasenia(resultado a e Cadena)
	char aux[50];			// almacenador de contraseña 1
	char aux2[50];			// almacenador de contraseña 2
	int alma;				// almacenador booleano del casteo de EsLetra
	int i;					// iterador
	int aux3 = 3;			// minimo de 3 letras iniciales
	int EsLetra(char ch){	// Funcion EsLetra(dato ch e Caracter) → (0,1)
		int EsMayuscula(char c){	// Funcion EsMayuscula(dato c e Caracter) → (0,1)
			if ( c >= 'A' && c <= 'Z' ){
				return 1;
			}else{
				return 0;
			}
		}
		int EsMinuscula(char c){	// Funcion EsMinuscula(dato c e Caracter) → (0,1)
			if ( c >= 'a' && c <= 'z' ){
				return 1;
			}else{
				return 0;
			}
		}
	  // Inicio de la Funcion EsLetra
		if ( EsMayuscula(ch) + EsMinuscula(ch) >= 1 ){	// si suma al menos 1, significa que una de las dos funciones devuelve 1. luego, es una letra minuscula o mayuscula. siendo al menos 1 verdadera, el caracter ingresado es letra, por lo tanto la funcion devuelve verdadero(1), en otro caso devuelve falso (0).
			return 1;	// EsLetra devuelve 1 si el parametro actual con el que se invoque es una letra, sino devuelve 0
		}else{
			return 0;
		}
	} // Fin Funcion EsLetra
	
	/* No funciona; debería dar límite a la contraseña...
	 * printf("De cuantos caracteres es su contraseña? \n");
	do{
		scanf("%d", &aux3);
	} while ( aux3 <= 0 );	// positivo distinto de cero deja de iterar. negativo o cero sigue iterando.
	*/
	
	// Inicio Accion CrearContrasenia
	printf("\nIngrese una contraseña. Debe empezar con 3 letras como mínimo: ");
	scanf("%s", aux );
	// *aux = *a;
	i = 0;
	do{
		alma = EsLetra(aux[i]);
		i++;
	} while ( i < aux3 && alma == 1 );	// Si la cond es verdadera, sigue iterando. Si es falsa, deja de iterar
	
	if ( alma == 0 ){	// si no tiene letras la contraseña pide entradas hasta q tenga al menos 1
		do{
			printf("\nNecesita poner 3 letras al inicio, vuelva a intentarlo: ");
			scanf("%s", aux );
			// *aux = *a;
			i = 0;
			do{
				alma = EsLetra(aux[i]);
				i++;
			} while ( i < aux3 && alma == 1 );
		} while ( alma == 0 );
	}
	
	printf("\nReingrese la contraseña para asegurar: ");
	scanf("%s", aux2 );
	while ( ( strcmp(aux, aux2) != 0 ) ){
		printf("\nLas contraseñas no coinciden. Vuelva a intentarlo: ");
		scanf("%s", aux2);
	}
	
	printf("\nContraseña creada con éxito! \n");
	*a = *aux;
}
