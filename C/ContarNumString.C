#include <stdio.h>

int main() {
    char cadena[1000]; // Supongamos que la cadena tiene un tamaño máximo de 1000 caracteres
    int contadorNumeros = 0;
    int i = 0;

    printf("Ingrese una cadena: ");
    gets(cadena); // Lee la cadena de entrada

    while (cadena[i] != '\0') {
        if (cadena[i] >= '0' && cadena[i] <= '9') {
            // Si el carácter actual está en el rango '0'-'9', es un dígito
            if (i == 0 || (cadena[i - 1] < '0' || cadena[i - 1] > '9')) {
                // Si es el primer dígito del número o no está precedido por un dígito
                contadorNumeros++;
            }
        }
        i++;
    }

    printf("Hay %d números enteros en la cadena.\n", contadorNumeros);

    return 0;
}