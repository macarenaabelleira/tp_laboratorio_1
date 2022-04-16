/*
 *
 *  Created on: 8 abr. 2022
 *      Author: Macaerna Abelleira. Div 1F
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

#include "Calculos.h"
/// @fn float CalcularDescuentoDebito(float)
/// @brief Calcula el descuento de la tarjeta de debito y lo devuelve.
/// @param precio
/// @return retorna el precio con descuento de la tarjeta de debito.
float CalcularDescuentoDebito(float precio);
/// @fn float CalcularAumentoCredito(float)
/// @brief calcula el aumento con la tarjeta de credito y lo devuelve.
/// @param precio
/// @return retorna el precio con aumento de la tarjeta de credito.
float CalcularAumentoCredito(float precio);
/// @fn double CalcularPrecioBitcoin(double)
/// @brief calcula el precio con bitcoin y lo devuelve
/// @param precio
/// @return retorna el precio en bitcoin
double CalcularPrecioBitcoin(double precio);
/// @fn float PrecioUnitario(float, float)
/// @brief calcula el precio por unidad.
/// @param precio
/// @param kilometros
/// @return retorna el precio por unidad.
float PrecioUnitario(float precio, float kilometros);
/// @fn float DiferenciaDePrecios(float, float)
/// @brief calcula la difeerncia de precios entre los dos vuelos.
/// @param precioA
/// @param precioL
/// @return retorna la diferencia de precios entre los dos vuelos.
float DiferenciaDePrecios(float precioA, float precioL);


#endif /* CALCULOS_H_ */
