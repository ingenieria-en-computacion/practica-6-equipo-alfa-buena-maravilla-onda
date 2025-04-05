#include "bicola.h"

void inicializarBicola(Bicola *bicola) {
    bicola->frente = -1;
    bicola->final = -1;
    bicola->longitud = 0;
}

int estaVacia(Bicola *bicola) {
    return (bicola->longitud == 0);
}

int estaLlena(Bicola *bicola) {
    return (bicola->longitud == MAX);
}

int encolarFrente(Bicola *bicola, int elemento) {
    if (estaLlena(bicola)) {
        printf("La bicola esta llena.\n");
        return -1;
    }
    if (estaVacia(bicola)) {
        bicola->frente = bicola->final = 0;
    } else {
        bicola->frente = (bicola->frente - 1 + MAX) % MAX;
    }
    bicola->datos[bicola->frente] = elemento;
    bicola->longitud++;
    return 0;
}

int encolarFinal(Bicola *bicola, int elemento) {
    if (estaLlena(bicola)) {
        printf("La bicola esta llena.\n");
        return -1;
    }
    if (estaVacia(bicola)) {
        bicola->frente = bicola->final = 0;
    } else {
        bicola->final = (bicola->final + 1) % MAX;
    }
    bicola->datos[bicola->final] = elemento;
    bicola->longitud++;
    return 0;
}

int desencolarFrente(Bicola *bicola, int *elemento) {
    if (estaVacia(bicola)) {
        printf(" La bicola esta vacia.\n");
        return -1;
    }
    *elemento = bicola->datos[bicola->frente];
    if (bicola->frente == bicola->final) {
        inicializarBicola(bicola);
    } else {
        bicola->frente = (bicola->frente + 1) % MAX;
        bicola->longitud--;
    }
    return 0;
}

int desencolarFinal(Bicola *bicola, int *elemento) {
    if (estaVacia(bicola)) {
        printf("La bicola esta vacia.\n");
        return -1;
    }
    *elemento = bicola->datos[bicola->final];
    if (bicola->frente == bicola->final) {
        inicializarBicola(bicola);
    } else {
        bicola->final = (bicola->final - 1 + MAX) % MAX;
        bicola->longitud--;
    }
    return 0;
}

void mostrarBicola(Bicola *bicola) {
    if (estaVacia(bicola)) {
        printf("La bicola esta vacia.\n");
        return;
    }
    int i = bicola->frente;
    printf("Bicola (longitud %d): ", bicola->longitud);
    while (1) {
        printf("%d ", bicola->datos[i]);
        if (i == bicola->final)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
