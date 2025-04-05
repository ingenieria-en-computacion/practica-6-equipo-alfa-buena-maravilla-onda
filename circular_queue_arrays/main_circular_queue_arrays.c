#include "cola.h"

int main() {
    ColaCircular cola;
    int elemento;
    int n, m, p;

    inicializarCola(&cola);
    mostrarCola(&cola);
    
    printf("¿Cuantos elementos desea encolar? ");
    scanf("%d", &m);

    printf("\nInsertando nuevos elementos...\n");
    for (int i = 0; i < m; i++) {  
        int nuevoValor;
        printf("Ingrese el valor a encolar: ");
        scanf("%d", &nuevoValor);
        
        if (encolar(&cola, nuevoValor) == 0)
            printf("Encolado: %d\n", nuevoValor);
        else {
            printf("La cola esta llena, no se pueden encolar mas elementos.\n");
            break;
        }
    }

    mostrarCola(&cola);

    printf("¿Cuantos elementos desea desencolar? ");
    scanf("%d", &n);

    printf("\nDesencolando elementos...\n");
    for (int i = 0; i < n; i++) {
        if (desencolar(&cola, &elemento) == 0)
            printf("Desencolado: %d\n", elemento);
        else {
            printf("No se pudo desencolar mas elementos, la cola esta vacia.\n");
            break;
        }
    }

    mostrarCola(&cola);

    printf("¿Cuantos elementos desea encolar? ");
    scanf("%d", &p);

    printf("\nInsertando nuevos elementos...\n");
    for (int i = 0; i < p; i++) {
        int nuevoValor;
        printf("Ingrese el valor a encolar: ");
        scanf("%d", &nuevoValor);
        
        if (encolar(&cola, nuevoValor) == 0)
            printf("Encolado: %d\n", nuevoValor);
        else {
            printf("La cola esta llena, no se pueden encolar mas elementos.\n");
            break;
        }
    }

    mostrarCola(&cola);

    return 0;
}

