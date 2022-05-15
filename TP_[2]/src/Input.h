#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

float IngresarFlotante(char mensaje[], int desde, int hasta);
int IngresarEntero(char mensaje[], int desde, int hasta);
int getString(char cadena[], char mensaje[], int tam);
int ValidarEntero(char* ingreso);
int IngresoEnteroMinMax(int* ingreso, char* mensaje, char* errorTexto, int min, int max);
