#include <stdio.h>	

int main(){
	float entry1, entry2;	// entradas
	int i;				// contador
	float alma;	// almacenador
	float res;		// resultado
	
	scanf ("%f", &entry1);
	scanf ("%f", &entry2);
	
	for ( i=0; i <= entry2; i++ ){
		alma = entry1 * entry1;
		res = alma+alma;
	}
	
	printf ("%f", res);
	
	return 0;
}
