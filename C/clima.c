#include <stdio.h>

#define AÑOS 2
#define MESES 12

// Definimos los años 2023 y 2024
const int años[AÑOS] = {2023, 2024};

// Matriz para almacenar la cantidad de lluvia
float lluvia[AÑOS][MESES];

// Función para capturar la lluvia por mes y año
void capturar_lluvia() {
    for (int i = 0; i < AÑOS; i++) {
        printf("\nIngrese la cantidad de lluvia para el año %d:\n", años[i]);
        for (int j = 0; j < MESES; j++) {
            printf("Mes %d: ", j + 1);
            scanf("%f", &lluvia[i][j]);
        }
    }
}

// Función para calcular la cantidad total de lluvia en un año dado
void lluvia_por_año() {
    int año;
    printf("\nIngrese el año (2023 o 2024): ");
    scanf("%d", &año);

    int index = -1;
    for (int i = 0; i < AÑOS; i++) {
        if (años[i] == año) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Año no válido.\n");
        return;
    }

    float total = 0;
    for (int j = 0; j < MESES; j++) {
        total += lluvia[index][j];
    }
    printf("La cantidad total de lluvia en %d fue: %.2f mm\n", año, total);
}

// Función para calcular la lluvia total de un mes en ambos años
void lluvia_por_mes() {
    int mes;
    printf("\nIngrese el número del mes (1-12): ");
    scanf("%d", &mes);

    if (mes < 1 || mes > 12) {
        printf("Mes no válido.\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < AÑOS; i++) {
        total += lluvia[i][mes - 1];
    }
    printf("La cantidad total de lluvia en el mes %d (2023 y 2024) fue: %.2f mm\n", mes, total);
}

// Menú principal
void menu() {
    int opcion;
    do {
        printf("\n--- Sistema de Gestión de Lluvia ---\n");
        printf("1. Capturar datos de lluvia\n");
        printf("2. Calcular lluvia total de un año\n");
        printf("3. Calcular lluvia total de un mes en ambos años\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                capturar_lluvia();
                break;
            case 2:
                lluvia_por_año();
                break;
            case 3:
                lluvia_por_mes();
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (opcion != 4);
}

// Función principal
int main() {
    menu();
    return 0;
}