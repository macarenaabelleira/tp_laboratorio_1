/*
Macarena Abelleira. Div: 1-F

Una aerol�nea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
no puede tener m�s de 2000 pasajeros:

El sistema deber� tener el siguiente men� de opciones:

1. ALTAS: Se debe permitir ingresar un pasajero calculando autom�ticamente el
n�mero de Id. El resto de los campos se le pedir� al usuario.

2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
o Precio o Tipo de pasajero o C�digo de vuelo

3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.

4. INFORMAR:
   1. Listado de los pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero.
   2. Total y promedio de los precios de los pasajes, y cu�ntos pasajeros superan el precio
   promedio.
   3. Listado de los pasajeros por C�digo de vuelo y estados de vuelos �ACTIVO�


1-NOTA: Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de alg�n pasajero.

2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.


Para la realizaci�n de este programa, se utilizar� una biblioteca llamada �ArrayPassenger� que
facilitar� el manejo de la lista de pasajeros y su modificaci�n. En la secci�n siguiente se
detallan las funciones que esta biblioteca debe tener.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "Input.h"
#define TRUE 0
#define FALSE -1
#define ACTIVO 1
#define CANCELADO 2
#define DEMORADO 3
#define PASAJEROS 2000
int main(void) {
	setbuf(stdout, NULL);

	int opcion;
    int contadorPasajeros;
    int newId = 1;
    char newName[51];
    char newLastName[51];
    float newPrice;
    char newFlyCode[10];
    int newTypePassenger;
    int idFounded;
    int opcionMenuInformes;

    contadorPasajeros = 0;

    Passenger passenger[PASAJEROS];

    initPassengers(passenger, PASAJEROS);

	do{
		    puts("----------------------------");
			printf("1. Alta\n");
			printf("2. Modificar\n");
			printf("3. Baja\n");
			printf("4. Informar\n");
			printf("5. Carga Forzada Pasajeros\n");
			printf("6. Salir\n");
			puts("----------------------------");
            fflush(stdin);
			IngresoEnteroMinMax(&opcion,"elija una opcion\n", "Error, vuelva a elegir una opcion valida por favor: ",1,6);
			switch (opcion){
			case 1:

				if(contadorPasajeros < PASAJEROS){
					getString(newName, "Ingrese el nombre: ",51);
					getString(newLastName, "Ingrese el apellido: ",51);
					newPrice = IngresarFlotante("Ingrese el precio: ", 0, 300000);
				    while(newPrice < 0){
					newPrice = IngresarFlotante("Ingrese un precio en positivo por favor: ", 0, 300000);
				    }
				    getString(newFlyCode, "Ingrese el codigo de vuelo por favor: ",10);
				    newTypePassenger = IngresarEntero("Ingrese el tipo de pasajero por favor(1, 2 o 3): ", 1, 3);
				    if(addPassenger(passenger, PASAJEROS, newId, newName, newLastName, newPrice, newTypePassenger, newFlyCode) == FALSE){
				    	puts("----------------------------");
				    	puts("Error, datos invalidos");
				    	puts("----------------------------");
				    }
				    else{
				    	contadorPasajeros++;
				    	newId++;
				    	puts("----------------------------");
				    	puts("Pasajero creado con exito!");
				    	puts("----------------------------");
				    }
				  }
		      break;

			case 2:
				if(contadorPasajeros > 0){
					if(printPassenger(passenger, PASAJEROS)!= FALSE){
						idFounded = IngresarEntero("Ingrese el id del empleado a modificar por favor:", 0,10);
						if(findPassengerById(passenger, PASAJEROS, idFounded)!= FALSE){

							if(modifyPassenger(passenger, PASAJEROS, idFounded)!= FALSE){
								puts("----------------------------");
							    puts("�Pasajero modificado con exito! ");
							    puts("----------------------------");
						  }
							else{
								puts("----------------------------");
								puts("Error, datos invalidos");
								puts("----------------------------");
							}
						}
					}
				}
		      break;

			case 3:
				if(contadorPasajeros > 0){
					if(printPassenger(passenger, PASAJEROS) != FALSE){
						idFounded = IngresarEntero("Ingrese el id del empleado a modificar por favor:", 0,10);
						if(findPassengerById(passenger, PASAJEROS, idFounded)!= FALSE){
							if(removePassenger(passenger, PASAJEROS, idFounded) != FALSE){
								contadorPasajeros--;
								puts("----------------------------");
								puts("�Empleado eliminado con exito!");
								puts("----------------------------");
							}
							else{
								puts("----------------------------");
								puts("Error, datos invalidos");
								puts("----------------------------");
							}
						}
					}
				}
		      break;

			case 4:
				if(contadorPasajeros > 0){
				do{
				puts("----------------------------");
				puts("Ingrese una opcion: ");
				puts("1. Informar listado de los pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero.\n");
				puts("2. Informar total y promedio de los precios de los pasajes, y cu�ntos pasajeros superan el precio promedio.\n ");
				puts("3. Informar listado de los pasajeros por C�digo de vuelo y estados de vuelos �ACTIVO�\n");
				puts("4. Salir de este submenu. \n");
				puts("----------------------------");
				IngresoEnteroMinMax(&opcionMenuInformes,"", "Error, vuelva a ingresar un dato valido: ",1,4);

			    switch(opcionMenuInformes){
			    case 1:
			    	if(sortPassengers(passenger, PASAJEROS, 1) == TRUE &&printPassenger(passenger, PASAJEROS) == TRUE){

			    		puts("Listado de pasajeros por nombre apellido y tipo mostrado\n\n");

			    	}
			    	else{
			    	    	puts("Error, datos invalidos en el listado de pasajeros");
			    	}
			    	break;
			    case 2:
			    	if(promedioPassengers(passenger, PASAJEROS) == TRUE){
			    		puts("Informe de promedio mostrado\n\n");
			    	}
			    	else{
			    		 puts("Error, datos invalidos en el promedio");
			    	}
			    	break;
			    case 3:
			    	if(sortPassengersByCode(passenger, PASAJEROS, 1) == TRUE && printActivePassenger(passenger, PASAJEROS) == TRUE){
			    		puts("Listado de pasajeros por codigo y estado mostrado\n\n");
			    	}
			    	else{
			    		 puts("Error, datos invalidos en el codigo y estado del pasajero");
			    	}
			    	break;
			    case 4:
			    	puts("Saliendo del subMenu...");
			    	puts("�Usted ha salido del subMenu!");
			    }



				}while(opcionMenuInformes < 4);
				}
				break;

			case 5:
                 if(cargaForzadaPassenger(passenger, PASAJEROS, &newId) == TRUE){
                	  printPassenger(passenger, PASAJEROS);
                	  printf("�La carga forzada de pasajeros se ha realizado con exito!");
                 }
                 break;

			case 6:
				puts("Cerrando la Aplicacion...");
				break;
	    }
	}while(opcion < 6);

	puts("�la Aplicacion se ha cerrado con exito, muchas gracias por usarla!");
	puts("�Adios!");


	return EXIT_SUCCESS;
}
