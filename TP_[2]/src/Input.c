#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "input.h"
#define TRUE 1
#define FALSE 0
#define PASAJEROS 2000
float IngresarFlotante(char mensaje[], int desde, int hasta)
{
	  int respuesta;
	  printf("%s", mensaje);

	    scanf("%d", &respuesta);
	    while(respuesta < desde || respuesta > hasta)
	    {

	    printf("Error, reingrese el dato por favor: ");

	    scanf("%d", &respuesta);
	    }

	    return respuesta;
}

int IngresarEntero(char mensaje[], int desde, int hasta){
    int respuesta;
    printf("%s", mensaje);

    scanf("%d", &respuesta);
    while(respuesta < desde || respuesta > hasta)
    {

    printf("Error, reingrese el dato por favor: ");

    scanf("%d", &respuesta);
    }

    return respuesta;
}


int getString(char cadena[], char mensaje[], int tam)
{
	char auxiliarString[1000];
	int retorno;
	retorno = 0;
	if (cadena != NULL && mensaje != NULL)
	{
		retorno = 1;
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]", auxiliarString);

		while (strlen(auxiliarString) > tam)
		{
			printf("Reingrese: ");
			fflush(stdin);
			scanf("%[^\n]", auxiliarString);
		}
		strcpy(cadena, auxiliarString);
	}
	return retorno;
}
int ValidarEntero(char* ingreso){
	int status;
	int i;
	status = TRUE;
	if(strlen(ingreso)>0){
		for(i = 0; i < strlen(ingreso);i++){
			if(isdigit(ingreso[i]) == FALSE){
				if(i == 0){
					if(ingreso[0] != '-'){
						status = FALSE;
						break;
					}
				}
				else{
					status = 0;
				}
			}
		}
	}
	else{
		status = FALSE;
	}
	return status;
}

int IngresoEnteroMinMax(int* ingreso, char* mensaje, char* errorTexto, int min, int max){
	char buffer[1000];
	int status;
	status = FALSE;
	if(ingreso != NULL && mensaje != NULL && errorTexto != NULL && min < max){
		printf("%s", mensaje);
		fflush(stdin);
		gets(buffer);
		while(ValidarEntero(buffer) == FALSE || atoi(buffer) > max || atoi(buffer) < min){
			printf("%s", errorTexto);
			fflush(stdin);
			gets(buffer);
		}
		*ingreso = atoi(buffer);
		 status = TRUE;
	}
	return status;
}
