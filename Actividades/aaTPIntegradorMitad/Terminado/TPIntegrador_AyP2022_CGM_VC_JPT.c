/* Intr. a la algorítmica y programación
 * Trabajo práctico integrador de mitad de año: 2022
 * Integrantes: Celina Gillo Mayer, Valentín Cardozo, Joaquín Pablo Tissera
 */

#include <stdio.h>
#include <string.h>

#define AMax 1000		// Constante límite para la lista
#define MaxCaract 50	// Constante auxiliar para representar las cadenas (máximo 50 caractéres)

// Tipo cadena; arreglo de caractéres
typedef struct{
    char apellido[MaxCaract];
} TCadena;

// Tipo registro; el campo cant refiere a la cantidad actual de componentes del arreglo, el campo arreglo corresponde a un arreglo de cadenas
// Accedemos a los apellidos con <variable de tipo TData>.arreglo[<índice>].apellido
typedef struct{
    TCadena arreglo[AMax];
    int cant;
} TData;

// Declaración de Funciones
int Vacia(TData arr);															// Función Vacia (dato arr ϵ TData) → Lógico
int Llena(TData arr);															// Función Llena (dato arr ϵ TData) → Lógico
void InsertarApellido(char apellido[MaxCaract], TData* empleados);				// Acción InsertarApellido (dato apellido ϵ Cadena, dato/resultado empleados ϵ TData)
void SuprimirApellido(char apellidoModulo[MaxCaract], TData* arr);				// Acción SuprimirApellido (dato apellido ϵ Cadena, dato/resultado empleados ϵ TData)
void MostrarApellidos(TData arr);												// Acción MostrarApellidos (dato arr ϵ TData)
void ModificarApellido(int posicion, char apellidoViejo[MaxCaract], char apellidoNuevoMod[MaxCaract], TData* lista);	// Acción ModificarApellido (dato posicion є Z, apellidoViejo є Cadena, apellidoNuevoMod є Cadena, dato/resultado lista є TData)
int UbicarApellido(char apellido[MaxCaract], TData arr);						// Función UbicarApellido (dato apellido є Cadena, arr є TData) → Z
int ApellidosRepetidos(char apellido1[MaxCaract], char apellido2[MaxCaract]);	// Función ApellidosRepetidos (dato apellido1, apellido2 є Cadena) → Lógico
void DesplegarMenuDeOpciones();													// Acción DesplegarMenuDeOpciones ()
void DefensivaEntrada(int *entr);												// Acción DefensivaEntrada(dato/resultado entr ϵ Z)

