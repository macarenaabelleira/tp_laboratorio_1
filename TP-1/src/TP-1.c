/*
 Macarena Abelleira. 1-F
 1 Enunciado
 Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
 para ofrecerlos a sus clientes.
 Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
 El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
 Para ello el programa iniciará y contará con un menú de opciones:
 1. Ingresar Kilómetros: ( km=x)
 2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
 - Precio vuelo Aerolíneas:
 - Precio vuelo Latam:
 3. Calcular todos los costos:
 a) Tarjeta de débito (descuento 10%)
 b) Tarjeta de crédito (interés 25%)
 c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
 d) Mostrar precio por km (precio unitario)
 e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
 4. Informar Resultados
 “Latam:
 a) Precio con tarjeta de débito: r
 b) Precio con tarjeta de crédito: r
 c) Precio pagando con bitcoin : r
 d) Precio unitario: r
 Aerolíneas:
 a) Precio con tarjeta de débito: r
 b) Precio con tarjeta de crédito: r
 c) Precio pagando con bitcoin : r
 d) Precio unitario: r
 La diferencia de precio es : r “
 5. Carga forzada de datos
 6. Salir
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "Calculos.h"

int main(void) {
	setbuf(stdout, NULL);
	int opciones;
	float x;
	float z;
	float y;
	float precioBitcoinA;
	float precioBitcoinL;
	float precioUnitarioL;
	float precioUnitarioA;
	float diferenciaPrecioAyL;
	float aumentoCreditoA;
	float descuentoDebitoA;
	float aumentoCreditoL;
	float descuentoDebitoL;
	int KMforzados;
	int aerolineasDatoForzado;
	int latamDatoForzado;
	int flag1;
	flag1 = 0;
	x = 0;
	y = 0;
	z = 0;
	KMforzados = 7090;
	aerolineasDatoForzado = 162965;
	latamDatoForzado = 159339;

	printf("\n\tBIENVENIDOS A LA AGENCIA DE VIAJES DE MACARENA ABELLEIRA");
	puts("\n\t--------------------------------------------------------\n\n");

	do {
		system("cls");
		printf("\tMENU DE OPCIONES\n");
		printf("\t1. Ingrese Kilómetros: ( km=x)\n");
		printf("\t2. Ingrese Precio de Vuelos: (Aerolíneas=y, Latam=z)\n");
		printf("\t3. Calcular todos los costos: \n");
		printf("\t4. Informar Resultados \n");
		printf("\t5. Carga forzada de datos \n");
		printf("\t6. Salir. \n");
		printf("\telegir una opcion: \n");
		scanf("%d", &opciones);

		switch (opciones) {
		case 1:
			system("cls");
			printf("\tIngresar Kilometros: \n");
			scanf("%f", &x);

			if (x <= 0) {
				printf("\tError, no ha ingresado km validos.\n");
			}

			break;
		case 2:
			system("cls");
			printf("\tIngrese el precio de los vuelos: \n\n");
			printf("\tPrecio vuelo Aerolineas: \n");
			scanf("%f", &y);
			while (y <= 0) {
				printf(
						"\tError, no ha ingresado un precio valido de Aerolineas.\n");
				printf("\n\t Reingrese precio vuelo Aerolineas: \n");
				scanf("%f", &y);
				flag1 = 1;
			}
			printf("\tPrecio vuelo Latam: \n");
			scanf("%f", &z);
			while (z <= 0) {
				printf("\tError, no ha ingresado un precio valido de Latam.\n");
				printf("\n\t Reingrese precio vuelo Latam: \n");
				scanf("%f", &z);
				flag1 = 1;
			}
			break;

		case 3:
			system("cls");
			if (y <= 0 && z <= 0) {
				printf("\tError, no ha ingresado datos validos.\n");
			}
			if (y <= 0 || z <= 0) {
				printf(
						"\tError, a ingresado solo un dato valido, falta uno.\n");
			} else {
				descuentoDebitoA = CalcularDescuentoDebito(y);
				aumentoCreditoA = CalcularAumentoCredito(y);
				precioBitcoinA = CalcularPrecioBitcoin(y);
				precioUnitarioA = PrecioUnitario(y, x);

				descuentoDebitoL = CalcularDescuentoDebito(z);
				aumentoCreditoL = CalcularAumentoCredito(z);
				precioBitcoinL = CalcularPrecioBitcoin(z);
				precioUnitarioL = PrecioUnitario(z, x);

				diferenciaPrecioAyL = DiferenciaDePrecios(y, z);
				printf("\tLos calculos se hicieron correctamente.\n\n");
			}
			break;
		case 4:
			system("cls");
			if (y <= 0 && z <= 0) {
				printf("\tError, no ha ingresado datos validos.\n");
			}
			if (y <= 0 || z <= 0) {
				printf(
						"\tError, a ingresado solo un dato valido, falta uno.\n");

			} else {

				printf("\tKMs Ingresados: %.2f\n\n", x);
				printf("\tPrecio Aerolineas: $%.2f\n", y);
				printf("\ta) Precio con tarjeta de debito: $%.2f\n",
						descuentoDebitoA);
				printf("\tb) Precio con tarjeta de credito: $%.2f\n",
						aumentoCreditoA);
				printf("\tc) Precio pagando con bitcoin: $%f\n",
						precioBitcoinA);
				printf("\td) Mostrar precio unitario: $%.2f\n\n\n",
						precioUnitarioA);

				printf("\tPrecio Latam: %.2f\n", z);
				printf("\ta) Precio con tarjeta de debito:$ %.2f\n",
						descuentoDebitoL);
				printf("\tb) Precio con tarjeta de credito: $%.2f\n",
						aumentoCreditoL);
				printf("\tc) Precio pagando con bitcoin: $%f\n",
						precioBitcoinL);
				printf("\td) Mostrar precio unitario: $%.2f\n\n",
						precioUnitarioL);
				printf("\tla diferencia de precio es: $%.2f\n\n",
						diferenciaPrecioAyL);
			}
			break;
		case 5:
			system("cls");
			descuentoDebitoA = CalcularDescuentoDebito(aerolineasDatoForzado);
			aumentoCreditoA = CalcularAumentoCredito(aerolineasDatoForzado);
			precioBitcoinA = CalcularPrecioBitcoin(aerolineasDatoForzado);
			precioUnitarioA = PrecioUnitario(aerolineasDatoForzado, KMforzados);

			descuentoDebitoL = CalcularDescuentoDebito(latamDatoForzado);
			aumentoCreditoL = CalcularAumentoCredito(latamDatoForzado);
			precioBitcoinL = CalcularPrecioBitcoin(latamDatoForzado);
			precioUnitarioL = PrecioUnitario(latamDatoForzado, KMforzados);
			diferenciaPrecioAyL = DiferenciaDePrecios(aerolineasDatoForzado,
					latamDatoForzado);

			printf("\tKMs Ingresados: %d\n", KMforzados);
			printf("\tAerolineas Argentinas: $%d\n", aerolineasDatoForzado);
			printf("\ta) Precio con tarjeta de debito: $%.2f\n",
					descuentoDebitoA);
			printf("\tb) Precio con tarjeta de credito: $%.2f\n",
					aumentoCreditoA);
			printf("\tc) Precio pagando con bitcoin: $%f\n", precioBitcoinA);
			printf("\td) Mostrar precio unitario: $%.2f\n\n\n",
					precioUnitarioA);

			printf("\tLatam: $%d\n", latamDatoForzado);
			printf("\ta) Precio con tarjeta de debito: $%.2f\n",
					descuentoDebitoL);
			printf("\tb) Precio con tarjeta de credito: $%.2f\n",
					aumentoCreditoL);
			printf("\tc) Precio pagando con bitcoin: $%f\n", precioBitcoinL);
			printf("\td) Mostrar precio unitario: $%.2f\n\n", precioUnitarioL);
			printf("\tla diferencia de precio es: $%.2f\n\n",
					diferenciaPrecioAyL);
			break;
		}

	} while (opciones != 6);

	printf(
			"\t-----  Gracias por usar la agencia de viajes de Macarena  -----\n");

	return EXIT_SUCCESS;
}
