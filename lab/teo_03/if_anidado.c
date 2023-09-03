#include <stdio.h>

int  num;     //variable para almacenar el numero a analizar

int main(){
	printf("Ingrese un numero entero: ");
	scanf("%d",&num);
	if (num>=50){		//num es mayor o igual que 50
		printf("%d es mayor o igual que 50 \n", num);
	}else{ 				//num es menor que 50
		if (num<=10){	//num es menor que 50 y menor o igual que 10
			printf("%d es menor o igual que 10 \n", num);
		}else{ 			//num es menor que 50 y mayor que 10
			printf("%d está entre 10 y 50 \n", num);
		}
	}
	printf("Muchas gracias! \n");
	return 0;
}
