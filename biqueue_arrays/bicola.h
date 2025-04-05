#pragma once
#include <stdio.h>
#include <stdlib.h>

#define MAX 100  

typedef struct {
    int datos[MAX];
    int frente;
    int final;
    int longitud;
} Bicola;

void inicializarBicola(Bicola *bicola);
int estaVacia(Bicola *bicola);
int estaLlena(Bicola *bicola);
int encolarFrente(Bicola *bicola, int elemento);
int encolarFinal(Bicola *bicola, int elemento);
int desencolarFrente(Bicola *bicola, int *elemento);
int desencolarFinal(Bicola *bicola, int *elemento);
void mostrarBicola(Bicola *bicola);