#include <stdio.h>
#include <string.h>

int main() {
    char cadena[100]; // Declarar una cadena para almacenar la entrada del usuario
    char resultado[100] = ""; // Declarar una cadena vacía para el resultado
    int longitud = 0, longitudcadena = 0;

    printf("Ingrese una cadena: ");
    gets(cadena); // Leer la cadena de entrada (ten en cuenta que gets() es inseguro y se debe usar con precaución)

    while (cadena[longitud] != '\0') {
        longitud++;
    }

    for (int i = 0; i < longitud; i++) {
        char caracter_actual = cadena[i];
        int esta_repetido = 0;

        // Verificar si el carácter actual ya está presente en la cadena resultado
        for (int j = 0; j < longitudcadena; j++) {
            if (caracter_actual == resultado[j]) {
                esta_repetido = 1;
                break;
            }
        }

        // Si el carácter no está repetido, agrégalo a la cadena resultado
        if (!esta_repetido) {
            resultado[longitudcadena] = caracter_actual;
            longitudcadena++;
        }
    }

    resultado[longitudcadena] = '\0'; // Agregar el carácter nulo al final de la cadena resultado

    printf("Cadena resultante: %s\n", resultado);

    return 0;
}