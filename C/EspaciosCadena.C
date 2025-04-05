#include <stdio.h>
#include <string.h>

int main() {
    char cadena[100]; // Supongamos que la cadena tiene un tamaño máximo de 100 caracteres
    char nuevaCadena[100]; // Para almacenar la cadena resultante
    int i, j;
    int largoCadena;
    printf("Ingrese una cadena: ");
    gets(cadena); // Lee la cadena de entrada

    largoCadena = strlen(cadena);
    j = 0; // Índice para la nueva cadena

    for (i = 0; i < largoCadena; i++) {
        if (cadena[i] == ' ') {
            // Si es un espacio, verifica si el siguiente carácter también es un espacio
            int contadorEspacios = 0;
            while (cadena[i] == ' ' && i < largoCadena) {
                contadorEspacios++;
                i++;
            }
            // Si hay más de dos espacios consecutivos, agrega solo uno a la nueva cadena
            if (contadorEspacios > 2) {
                nuevaCadena[j++] = ' ';
            }
            // Retrocede un paso para no perder el carácter siguiente
            i--;
        } else {
            nuevaCadena[j++] = cadena[i];
            printf("%d",j);
        }
    }

    // Elimina los espacios al principio y al final de la cadena resultante
    while (j > 0 && nuevaCadena[j - 1] == ' ') {
        j--;
    }
    nuevaCadena[j] = '\0'; // Agrega el carácter nulo al final de la nueva cadena

    printf("Cadena resultante: %s\n", nuevaCadena);

    return 0;
}