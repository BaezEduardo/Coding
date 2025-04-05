#include <stdio.h>

int main() {
    char cadena[1000]; // Declarar una cadena para almacenar la entrada del usuario

    printf("Ingrese una cadena: ");
    gets(cadena); // Leer la cadena de entrada (ten en cuenta que gets() es inseguro y se debe usar con precaución)

    int vocales = 0;
    int consonantes = 0;
    int simbolosPuntuacion = 0;

    int i = 0;
    while (cadena[i] != '\0') {
        char caracter_actual = cadena[i];

        // Convertir el carácter a minúsculas para realizar las verificaciones sin distinción de mayúsculas/minúsculas
        if (caracter_actual >= 'A' && caracter_actual <= 'Z') {
            caracter_actual += ('a' - 'A');
        }

        // Verificar si el carácter es una vocal
        if (caracter_actual == 'a' || caracter_actual == 'e' || caracter_actual == 'i' || caracter_actual == 'o' || caracter_actual == 'u') {
            vocales++;
        }
        // Verificar si el carácter es una consonante
        else if ((caracter_actual >= 'a' && caracter_actual <= 'z')) {
            consonantes++;
        }
        // Verificar si el carácter es un símbolo de puntuación
        else if (caracter_actual == ',' || caracter_actual == '.' || caracter_actual == ':' || caracter_actual == ';') {
            simbolosPuntuacion++;
        }

        i++;
    }

    printf("Vocales: %d, Consonantes: %d, Simbolos de puntuación: %d\n", vocales, consonantes, simbolosPuntuacion);

    return 0;
}