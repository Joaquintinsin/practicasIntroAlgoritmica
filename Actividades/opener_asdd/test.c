#include <stdio.h>

int main(int argc, char **argv){
	FILE* f;
	char display;
	
	f = fopen("asDD.txt", "r");
	
	// extracción de caracteres
    while (1) {
        // capturador
        display = fgetc(f);
        
		// llega al final
        if (feof(f)){
			break;
        }
        
        // muestra cada caracter
        printf("%c", display);
    }
	
	fclose(f);
	
	return 0;
}