int main(){
	TData nominaEmpleados;				// Variable almacenador de la nómina
	int opcionEntry;					// Entrada y selector del menú
	char apellidoNuevo[MaxCaract];
	char bajaDeApellido[MaxCaract];
	char apellidoModificarViejo[MaxCaract];
	char apellidoModificarNuevo[MaxCaract];
	char apellidoBuscar[MaxCaract];
	int auxRepetido;					// Auxiliar/flag Lógico
	int posicionArreglo;				// Auxiliar Entero
	int i;
	
	// Inicialización de variables
	opcionEntry = 0;
	nominaEmpleados.cant = 0;
	auxRepetido = 0;
	
	do{		// Repetir ... Hasta que (opcionEntry = 6)
		DesplegarMenuDeOpciones();
		scanf ("%d", &opcionEntry);		// Entrada de la opcion (del 1 al 6)
		DefensivaEntrada(&opcionEntry);
		
		if ( opcionEntry == 1 ){
			printf ("Opción 1: Dar de alta un empleado \n");
			if ( Llena(nominaEmpleados) ){
				printf ("No se puede agregar, la lista está llena \n");
			}else{
				printf ("Ingrese el apellido del nuevo empleado: ");
				scanf ("%s", apellidoNuevo);
				
				for ( i = 0 ; i < nominaEmpleados.cant ; i++ ){		// Recorre el arreglo buscando si ya hay un apellido igual
					auxRepetido = ApellidosRepetidos(apellidoNuevo,nominaEmpleados.arreglo[i].apellido);
				}
				
				if ( auxRepetido ){		// No debe haber apellido repetidos
					printf ("ERROR. El apellido ya existe. \n");
				}else{
					InsertarApellido(apellidoNuevo,&nominaEmpleados);
					printf ("Alta del empleado ' %s ' exitosa. \n", apellidoNuevo);
				}
			}
		}
		
		if ( opcionEntry == 2 ){
			printf ("Opción 2: Dar de baja un empleado \n");
			if ( Vacia(nominaEmpleados) ){
				printf ("La nómina está vacía. \n");
			}else{
				printf ("Ingrese el apellido del empleado a dar de baja: ");
				scanf ("%s", bajaDeApellido);
				
				posicionArreglo = UbicarApellido(bajaDeApellido, nominaEmpleados);	// Guarda la ubicación del apellido si es que existe. Si no existe, la función devolverá -1
				
				if ( posicionArreglo == -1 ){
					printf ("ERROR. El apellido no existe. \n");
				}else{
					SuprimirApellido(bajaDeApellido, &nominaEmpleados);
				}
			}
		}
		
		if ( opcionEntry == 3 ){
			printf ("Opción 3: Modificar apellido \n");
			if ( Vacia(nominaEmpleados) ){
				printf ("La nómina está vacía. \n");
			}else{
				printf ("Ingrese el apellido del empleado que quiere modificar: ");
				scanf ("%s", apellidoModificarViejo);
				
				posicionArreglo = UbicarApellido(apellidoModificarViejo, nominaEmpleados);	// Guarda la ubicación del apellido si es que existe. Si no existe, la función devolverá -1
				
				if ( posicionArreglo == -1 ){	// Si es -1 es que no encontró el apellido.
					printf ("ERROR. No hay coincidencia de apellidos. \n");
				}else{
					printf ("Va a cambiar el apellido ' %s ' \n", apellidoModificarViejo);
					printf ("Ingrese el nuevo apellido: ");
					scanf ("%s", apellidoModificarNuevo);
					ModificarApellido(posicionArreglo, apellidoModificarViejo, apellidoModificarNuevo, &nominaEmpleados);
				}
			}
		}
		
		if ( opcionEntry == 4 ){
			printf ("Opción 4: Listar empleados \n");
			if ( Vacia(nominaEmpleados) ){
				printf ("La nómina está vacía. \n");
			}else{
				MostrarApellidos(nominaEmpleados);
			}
		}
		
		if ( opcionEntry == 5 ){
			printf ("Opción 5: Buscar un empleado \n");
			if ( Vacia(nominaEmpleados) ){
				printf ("La nómina está vacía. \n");
			}else{
				printf ("Escriba el apellido que quiere buscar: ");
				scanf ("%s", apellidoBuscar);
				
				posicionArreglo = UbicarApellido(apellidoBuscar, nominaEmpleados);
				
				if ( posicionArreglo == -1 ){
					printf ("El apellido '%s' no está en la nómina. \n", apellidoBuscar);
				}else{
					printf ("El apellido '%s' está en la lista. \n", nominaEmpleados.arreglo[posicionArreglo].apellido);
					printf ("Además, corresponde a la posición %d \n", posicionArreglo);
				}
			}
		}
		
		if ( opcionEntry == 6 ){
			printf ("Opción 6: Salir \n");
		}
		
	} while ( !( opcionEntry == 6 ) );
	
	printf ("Salida exitosa. \n");
	return 0;
}

void DesplegarMenuDeOpciones(){
	printf ("\n");
	printf ("· Menú principal");
	printf ("\n");
	printf ("Seleccione una opción para continuar: \n");
	printf ("\t 1. Dar de alta un empleado (por apellido) \n");
	printf ("\t 2. Dar de baja un empleado (buscando por apellido) \n");
	printf ("\t 3. Modificar apellido \n");
	printf ("\t 4. Listar empleados \n");
	printf ("\t 5. Buscar un empleado (por apellido) \n");
	printf ("\t 6. Salir \n");
}

