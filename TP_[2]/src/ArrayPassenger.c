#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "Input.h"
#define TRUE 0
#define FALSE -1
#define PASAJEROS 2000
#define ACTIVO 1
#define CANCELADO 2
#define DEMORADO 3
int initPassengers(Passenger* list, int len){
    int status;
    int i;

    status = FALSE;

    if(list != NULL && len > 0)//valida que el array exista y no se encuentre vacio
    {
    	status = TRUE; //bien

    	for (i = 0; i < len; i++)
    	{
    		list[i].isEmpty = TRUE;
    	}
    }
	return status;
}
/*
int BuscarEspacioLibre(Passenger* list, int len, int*index){
	int status;
	int indexLibre;
	int i;

	status = FALSE;

	for(i = 0; i < len; i++){
	     if(list[i].isEmpty == TRUE){
	    	 indexLibre = i;
	    	 *index = indexLibre;
	    	 status = TRUE;
	    	 break;
	     }
	}
	return status;
} */

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flyCode[])
{
	int status;
	int i;

	status = FALSE;

	if(list != NULL && len > 0 && name != NULL && lastName != NULL && price >= 0 && typePassenger >= 0 && flyCode >= 0)
	    {
	    	for (i = 0; i < len; i++)
	    	{
	    		if(list[i].isEmpty == TRUE){
	    			list[i].isEmpty = FALSE;
	    			list[i].id = id;
	    			strcpy(list[i].name, name);
	    			strcpy(list[i].lastName, lastName);
                    list[i].price = price;
                    strcpy(list[i].flyCode, flyCode);
                    list[i].typePassenger = typePassenger;
                    list[i].statusFlight = ACTIVO;
                    status = TRUE;
                    break;

	    		}
	    	}
	    }

return status;
}

int findPassengerById(Passenger* list, int len, int id)
{
	int status;
	int i;

	status = FALSE;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].id == id)
			{
				status = i;
		    }
	    }
	}

return status;
}

int modifyPassenger(Passenger* list, int len, int id)
{
	int status;
	int option;
	int idRemove;

	status = FALSE;

	if(list != NULL && len > 0 && id != FALSE){
		idRemove = findPassengerById(list, len, id);
		puts("---------------------------------------");
		puts("¿Que desea modificar?");
		puts("1. Nombre");
		puts("2. Apellido");
		puts("3. Precio");
		puts("4. Codigo de vuelo");
		puts("5. Tipo de pasajero");
		IngresoEnteroMinMax(&option,"", "Error, vuelva a ingresar un dato valido: ",1,5);
		if(idRemove != FALSE){
			switch(option){
			case 1:
				getString(list[idRemove].name, "Ingrese el nuevo nombre por favor: ",51);
				break;

			case 2:
				getString(list[idRemove].lastName, "Ingrese el nuevo apellido por favor: ",51);
                break;

			case 3:
                list[idRemove].price = IngresarFlotante("Ingrese el nuevo precio por favor: ", 0, 300000);
                while(list[idRemove].price < 0)
			    {
                	list[idRemove].price = IngresarFlotante("El precio no puede ser negativo, reingrese el nuevo precio por favor: ", 0, 300000);
                }
                break;

			case 4:
                getString(list[idRemove].flyCode, "Ingrese el nuevo codigo de vuelo por favor: ",10);
                break;

			case 5:
                list[idRemove].typePassenger = IngresarEntero("Ingrese el nuevo tipo de pasajero por favor(1, 2 o 3): ", 1, 3);
                break;

			}
			status = TRUE;
		}
	}
return status;
}

int removePassenger(Passenger* list, int len, int id){
	int status;
	int idModify;

	status = FALSE;

	if(list != NULL && len > 0 && id != FALSE){
		idModify = findPassengerById(list, len, id);
		if(idModify != FALSE){
			list[idModify].isEmpty = TRUE;
			status = TRUE;
		}
	}
	return status;
}


