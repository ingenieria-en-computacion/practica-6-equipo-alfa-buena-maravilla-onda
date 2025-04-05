#pragma once
#include <stdio.h>
#include <stdlib.h>

#define MAX 100  

typedef struct {
    int datos[MAX];
    int frente;
    int final;
    int longitud;  
} ColaCircular;

void inicializarCola(ColaCircular *cola);
int estaVacia(ColaCircular *cola);
int estaLlena(ColaCircular *cola);
int encolar(ColaCircular *cola, int elemento);
int desencolar(ColaCircular *cola, int *elemento);
void mostrarCola(ColaCircular *cola);


