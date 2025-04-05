#include "cola.h"

void inicializarCola(ColaCircular *cola) {
    cola->frente = -1;
    cola->final = -1;
    cola->longitud = 0;  
}

int estaVacia(ColaCircular *cola) {
    return (cola->longitud == 0);
}

int estaLlena(ColaCircular *cola) {
    return (cola->longitud == MAX);
}

int encolar(ColaCircular *cola, int elemento) {
    if (estaLlena(cola)) {
        printf("Error: La cola esta llena.\n");
        return -1;
    }
    if (estaVacia(cola)) {
        cola->frente = 0;
    }
    cola->final = (cola->final + 1) % MAX;
    cola->datos[cola->final] = elemento;
    cola->longitud++;  
    return 0;
}

int desencolar(ColaCircular *cola, int *elemento) {
    if (estaVacia(cola)) {
        printf("Error: La cola esta vacia.\n");
        return -1;
    }
    *elemento = cola->datos[cola->frente];
    if (cola->frente == cola->final) {  
        cola->frente = -1;
        cola->final = -1;
    } else {
        cola->frente = (cola->frente + 1) % MAX;
    }
    cola->longitud--;  
    return 0;
}

void mostrarCola(ColaCircular *cola) {
    if (estaVacia(cola)) {
        printf("La cola esta vacia.\n");
        return;
    }
    int i = cola->frente;
    printf("Cola (longitud %d): ", cola->longitud);
    while (1) {
        printf("%d ", cola->datos[i]);
        if (i == cola->final)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

