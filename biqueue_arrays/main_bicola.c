#include "bicola.h"

int main() {
    Bicola bicola;
    int elemento;
    int n, m, p;

    inicializarBicola(&bicola);
    mostrarBicola(&bicola);
    
    printf("¿Cuantos elementos desea encolar por el final? ");
    scanf("%d", &m);

    printf("\nInsertando elementos al final...\n");
    for (int i = 0; i < m; i++) {  
        int nuevoValor;
        printf("Ingrese el valor a encolar: ");
        scanf("%d", &nuevoValor);
        
        if (encolarFinal(&bicola, nuevoValor) == 0)
            printf("Encolado en final: %d\n", nuevoValor);
        else {
            printf("La bicola esta llena, no se pueden encolar mas elementos.\n");
            break;
        }
    }

    mostrarBicola(&bicola);

    printf("¿Cuantos elementos desea encolar por el frente? ");
    scanf("%d", &p);

    printf("\nInsertando elementos al frente...\n");
    for (int i = 0; i < p; i++) {
        int nuevoValor;
        printf("Ingrese el valor a encolar: ");
        scanf("%d", &nuevoValor);
        
        if (encolarFrente(&bicola, nuevoValor) == 0)
            printf("Encolado en frente: %d\n", nuevoValor);
        else {
            printf("La bicola esta llena, no se pueden encolar mas elementos.\n");
            break;
        }
    }

    mostrarBicola(&bicola);

    printf("¿Cuantos elementos desea desencolar por el frente? ");
    scanf("%d", &n);

    printf("\nDesencolando elementos del frente...\n");
    for (int i = 0; i < n; i++) {
        if (desencolarFrente(&bicola, &elemento) == 0)
            printf("Desencolado del frente: %d\n", elemento);
        else {
            printf("No se pudo desencolar mas elementos, la bicola esta vacia.\n");
            break;
        }
    }

    mostrarBicola(&bicola);

    printf("¿Cuantos elementos desea desencolar por el final? ");
    scanf("%d", &n);

    printf("\nDesencolando elementos del final...\n");
    for (int i = 0; i < n; i++) {
        if (desencolarFinal(&bicola, &elemento) == 0)
            printf("Desencolado del final: %d\n", elemento);
        else {
            printf("No se pudo desencolar mas elementos, la bicola esta vacia.\n");
            break;
        }
    }

    mostrarBicola(&bicola);

    return 0;
}
