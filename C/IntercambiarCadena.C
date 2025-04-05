#include <stdio.h>

int main() {
    char cad1[1000]; // Declarar una cadena para la primera entrada
    char cad2[1000]; // Declarar una cadena para la segunda entrada
    char temp[1000]; // Declarar una cadena temporal para el intercambio

    // Leer las dos cadenas
    printf("Ingrese la cadena 1: ");
    gets(cad1); // Leer la primera cadena (ten en cuenta que gets() es inseguro y se debe usar con precaución)

    printf("Ingrese la cadena 2: ");
    gets(cad2); // Leer la segunda cadena

    // Intercambiar las cadenas sin usar funciones
    int i = 0;
    while (cad1[i] != '\0' || cad2[i] != '\0') {
        temp[i] = cad1[i];
        cad1[i] = cad2[i];
        cad2[i] = temp[i];
        i++;
    }

    // Mostrar las cadenas intercambiadas
    printf("Cadena 1 (después del intercambio): %s\n", cad1);
    printf("Cadena 2 (después del intercambio): %s\n", cad2);

    return 0;
}