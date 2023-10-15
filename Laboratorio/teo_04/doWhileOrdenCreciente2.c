// ordenCreciente;
#include <stdio.h>

int num1, num2; //números a ordenar

int main(){
	printf("Ingrese el primer número "); 
	scanf("%d",&num1);
	do {
		printf("Ingrese otro diferente al primero "); 
		scanf("%d",&num2);
	} while (!(num1!=num2));
	
	if (num1<num2){
		printf("Primer numero: %d ",num1); 
		printf("Segundo número: %d ",num2);
	}else{ 
		printf("Segundo numero: %d ",num2); 
		printf("Primer numero: %d ",num1);
	}
	return 0;
}