void DefensivaEntrada(int *entr){	// Resguardo contra negativos o mayores a 6. Si se ingresa una letra se rompe el programa.
	if ( *entr < 1 || *entr > 6 ){
		do{
			printf ("Debe ingresar un digito del 1 al 6 \n");
			scanf ("%d", entr);
		}while ( *entr < 1 || *entr > 6 );
	}
}

int Vacia(TData arr){
	if ( arr.cant == 0 ){
		return 1;
	}else{
		return 0;
	}
}

int Llena(TData arr){
	if ( arr.cant == AMax ){
		return 1;
	}else{
		return 0;
	}
}

void InsertarApellido(char apellidoModulo[MaxCaract], TData* empleados){
	strcpy(empleados->arreglo[empleados->cant].apellido , apellidoModulo);
	empleados->cant = empleados->cant + 1;
}

void SuprimirApellido(char apellidoModulo[MaxCaract], TData* empleados){
	int i, j;
	char rta[MaxCaract];
	
	i = 0;

	printf ("Desea dar de baja el empleado ' %s ' ? Ingrese 'Si' o 'No': ", apellidoModulo);
	scanf ("%s", rta);
	if ( (strcmp(rta,"Si") == 0) || (strcmp(rta,"si") == 0) ){
		while ( i < empleados->cant ){
			if ( strcmp(apellidoModulo , empleados->arreglo[i].apellido) == 0 ){
				for ( j = i ; j < empleados->cant ; j++ ){
					empleados->arreglo[j] = empleados->arreglo[j+1];
				}
				empleados->cant--;
			}
			i++;
		}
		printf ("Baja del empleado ' %s ' exitosa. \n", apellidoModulo);
	}else{
		printf ("Volviendo al menú principal \n");
	}
}

void ModificarApellido(int posicion, char apellidoViejo[MaxCaract], char apellidoNuevoMod[MaxCaract], TData* lista){
	int auxPosicion;

	if ( strcmp(apellidoViejo, apellidoNuevoMod) == 0 ){	// Si se quiere modificar un apellido por el mismo no hace la modificación y avisa que es el mismo.
		printf ("La modificación del apellido debe ser distinta al que se quiere modificar. \n");
	}else{
		auxPosicion = UbicarApellido(apellidoNuevoMod, *lista);	// Guardo la ubicación del apellido si es que existe. Si no existe, la función devolverá -1

		if ( auxPosicion == -1 ){	// Siempre y cuando no se haya ubicado ningún apellido, lo podremos modificar.
			strcpy(lista->arreglo[posicion].apellido, apellidoNuevoMod);				
			printf ("Modificación exitosa. \n");
		}else{						// Si se encuentra que hay alguno, entonces no podemos poner apellidos repetidos.
			printf ("ERROR. El apellido no se puede modificar por uno que ya existe. \n");
		}
	}
}

void MostrarApellidos(TData arr){
	int i;

	printf ("\t Inicio de la nómina de empleados... \n");
	for ( i = 0 ; i < arr.cant ; i++ ){
		printf("Apellido nro %d es: %s \n", i, arr.arreglo[i].apellido);
	}
	printf ("\t Fin de la nómina de empleados... \n");
}

int UbicarApellido(char apellido[MaxCaract], TData arr){
	int i;

	for ( i = 0 ; i < arr.cant ; i++ ){
		if ( strcmp(apellido,arr.arreglo[i].apellido) == 0 ){
			return i;
		}
	}

	return -1;	// Si devuelve -1 es porque no hay coincidencia.
}

int ApellidosRepetidos(char apellido1[MaxCaract], char apellido2[MaxCaract]){
	if ( strcmp(apellido1,apellido2) == 0 ){
		return 1;
	}else{
		return 0;
	}
}
