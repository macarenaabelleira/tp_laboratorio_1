#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include "Calculos.h"

float CalcularDescuentoDebito(float precio){

	float descuentoDeDebito;

	descuentoDeDebito = precio - (precio*0.1);

	return descuentoDeDebito;
}
float CalcularAumentoCredito(float precio){

	float AumentoDeCredito;

	AumentoDeCredito = precio + (precio*0.25);

	return AumentoDeCredito;
}

double CalcularPrecioBitcoin(double precio){

	double precioBitcoin;
    double calculo;

    precioBitcoin = 4772611.08;

    calculo = precio/precioBitcoin ;

	return calculo;

}

float PrecioUnitario(float precio, float kilometros){

	float precioU;

	precioU = precio/kilometros;

	return precioU;
}

float DiferenciaDePrecios(float precioA, float precioL){

	float diferenciaPrecio;

	diferenciaPrecio = precioA - precioL;
	if(diferenciaPrecio < 0){

		diferenciaPrecio = diferenciaPrecio *- 1;
	}
	return diferenciaPrecio;
}

