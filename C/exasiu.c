#include <stdio.h>

int main(){
    int pasos[24], superados = 0, sedentarios = 0;
    int pasos_max = 0, dia_pasos_max = 0;

    // Pide la cantidad de pasos durante un mes
    printf("Ingrese la cantidad de pasos diarios durante un mes:\n");
    for (int i = 0; i < 24; i++) {
        printf("Día %d: ", i + 1);
        scanf("%d", &pasos[i]);

        if(pasos[i]<0){
            printf("Pasos invalidos\n");
            printf("Día %d:",i +1);
            scanf("%d",&pasos[i]);
        }

        // Contar días con más de 10,000 pasos y suma al contador para guardar los dias superados
        if (pasos[i] > 10000) {
            superados++;
        }

        // Contar días con menos de 1,000 pasos y suma al contador para guardar los dias sedentarios
        if (pasos[i] < 1000) {
            sedentarios++;
        }

        // Compara los dias y encuentra el maximo de los pasos y en que dia
        if (pasos[i] > pasos_max) {
            pasos_max = pasos[i];
            dia_pasos_max = i + 1;
        }
    }

    // Muestra los dias superados, sedentarios y el dia y los pasos maximos que dio
    printf("\nResultados del registro de pasos:\n");
    printf("Días con más de 10,000 pasos: %d\n", superados);
    printf("Días con menos de 1,000 pasos: %d\n", sedentarios);
    printf("El día con más pasos fue el día %d con %d pasos.\n", dia_pasos_max, pasos_max);

    return 0;
}