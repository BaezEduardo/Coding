#include <stdio.h>

int main() {
    char cadena[1000]; // Declarar una cadena para almacenar la entrada del usuario

    printf("Ingrese una cadena: ");
    gets(cadena); // Leer la cadena de entrada (ten en cuenta que gets() es inseguro y se debe usar con precaución)

    int i = 0;
    while (cadena[i] != '\0') {
        char palabra[100] = ""; // Declarar una cadena para almacenar la palabra actual
        int j = 0;

        // Ignorar espacios iniciales
        while (cadena[i] == ' ') {
            i++;
        }

        // Extraer la palabra actual
        while (cadena[i] != ' ' && cadena[i] != '\0') {
            palabra[j] = cadena[i];
            i++;
            j++;
        }

        // Mostrar la palabra actual si no está vacía
        if (j > 0) {
            printf("\"%s\" ", palabra);
        }
    }

    printf("\n");

    return 0;
}