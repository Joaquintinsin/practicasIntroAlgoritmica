#include <stdio.h>

void Calculadora(float n1, char ch, float n2, float *res);
void ObtenerDatos(float *x, char *c, float *y);

int main(){
	char car;	// dato. caracter que indica la operacion de la calculadora
	float num1;	// dato. primer numero para operar
	float num2;	// dato. segundo numero para operar
	float resultado;// resultado. se almacena el resultado de operar el primer numero con el segundo numero

	ObtenerDatos(&num1,&car,&num2);
	Calculadora(num1,car,num2,&resultado);
	printf("El resultado de la calculadora es %f \n",resultado);
	return 0;
}

void ObtenerDatos(float *x, char *c, float *y){
	printf("Ingresar el primer valor \n");
	scanf("%f", x);
	do{
		printf("Ingresar +, -, *, o / \n");
		scanf("%s", c);
	} while ( *c != '+' && *c != '-' && *c != '*' && *c != '/' );
	printf("Ingresar el segundo valor \n");
	scanf("%f", y);
}

void Calculadora(float n1, char ch, float n2, float *res){
	if ( ch == '/' && n2 == 0 ){
		printf("ERROR\n");
		*res = 999999;
	}else{
		if ( ch == '+' ){
			*res = n1 + n2;
		}else{
			if ( ch == '-' ){
				*res = n1 - n2;
			}else{
				if ( ch == '/' ){
					*res = n1 / n2;
				}else{
					*res = n1 * n2;
				}
			}
		}
	}
}

