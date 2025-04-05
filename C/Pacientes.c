#include <stdio.h>
#include <string.h>

#define MAX_PACIENTES 100

// Estructura para representar a un paciente
typedef struct {
    int id;
    char nombre[50];
    int edad;
    char genero[10];
    char diagnostico[100];
    int activo; // 1 = activo, 0 = eliminado
} Paciente;

Paciente pacientes[MAX_PACIENTES]; // Arreglo para almacenar los pacientes
int contador_pacientes = 0; // Número actual de pacientes registrados

// Función para agregar un nuevo paciente
void agregar_paciente() {
    if (contador_pacientes >= MAX_PACIENTES) {
        printf("Error: No se pueden agregar más pacientes.\n");
        return;
    }
    
    Paciente nuevo;
    nuevo.id = contador_pacientes + 1;
    printf("Nombre: ");
    scanf(" %[^\n]", nuevo.nombre);
    printf("Edad: ");
    scanf("%d", &nuevo.edad);
    printf("Género: ");
    scanf(" %[^\n]", nuevo.genero);
    printf("Diagnóstico: ");
    scanf(" %[^\n]", nuevo.diagnostico);
    nuevo.activo = 1;
    
    pacientes[contador_pacientes++] = nuevo;
    printf("Paciente agregado con ID: %d\n", nuevo.id);
}

// Función para buscar un paciente por ID
void buscar_paciente() {
    int id;
    printf("Ingrese el ID del paciente: ");
    scanf("%d", &id);
    
    for (int i = 0; i < contador_pacientes; i++) {
        if (pacientes[i].id == id && pacientes[i].activo) {
            printf("ID: %d, Nombre: %s, Edad: %d, Género: %s, Diagnóstico: %s\n",
                   pacientes[i].id, pacientes[i].nombre, pacientes[i].edad,
                   pacientes[i].genero, pacientes[i].diagnostico);
            return;
        }
    }
    printf("Paciente no encontrado.\n");
}

// Función para listar todos los pacientes
void listar_pacientes() {
    printf("\n--- Lista de Pacientes ---\n");
    for (int i = 0; i < contador_pacientes; i++) {
        if (pacientes[i].activo) {
            printf("ID: %d | Nombre: %s | Edad: %d | Género: %s | Diagnóstico: %s\n",
                   pacientes[i].id, pacientes[i].nombre, pacientes[i].edad,
                   pacientes[i].genero, pacientes[i].diagnostico);
        }
    }
}

// Función para eliminar un paciente por ID
void eliminar_paciente() {
    int id;
    printf("Ingrese el ID del paciente a eliminar: ");
    scanf("%d", &id);
    
    for (int i = 0; i < contador_pacientes; i++) {
        if (pacientes[i].id == id && pacientes[i].activo) {
            pacientes[i].activo = 0;
            printf("Paciente con ID %d eliminado.\n", id);
            return;
        }
    }
    printf("Paciente no encontrado.\n");
}

// Menú principal
void menu() {
    int opcion;
    do {
        printf("\n--- Sistema de Gestión de Pacientes ---\n");
        printf("1. Agregar Paciente\n");
        printf("2. Buscar Paciente\n");
        printf("3. Listar Pacientes\n");
        printf("4. Eliminar Paciente\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                agregar_paciente();
                break;
            case 2:
                buscar_paciente();
                break;
            case 3:
                listar_pacientes();
                break;
            case 4:
                eliminar_paciente();
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (opcion != 5);
}

// Función principal
int main(){
    menu();
    return 0;
}