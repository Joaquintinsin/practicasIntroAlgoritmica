#include <stdio.h>
#include <string.h>
#include <time.h>

int main(){
	time_t t = time(NULL);
	struct tm *tm = localtime(&t);
	char hora[26], nomArch[25], extens[5];
	strftime(hora, sizeof(hora), "%c", tm);
	printf ("Ingresar el nombre del archivo para la copia de seguridad (sin el .dat).\nSe concatenará la hora en que se realizó luego del nombre.\n");
	scanf("%s", nomArch);
	strcat(nomArch, "_");
	strcat(nomArch, hora);
	strcat(extens, ".dat");
	strcat(nomArch, extens);
	printf ("nomArch final: %s \n", nomArch);
	return 0;
}
