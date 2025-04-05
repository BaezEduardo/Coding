#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

// Función para insertar al inicio de la lista
void insertarInicio(Nodo **cabeza, int nuevoDato) {
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->dato = nuevoDato;
    nuevoNodo->siguiente = *cabeza;
    *cabeza = nuevoNodo;
}

// Función para imprimir los elementos de la lista
void imprimirLista(Nodo *n) {
    while (n != NULL) {
        printf("%d ", n->dato);
        n = n->siguiente;
    }
    printf("\n");
}

int main() {
    Nodo *cabeza = NULL;
    insertarInicio(&cabeza, 5);
    insertarInicio(&cabeza, 2);
    insertarInicio(&cabeza, 1);

    printf("La lista es: ");
    imprimirLista(cabeza);

    // Liberar la memoria de la lista
    // (se omiten las llamadas a free por simplicidad)

    return 0;
}