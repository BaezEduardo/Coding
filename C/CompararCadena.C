#include <stdio.h>

int main() {
    char cadena1[1000]; // Declarar una cadena para la primera entrada
    char cadena2[1000]; // Declarar una cadena para la segunda entrada

    // Leer las dos cadenas
    printf("Ingrese la cadena 1: ");
    gets(cadena1); // Leer la primera cadena (ten en cuenta que gets() es inseguro y se debe usar con precaución)

    printf("Ingrese la cadena 2: ");
    gets(cadena2); // Leer la segunda cadena

    int sonIguales = 1; // Suponemos que las cadenas son iguales al principio

    // Verificar si las cadenas son iguales o no
    int i = 0;
    while (cadena1[i] != '\0' || cadena2[i] != '\0') {
        if (cadena1[i] != cadena2[i]) {
            sonIguales = 0; // Si se encuentra un carácter diferente, las cadenas no son iguales
            break;
        }
        i++;
    }

    if (sonIguales) {
        printf("Las cadenas son iguales.\n");
    } else {
        printf("Las cadenas no son iguales.\n");
    }

    return 0;
}