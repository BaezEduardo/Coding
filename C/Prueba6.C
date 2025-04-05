#include <stdio.h>

void invertirCaso(char *cadena) {
    while (*cadena) {
        if (*cadena >= 'a' && *cadena <= 'z') {
            *cadena = *cadena - 'a' + 'A';
        } else if (*cadena >= 'A' && *cadena <= 'Z') {
            *cadena = *cadena - 'A' + 'a';
        }
        cadena++;
    }
}

int main() {
    char cadena[1000];

    printf("Ingrese una cadena: ");
    scanf(cadena);

    invertirCaso(cadena);

    printf("Cadena con el caso invertido: %s\n", cadena);

    return 0;
}
