

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;
/// @fn int initPassengers(Passenger*, int)
/// @brief indica que todas las posiciones del array estan vacias,
/// esta funcion pone el isEmpty en TRUE en todas las posiciones del array.
/// @param list Passenger* puntero a un array de pasajeros.
/// @param len longuitud de la matriz.
/// @return devuelve -1 si hay un error o 0 si esta bien.
int initPassengers(Passenger* list, int len);
/// @fn int addPassenger(Passenger*, int, int, char[], char[], float, int, char[])
/// @brief agregar una lista existente de pasajeros con los valores recibidos como
/// parametros en la primera posicion vacia.
/// @param list passenger*
/// @param len int
/// @param id int
/// @param name[] char  nombre pasajero
/// @param lastName [] char  apellido pasajero
/// @param price float precio pasajero
/// @param typePassenger int tipo de pasarejo
/// @param flyCode [] char  codigo pasajero
/// @return devuelve -1 si hay un error o 0 si esta bien.
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flyCode[]);
/// @fn int findPassengerById(Passenger*, int, int)
/// @brief busca el pasajero por el id.
/// @param list Passenger*
/// @param len  int
/// @param id int
/// @return devuelve -1 si hay un error o 0 si esta bien.
int findPassengerById(Passenger* list, int len, int id);
/// @fn int modifyPassenger(Passenger*, int, int)
/// @brief modifica datos pasajero.
/// @param list Passenger*
/// @param len int
/// @param id int
/// @return devuelve -1 si hay un error o 0 si esta bien.
int modifyPassenger(Passenger* list, int len, int id);
/// @fn int removePassenger(Passenger*, int, int)
/// @brief remueve pasajero por id.
/// @param list Passenger*
/// @param len int
/// @param id int
/// @return devuelve -1 si hay un error o 0 si esta bien.
int removePassenger(Passenger* list, int len, int id);
/// @fn int sortPassengers(Passenger*, int, int)
/// @brief Ordena el listado de pasajeros por apellido y tipo
/// @param list Passenger*
/// @param len int
/// @param order 1 up 0 down
/// @return devuelve -1 si hay un error o 0 si esta bien.
int sortPassengers(Passenger* list, int len, int order);
/// @fn int sortPassengersByCode(Passenger*, int, int)
/// @brief Ordena el listado de pasajeros por codigo y estado
/// @param list Passenger*
/// @param len int
/// @param order 1 up 0 down
/// @return devuelve -1 si hay un error o 0 si esta bien.
int sortPassengersByCode(Passenger* list, int len, int order);
/// @fn int printPassenger(Passenger*, int)
/// @brief imprime el contenido del array de pasajeros
/// @param list Passenger*
/// @param length int
/// @return devuelve -1 si hay un error o 0 si esta bien.
int printPassenger(Passenger* list, int length);
/// @fn int promedioPassengers(Passenger*, int)
/// @brief saca el promedio de los precios de los pasajeros
/// @param list Passenger*
/// @param len int
/// @return devuelve -1 si hay un error o 0 si esta bien.
int promedioPassengers(Passenger* list, int len);
/// @fn int printActivePassenger(Passenger*, int)
/// @brief Iprime el contenido del array de pasajeros en estado ACTIVO
/// @param list Passenger*
/// @param len int
/// @return devuelve -1 si hay un error o 0 si esta bien.
int printActivePassenger(Passenger* list, int len);
/// @fn int cargaForzadaPassenger(Passenger*, int, int*)
/// @brief hace una carga forzada de pasajeros
/// @param list Passenger*
/// @param len int
/// @param id int
/// @return devuelve -1 si hay un error o 0 si esta bien.
int cargaForzadaPassenger(Passenger* list, int len, int* id);
#endif /* ARRAYPASSENGER_H_ */
