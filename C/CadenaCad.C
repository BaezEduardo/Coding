#include <stdio.h>
#include <string.h>

int main() {
    char cadena[1000]; // Declarar una cadena para la primera entrada
    char subcadena[1000]; // Declarar una cadena para la segunda entrada

    printf("Ingrese la cadena principal: ");
    gets(cadena); 

    printf("Ingrese la subcadena a buscar: ");
    gets(subcadena); 

    int contador = 0;
    int longitudCadena = strlen(cadena);
    int longitudSubcadena = strlen(subcadena);

    if (longitudSubcadena <= longitudCadena) {
        for (int i = 0; i <= longitudCadena - longitudSubcadena; i++) {
            int j;

            for (j = 0; j < longitudSubcadena; j++) {
                if (cadena[i + j] != subcadena[j]) {
                    break;
                }
            }

            if (j == longitudSubcadena) {
                contador++;
            }
        }
    }

    printf("\"%s\" aparece %d veces en la cadena.\n", subcadena, contador);

    return 0;
}