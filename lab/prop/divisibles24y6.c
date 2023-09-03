#include <stdio.h>

int main(){

	int i;

	i = 0;

	do{
		i++;
		if ( i%2 == 0 ){
			printf("%d es divisible por dos. \n", i);
		}
		if ( i%4 == 0 ){
			printf("%d es divisible por cuatro. \n", i);
		}
		if ( i%6 == 0 ){
			printf("%d es divisible por seis. \n", i);
		}
	} while ( i < 100 );
	return 0;
}

