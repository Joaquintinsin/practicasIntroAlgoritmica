#include <stdio.h>
#include <string.h>

int lluvia;			// Dato de entrada
int max, min, mes;	// Auxiliares
int mesMax, mesMin;	// Resultado

int main(){
	max = 0;
	min = 99999;
	mes = 1;

	printf("Ingrese las precipitaciones desde enero hasta diciembre. \n");
	do{
		scanf("%d", &lluvia);
			
		if(lluvia >= max){
			max = lluvia;
			mesMax = mes;
		}
		if(lluvia < min){
			min = lluvia;
			mesMin = mes;
		}
		
		mes = mes + 1;
	} while (mes < 13);
	
	if(mesMin == 1){
		printf("El mes de menor precipitación fue Enero. \n");
	}else{
		if(mesMin == 2){
			printf("El mes de menor precipitación fue Febrero. \n");
		}else{
			if(mesMin == 3){
				printf("El mes de menor precipitación fue Marzo. \n");
			}else{
				if(mesMin == 4){
					printf("El mes de menor precipitación fue Abril. \n");
				}else{
					if(mesMin == 5){
						printf("El mes de menor precipitación fue Mayo. \n");
					}else{
						if(mesMin == 6){
							printf("El mes de menor precipitación fue Junio. \n");
						}else{
							if(mesMin == 7){
								printf("El mes de menor precipitación fue Julio. \n");
							}else{
								if(mesMin == 8){
									printf("El mes de menor precipitación fue Agosto. \n");
								}else{
									if(mesMin == 9){
										printf("El mes de menor precipitación fue Septiembre. \n");
									}else{
										if(mesMin == 10){
											printf("El mes de menor precipitación fue Octubre. \n");
										}else{
											if(mesMin == 11){
												printf("El mes de menor precipitación fue Noviembre. \n");
											}else{
												if(mesMin == 12){
													printf("El mes de menor precipitación fue Diciembre. \n");
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	if(mesMax == 1){
		printf("El mes de mayor precipitación fue Enero. \n");
	}else{
		if(mesMax == 2){
			printf("El mes de mayor precipitación fue Febrero. \n");
		}else{
			if(mesMax == 3){
				printf("El mes de mayor precipitación fue Marzo. \n");
			}else{
				if(mesMax == 4){
					printf("El mes de mayor precipitación fue Abril. \n");
				}else{
					if(mesMax == 5){
						printf("El mes de mayor precipitación fue Mayo. \n");
					}else{
						if(mesMax == 6){
							printf("El mes de mayor precipitación fue Junio. \n");
						}else{
							if(mesMax == 7){
								printf("El mes de mayor precipitación fue Julio. \n");
							}else{
								if(mesMax == 8){
									printf("El mes de mayor precipitación fue Agosto. \n");
								}else{
									if(mesMax == 9){
										printf("El mes de mayor precipitación fue Septiembre. \n");
									}else{
										if(mesMax == 10){
											printf("El mes de mayor precipitación fue Octubre. \n");
										}else{
											if(mesMax == 11){
												printf("El mes de mayor precipitación fue Noviembre. \n");
											}else{
												if(mesMax == 12){
													printf("El mes de mayor precipitación fue Diciembre. \n");
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}

