#include <stdio.h>

void PedirUsuario(char *a);
void CrearContrasenia(char *a);

int main( int argc, char **argv ) {
	char username[100];
	char password[50];
	PedirUsuario(username);
	CrearContrasenia(password);
	return 0;
}

void PedirUsuario(char *a){
	printf("Ingrese un nombre de usuario: ");
	scanf("%s", &(*a) );
	printf("\n");
	printf("El nombre de usuario ingresado es: %s \n", &(*a));
}

void CrearContrasenia(char *a){
	char aux[50];	// almacenador de contraseña 1
	char aux2[50];	// almacenador de contraseña 2
	printf("\n");
	printf("Ingrese una contraseña: ");
	scanf("%s", &(*a) );
	printf("\n");
	*aux = *a;
	
	printf("Reingrese la contraseña para asegurar: ");
	scanf("%s", aux2 );
	printf("\n");
	if ( *a != *aux2 ){
		do{
			printf("Las contraseñas no coinciden. Vuelva a intentarlo: ");
			scanf("%s", aux2);
			printf("\n");
		} while ( *aux2 != *a );
	}
	printf("Contraseña creada con éxito! \n");
}
