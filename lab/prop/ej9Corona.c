#include <stdio.h> 
#include <string.h>

int indicio;					// var aux, guarda 0, 1, 2 o 3 segun los sintomas dados
char respuesta[50]; 		// var resultado, informa el estado de salud.
char sint1[50];				// síntoma 1
char sint2[50];				// síntoma 2
char sint3[50];				// síntoma 3
char sint4[50];				// síntoma 4
char sint5[50];				// síntoma 5

int main(){
    printf("Ingrese 'tos' si tiene tos u otra cosa en caso de que no. \n");
    scanf("%s",sint1);
	printf("Ingrese 'estornudo' si tiene estornudos, sino ingrese otra cosa. \n");
    scanf("%s",sint2);
	printf("Ingrese 'fiebre' si tiene fiebre, sino ingrese otra cosa. \n");
    scanf("%s",sint3);
	printf("Ingrese 'moco' si tiene mocos, sino ingrese otra cosa. \n");
    scanf("%s",sint4);
	printf("Ingrese 'flema', 'vomito' o 'congestion' si posee uno y solo uno de los sintomas, sino ingrese otra cosa. \n");
    scanf("%s",sint5);
	
	if(strcmp(sint1,"tos")==0){
        indicio = 1;
    }else{
        indicio = 0;
    }
    
    if(strcmp(sint2,"estornudo")!=0){
        if(strcmp(sint3,"fiebre")!=0){
			indicio = 0;
		}else{
			indicio = 1;
		}
    }else{
        if(strcmp(sint4,"moco")==0){
			if(strcmp(sint3,"fiebre")!=0){
				indicio = 0;
			}else{
				indicio = 2;
			}
		}else{
			indicio = 3;
		}
    }
    
    if( (indicio == 1) && (strcmp(sint5,"flema")==0) ){
        strcpy(respuesta,"Coronavirus. \n");
    }else{
        if( (indicio == 2) && (strcmp(sint5,"vomito")==0) ){
			strcpy(respuesta,"Gripe. \n");
		}else{
			if( (indicio == 3) && (strcmp(sint5,"congestion")==0) ){
				strcpy(respuesta,"Resfrio. \n");
			}else{
				strcpy(respuesta,"Hasta ahora parece no estar enfermo. \n");
			}
		}
	}

	printf("%s",respuesta);
	
	return 0;
}