int sortPassengers(Passenger* list, int len, int order)
{
	int status;
	int i;
	int j;

	status = FALSE;

	Passenger listaAux;

	if(list != NULL && len > 0)
	{

		status = TRUE;
		if(order == 1)
		{
			for(i = 0; i < len; i++)
			{

				for(j = i+1; j < len; j++)
				{
					if((strcmp(list[i].lastName, list[j].lastName) > 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE))
					{
						listaAux = list[i];
						list[i] = list[j];
						list[j] = listaAux;
					}
					else
					{
						if((strcmp(list[i].lastName, list[j].lastName) == 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE))
						{
							if(list[i].typePassenger > list[j].typePassenger)
							{
								listaAux = list[i];
								list[i] = list[j];
								list[j] = listaAux;
							}
						}
					}
				}
			}
		}
		else
		{
		  for(i=0; i < len; i++)
		  {
			 for(j = i+1; j < len; j++)
			 {
			   if((strcmp(list[i].lastName, list[j].lastName)< 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE))
			   {

				listaAux = list[i];
				list[i] = list[j];
				list[j] = listaAux;
			}
			else
			{
				if((strcmp(list[i].lastName, list[j].lastName) == 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE))
				{

				   if(list[i].typePassenger > list[j].typePassenger)
				   {

				       listaAux = list[i];
				       list[i] = list[j];
				       list[j] = listaAux;
				   }
				}
			}
		  }
		 }
		}
	}
return status;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
	int status;
	int i;

	status = FALSE;
	Passenger listaAuxiliar;

	if(list != NULL && len > 0)
	{

		status = TRUE;
		if(order == 1)
		{
			for(i = 0; i < len; i++)
			{
					if(stricmp(list[i].flyCode, list[i+1].flyCode) > 0)
					{
						listaAuxiliar = list[i];
						list[i] = list[i+1];
						list[i+1] = listaAuxiliar;
					}
					else
					{
						if(stricmp(list[i].flyCode, list[i+1].flyCode) < 0)
						{

								listaAuxiliar = list[i];
								list[i] = list[i+1];
								list[i+1] = listaAuxiliar;

						}
					}
				}
		}
		status = TRUE;
	}

	return status;
}

int printActivePassenger(Passenger* list, int len){
	int i;
	int status;
	status = FALSE;

	if(list != NULL && len > 0){
		printf("ID\t--\tNombre\t--\tApellido\t--\tPrecio\t--\tCodigo\t--\tTipo\t--\tEstado\n");
		for(i = 0; i < len; i++){
			if(list[i].isEmpty == FALSE && list[i].statusFlight == ACTIVO){
				printf("%d", list[i].id);
				printf("%20s", list[i].name);
				printf("%20s", list[i].lastName);
				printf("%20.2f", list[i].price);
				printf("%20s", list[i].flyCode);
				printf("%10d", list[i].typePassenger);
				printf("%10d", list[i].statusFlight);
			}
		}
		status = TRUE;
	}

	return status;
}


int printPassenger(Passenger* list, int length)
{
	int status;
	int i;

	status = FALSE;

	if(list != NULL && length >0){
		status = TRUE;
		puts("----------------------------");
		for(i = 0; i < length; i++){
			if(list[i].isEmpty == FALSE){
				printf("ID: %d || %s,  %s || Precio: %.2f || Codigo Pasajero: %s || Tipo de Pasajero:  %d\n", list[i].id, list[i].name, list[i].lastName, list[i].price, list[i].flyCode, list[i].typePassenger);
			}
		}
		puts("----------------------------");
	}

return status;
}

int promedioPassengers(Passenger* list, int len){
	int status;
	int i;
	float acumulador;
	int contador;
	float promedio;
	int contadorPromedioConPrecioMasAlto;

	status = FALSE;
	promedio = 0;
	acumulador = 0;
	contador = 0;
	contadorPromedioConPrecioMasAlto = 0;

	if(list != NULL && len > 0){
		for(i = 0; i < len; i++){
			if(list[i].isEmpty == FALSE){
				acumulador += list[i].price;
				contador++;
			}
		}
		promedio = acumulador/contador;

		for(i = 0; i < len; i++){
			if(list[i].isEmpty == FALSE && list[i].price > promedio){
			    contadorPromedioConPrecioMasAlto++;
			}
		}
		puts("----------------------------");
		printf("Costo total de pasajes: $ %.2f\n", acumulador);
		printf("Promedio: $ %.2f\n", promedio);
		printf("Pasajeros que superan el promedio: %d\n", contadorPromedioConPrecioMasAlto);
		puts("----------------------------");

		status = TRUE;
	}

	return status;
}

int cargaForzadaPassenger(Passenger* list, int len, int* id){
	int status;
	status = FALSE;

	if(list != NULL && len > 0){
		if(addPassenger(list, len, *id, "Macarena","Abelleira", 30000, 1, "MA345") == TRUE &&
				addPassenger(list, len, *id+1, "Ailin","Perez", 35000, 1, "MA560") == TRUE &&
				addPassenger(list, len, *id+2, "Ramiro","Cortez", 40000, 1, "SI607") == TRUE &&
				addPassenger(list, len, *id+3, "Juan Carlos","Chup", 35000, 1, "SI678") == TRUE &&
				addPassenger(list, len, *id+4, "Susana","Gimenez", 30000, 1, "SI667") == TRUE)
		{
			 *id += 5;
			 status = TRUE;
		}
	 }
	return status;
}


