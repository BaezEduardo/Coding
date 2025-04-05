#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct FechaNacimiento {
    int dia,mes,año;
};
struct Jugador {
    char nombrejugador[50];
    struct FechaNacimiento fecha;
    int numero;
};
struct Equipo {
    char nombreequipo[50];
    struct Jugador jugadores[10];
    int numerojugadores;
};
struct Liga {
    struct Equipo libre[8];
    struct Equipo junior[8];
    int numlibres;
    int numjuniors;
};

void removerEspacios(char *cadena) {
    int longitud = strlen(cadena);

    int inicio = 0;
    while (cadena[inicio] == ' ') {
        inicio++;
    }

    int fin = longitud - 1;
    while (fin >= 0 && (cadena[fin] == ' ' || cadena[fin] == '\n')) {
        fin--;
    }

    memmove(cadena, cadena + inicio, fin - inicio + 1);
    cadena[fin - inicio + 1] = '\0';
}
void minusculas(char *frase) {
    while (*frase) {
        *frase = tolower((unsigned char)*frase);
        frase++;
    }
}
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int esBisiesto(int año) {
    return (año % 4 == 0 && año % 100 != 0) || (año % 400 == 0);
}
int fechaValida(int dia, int mes, int año) {
    if (mes < 1 || mes > 12 || dia < 1) {
        return 0;
    }

    int diasEnMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes == 2 && esBisiesto(año)) {
        return dia <= 29;
    }

    return dia <= diasEnMes[mes];
}

void inicializarJugador(struct Jugador *jugador, const char *nombre, int dia, int mes, int año, int numero) {
    strcpy(jugador->nombrejugador, nombre);
    jugador->fecha.dia = dia;
    jugador->fecha.mes = mes;
    jugador->fecha.año = año;
    jugador->numero = numero;
}
void inicializarEquipo(struct Equipo *equipo, const char *nombreEquipo) {
    strcpy(equipo->nombreequipo, nombreEquipo);
    equipo->numerojugadores = 0;
}
void inicializarLiga(struct Liga *liga) {
    liga->numlibres = 0;
    liga->numjuniors = 0;

    for (int i = 0; i < 8; ++i) {
        inicializarEquipo(&(liga->libre[i]), "Equipo Libre");
    }

    for (int i = 0; i < 8; ++i) {
        inicializarEquipo(&(liga->junior[i]), "Equipo Junior");
    }
}

void RegistroEquipo(struct Liga *torneo, int esJunior) {
    char nombreequipo[50];
    int cont = 0;
    limpiarBuffer();

    if ((esJunior && torneo->numjuniors < 8) || (!esJunior && torneo->numlibres < 8)) {
        printf("\nIngrese la información requerida\n\n");
        printf("Nombre del equipo: ");
        fgets(nombreequipo, sizeof(nombreequipo), stdin);
        removerEspacios(nombreequipo);
        minusculas(nombreequipo);

        for (int i = 0; i < 8; i++) {
            if ((esJunior && strcmp(nombreequipo, torneo->junior[i].nombreequipo) == 0) ||
                (!esJunior && strcmp(nombreequipo, torneo->libre[i].nombreequipo) == 0)) {
                cont = 1;
            }
        }

        if (cont != 1) {
            if (esJunior) {
                strncpy(torneo->junior[torneo->numjuniors].nombreequipo, nombreequipo,
                        sizeof(torneo->junior[torneo->numjuniors].nombreequipo));
                torneo->numjuniors += 1;
            } else {
                strncpy(torneo->libre[torneo->numlibres].nombreequipo, nombreequipo,
                        sizeof(torneo->libre[torneo->numlibres].nombreequipo));
                torneo->numlibres += 1;
            }
            printf("\nEl equipo fue registrado con éxito!\n");
            printf("\nPresiona Enter para continuar...");
            getchar();
        } else {
            printf("\nLo sentimos, ya existe un equipo registrado con ese nombre.\n");
            printf("\nPresiona Enter para continuar...");
            getchar();
        }
    } else {
        printf("\nLo sentimos, ya no hay cupos libres en la liga.\n");
        printf("\nPresiona Enter para continuar...");
        getchar();
    }
}

void RegistroJugador(struct Liga *torneo, int esJunior) {
    int a, cont = 0;
    char nombreequipo[50];
    limpiarBuffer();

    printf("\nCual es el nombre del equipo en el que se va a registrar? ");
    fgets(nombreequipo, sizeof(nombreequipo), stdin);
    minusculas(nombreequipo);
    removerEspacios(nombreequipo);

    for (int i = 0; i < 8; i++) {
        if ((esJunior && strcmp(nombreequipo, torneo->junior[i].nombreequipo) == 0) ||
            (!esJunior && strcmp(nombreequipo, torneo->libre[i].nombreequipo) == 0)) {
            cont = 1;
            a = i;
            break;
        }
    }

    if (cont == 1) {
        if ((esJunior && torneo->junior[a].numerojugadores < 10) ||
            (!esJunior && torneo->libre[a].numerojugadores < 10)) {
            char nombrecompleto[50];
            int num, dia, mes, año;
            printf("\nIngrese la información requerida\n\n");
            printf("Nombre completo del jugador: ");
            fgets(nombrecompleto, sizeof(nombrecompleto), stdin);
            minusculas(nombrecompleto);
            removerEspacios(nombrecompleto);
            printf("Numero de jugador: ");
            scanf("%d", &num);
            printf("Fecha de nacimiento en números: (ej. DD:MM:AAAA)");
            printf("\nDia: ");
            scanf("%d", &dia);
            printf("Mes: ");
            scanf("%d", &mes);
            printf("Año: ");
            scanf("%d", &año);

            int edad = 2023 - año;

            if ((esJunior && edad > 12 && edad < 18) ||
                (!esJunior && edad > 18 && edad < 50) && fechaValida(dia, mes, año)) {
                struct Jugador *jugador;

                if (esJunior) {
                    jugador = &torneo->junior[a].jugadores[torneo->junior[a].numerojugadores];
                } else {
                    jugador = &torneo->libre[a].jugadores[torneo->libre[a].numerojugadores];
                }

                strncpy(jugador->nombrejugador, nombrecompleto, sizeof(jugador->nombrejugador));
                jugador->fecha.dia = dia;
                jugador->fecha.mes = mes;
                jugador->fecha.año = año;
                jugador->numero = num;

                printf("\nEl jugador fue registrado exitosamente\n");

                if (esJunior) {
                    torneo->junior[a].numerojugadores += 1;
                } else {
                    torneo->libre[a].numerojugadores += 1;
                }

                limpiarBuffer();
                printf("\nPresiona Enter para continuar...");
                getchar();
            } else {
                printf("La fecha de nacimiento no es válida, el jugador es menor de edad o el jugador tiene más de 50 años");
                limpiarBuffer();
                printf("\nPresiona Enter para continuar...");
                getchar();
            }
        } else {
            printf("Lo sentimos, ya no hay cupos en el equipo");
            limpiarBuffer();
            printf("\nPresiona Enter para continuar...");
            getchar();
        }
    } else {
        printf("\nEse equipo no existe\n");
        printf("\nPresiona Enter para continuar...");
        getchar();
    }
}

void InfoEquipo(struct Liga *torneo) {
    char nombreequipo[50];
    int a, cont = 0;
    limpiarBuffer();

    printf("\nCual es el nombre del equipo que esta buscando? ");
    fgets(nombreequipo, sizeof(nombreequipo), stdin);
    removerEspacios(nombreequipo);
    minusculas(nombreequipo);

    for (int i = 0; i < 8; i++) {
        if (strcmp(nombreequipo, torneo->junior[i].nombreequipo) == 0) {
            cont = 1;
            a = i;
            break;
        } else if (strcmp(nombreequipo, torneo->libre[i].nombreequipo) == 0) {
            cont = 2;
            a = i;
            break;
        }
    }

    if (cont == 1 || cont == 2) {
        printf("\nNombre equipo: %s", (cont == 1) ? torneo->junior[a].nombreequipo : torneo->libre[a].nombreequipo);
        printf(", número de jugadores: %d\n", (cont == 1) ? torneo->junior[a].numerojugadores : torneo->libre[a].numerojugadores);

        if ((cont == 1 ? torneo->junior[a].numerojugadores : torneo->libre[a].numerojugadores) > 5) {
            printf("\nEstado: Completo");
        } else {
            printf("\nEstado: Incompleto\n");
        }

        printf("\nJugadores:\n");
        struct Jugador *jugadores = (cont == 1) ? torneo->junior[a].jugadores : torneo->libre[a].jugadores;
        int numJugadores = (cont == 1) ? torneo->junior[a].numerojugadores : torneo->libre[a].numerojugadores;

        for (int i = 0; i < numJugadores; i++) {
            printf("\nNombre jugador: %s\n", jugadores[i].nombrejugador);
            printf("Numero de jugador: %d\n", jugadores[i].numero);
            printf("Fecha de nacimiento: %d/%d/%d\n", jugadores[i].fecha.dia, jugadores[i].fecha.mes, jugadores[i].fecha.año);
        }

        printf("\nPresiona Enter para continuar...");
        getchar();
    } else {
        printf("No se encontro un equipo con ese nombre");
        printf("\nPresiona Enter para continuar...");
        getchar();
    }
}

void InfoEquipos(struct Liga *torneo) {
    printf("\nLista de equipos: \n");
    printf("\nLiga Junior\n");  
    
    if (torneo->numjuniors>0){
        for (int i = 0; i < torneo->numjuniors; i++){
            printf("Nombre equipo: %s",torneo->junior[i].nombreequipo);
            printf(", número de jugadores: %d\n",torneo->junior[i].numerojugadores);
        }
    }else{printf("\nNo se encontraron equipos en la liga junior\n");}

    printf("\nLiga Libre\n");

    if (torneo->numlibres>0){
        for (int i = 0; i < torneo->numlibres; i++){
            printf("Nombre equipo: %s",torneo->libre[i].nombreequipo);
            printf(", número de jugadores: %d\n",torneo->libre[i].numerojugadores);
        }
    }else{printf("\nNo se encontraron equipos en la liga libre\n");}
    
    limpiarBuffer();
    printf("\nPresiona Enter para continuar...");
    getchar();
}

void BuscarPorNombre(struct Liga *torneo, int *liga, int *jugador) {
    char nombrejugador[50];
    limpiarBuffer();
    printf("\nCual es el nombre del jugador que esta buscando? ");
    fgets(nombrejugador, sizeof(nombrejugador), stdin);
    removerEspacios(nombrejugador);
    minusculas(nombrejugador);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < torneo->junior[i].numerojugadores; j++) {
            if (strcmp(nombrejugador, torneo->junior[i].jugadores[j].nombrejugador) == 0) {
                *liga = i;
                *jugador = j;
                return;
            }
        }

        for (int k = 0; k < torneo->libre[i].numerojugadores; k++) {
            if (strcmp(nombrejugador, torneo->libre[i].jugadores[k].nombrejugador) == 0) {
                *liga = i;
                *jugador = k;
                return;
            }
        }
    }
}

void MostrarInformacion(struct Liga *torneo, int liga, int jugador) {
    if (liga >= 0 && liga < 8) {
        if (jugador >= 0 && jugador < torneo->junior[liga].numerojugadores) {
            printf("\nNombre equipo: %s\n", torneo->junior[liga].nombreequipo);
            printf("Nombre jugador: %s\n", torneo->junior[liga].jugadores[jugador].nombrejugador);
            printf("Numero de jugador: %d\n", torneo->junior[liga].jugadores[jugador].numero);
            printf("Fecha de nacimiento: %d/%d/%d\n", torneo->junior[liga].jugadores[jugador].fecha.dia,
                   torneo->junior[liga].jugadores[jugador].fecha.mes, torneo->junior[liga].jugadores[jugador].fecha.año);
        } else if (jugador >= 0 && jugador < torneo->libre[liga].numerojugadores) {
            printf("\nNombre equipo: %s\n", torneo->libre[liga].nombreequipo);
            printf("Nombre jugador: %s\n", torneo->libre[liga].jugadores[jugador].nombrejugador);
            printf("Numero de jugador: %d\n", torneo->libre[liga].jugadores[jugador].numero);
            printf("Fecha de nacimiento: %d/%d/%d\n", torneo->libre[liga].jugadores[jugador].fecha.dia,
                   torneo->libre[liga].jugadores[jugador].fecha.mes, torneo->libre[liga].jugadores[jugador].fecha.año);
        } else {
            printf("No se encontro un jugador con ese nombre");
        }
    } else {
        printf("No se encontro un jugador con ese nombre");

    printf("\nPresiona Enter para continuar...");
    getchar();}
}

void InfoJugador(struct Liga *torneo) {
    int opcion, num, liga, jugador;

    printf("\nComo desea buscar al jugador?\n");
    printf("1. Nombre\n");
    printf("2. Número de jugador\n");
    printf("3. Regresar al menu anterior\n");
    printf("\nIngrese su opcion: ");
    if (scanf("%d", &opcion) == 1) {
        switch (opcion) {
            case 1:
                BuscarPorNombre(torneo, &liga, &jugador);
                MostrarInformacion(torneo, liga, jugador);
                limpiarBuffer();
                printf("\nPresiona Enter para continuar...");
                getchar();
                break;
            case 2:
                printf("\nCual es el numero del jugador que esta buscando?");
                if (scanf("%d", &num) == 1) {
                    for (int i = 0; i < torneo->numjuniors; i++) {
                        for (int j = 0; j < torneo->junior[i].numerojugadores; j++) {
                            if (num == torneo->junior[i].jugadores[j].numero) {
                                liga = i;
                                jugador = j;
                                MostrarInformacion(torneo, liga, jugador);
                                limpiarBuffer();
                                printf("\nPresiona Enter para continuar...");
                                getchar();
                                return;
                            }
                        }
                    }

                    for (int i = 0; i < torneo->numlibres; i++) {
                        for (int k = 0; k < torneo->libre[i].numerojugadores; k++) {
                            if (num == torneo->libre[i].jugadores[k].numero) {
                                liga = i;
                                jugador = k;
                                MostrarInformacion(torneo, liga, jugador);
                                limpiarBuffer();
                                printf("\nPresiona Enter para continuar...");
                                getchar();
                                return;
                            }
                        }
                    }
                } else {
                    printf("Entrada no válida. Por favor, ingrese un número entero.\n");
                }

                limpiarBuffer();
                printf("\nPresiona Enter para continuar...");
                getchar();
                break;
            case 3:
                printf("\nRegresando al menú anterior!\n");
                break;
            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
                limpiarBuffer();
                printf("\nPresiona Enter para continuar...");
                getchar();
        }
    } else {
        printf("Entrada no válida. Por favor, ingrese un número entero.\n");
        limpiarBuffer();
        printf("\nPresiona Enter para continuar...");
        getchar();
    }
}

void InfoJugadores(struct Liga *torneo) {

    printf("\nLista de jugadores: \n");
    printf("\nLiga Junior\n");  
    if (torneo->numjuniors>0){
        for (int i = 0; i < torneo->numjuniors; i++){
            for (int j = 0; j < torneo->junior[i].numerojugadores; j++){
                printf("\nNombre equipo: %s\n",torneo->junior[i].nombreequipo);
                printf("Nombre jugador: %s\n",torneo->junior[i].jugadores[j].nombrejugador);
                printf("Numero de jugador: %d\n",torneo->junior[i].jugadores[j].numero);
                printf("Fecha de nacimiento: %d/%d/%d\n",torneo->junior[i].jugadores[j].fecha.dia,torneo->junior[i].jugadores[j].fecha.mes,torneo->junior[i].jugadores[j].fecha.año);
            }
        }
    } else{printf("\nNo se encontraron jugadores en la liga junior\n");}

    printf("\nLiga Libre\n");
    if (torneo->numlibres>0){
        for (int i = 0; i < torneo->numlibres; i++){
            for (int j = 0; j < torneo->libre[i].numerojugadores; j++){
                printf("\nNombre equipo: %s\n",torneo->libre[i].nombreequipo);
                printf("Nombre jugador: %s\n",torneo->libre[i].jugadores[j].nombrejugador);
                printf("Numero de jugador: %d\n",torneo->libre[i].jugadores[j].numero);
                printf("Fecha de nacimiento: %d/%d/%d\n",torneo->libre[i].jugadores[j].fecha.dia,torneo->libre[i].jugadores[j].fecha.mes,torneo->libre[i].jugadores[j].fecha.año);
            }
        }
    } else{printf("\nNo se encontraron jugadores en la liga libre\n");}
    
    limpiarBuffer();
    printf("\nPresiona Enter para continuar...");
    getchar();
}

void MenuRegistroEquipo(struct Liga *torneo) {
    int opcion = 0;
    do
    {
        printf("\nRegistro Equipo.");
        printf("\nEn que liga desea registrarse?\n\n");
        printf("1. Junior\n");
        printf("2. Libre\n");
        printf("3. Volver al menú anterior\n");

        printf("\nIngrese su opción: ");
        if (scanf("%d", &opcion) == 1) {
            switch (opcion) {
                case 1:
                    RegistroEquipo(torneo,1);
                    break;
                case 2:
                    RegistroEquipo(torneo,0);
                    break;
                case 3:
                    printf("\nRegresando al menú anterior!\n");
                    break;
                default:
                    printf("Opción no válida. Inténtelo de nuevo.\n");
                    limpiarBuffer();
                    printf("\nPresiona Enter para continuar...");
                    getchar();
            }
        } else {printf("Entrada no válida. Por favor, ingrese un número entero.\n");
                limpiarBuffer();
                printf("\nPresiona Enter para continuar...");
                getchar();}
    } while (opcion!=3);
}

void MenuRegistroJugador(struct Liga *torneo) {
    int opcion = 0;
    do
    {
        printf("\nRegistro Jugador.");
        printf("\nEn que liga desea registrarse?\n\n");
        printf("1. Junior\n");
        printf("2. Libre\n");
        printf("3. Volver al menú anterior\n");

        printf("\nIngrese su opción: ");
        if (scanf("%d", &opcion) == 1) {
            switch (opcion) {
                case 1:
                    RegistroJugador(torneo,1);
                    break;
                case 2:
                    RegistroJugador(torneo,0);
                    break;
                case 3:
                    printf("\nRegresando al menú anterior!\n");
                    break;
                default:
                    printf("Opción no válida. Inténtelo de nuevo.\n");
                    limpiarBuffer();
                    printf("\nPresiona Enter para continuar...");
                    getchar();
            }
        } else {printf("Entrada no válida. Por favor, ingrese un número entero.\n");
                limpiarBuffer();
                printf("\nPresiona Enter para continuar...");
                getchar();}
    } while (opcion!=3);
}

int BuscarEquipo(struct Liga *torneo, const char *nombreequipo) {
    for (int i = 0; i < torneo->numjuniors; i++) {
        if (strcmp(nombreequipo, torneo->junior[i].nombreequipo) == 0) {
            return i + 1;
        }
    }

    for (int i = 0; i < torneo->numlibres; i++) {
        if (strcmp(nombreequipo, torneo->libre[i].nombreequipo) == 0) {
            return -(i + 1); 
        }
    }

    return 0;  
}

void EliminarEquipo(struct Liga *torneo, int liga, int numEquipos, int tamanoLiga, const char *tipoLiga) {
    if (liga > 0 && liga <= numEquipos) {
        if (tamanoLiga == 0) {
            for (int i = liga - 1; i < numEquipos - 1; i++) {
                if (strcmp(tipoLiga, "junior") == 0) {
                    torneo->junior[i] = torneo->junior[i + 1];
                } else {
                    torneo->libre[i] = torneo->libre[i + 1];
                }
            }
            numEquipos--;
            printf("\nEquipo eliminado con éxito.\n");
        } else {
            printf("\nPrimero debe eliminar a los jugadores del equipo.\n");
        }
    } else {
        printf("\nNo se encontró un equipo con ese nombre en la liga %s.\n", tipoLiga);
    }

    printf("\nPresiona Enter para continuar...");
    limpiarBuffer();
    getchar();
}

void RemoverEquipo(struct Liga *torneo) {
    int cont = 0;
    char nombreequipo[50];
    limpiarBuffer();

    printf("Cual es el nombre del equipo que desea remover? ");
    fgets(nombreequipo, sizeof(nombreequipo), stdin);
    minusculas(nombreequipo);
    removerEspacios(nombreequipo);

    int liga = BuscarEquipo(torneo, nombreequipo);

    if (liga != 0) {
        const char *tipoLiga = (liga > 0) ? "junior" : "libre";
        int numEquipos = (liga > 0) ? torneo->numjuniors : torneo->numlibres;
        int tamanoLiga = (liga > 0) ? torneo->junior[liga - 1].numerojugadores : torneo->libre[-liga - 1].numerojugadores;

        EliminarEquipo(torneo, abs(liga), numEquipos, tamanoLiga, tipoLiga);
    } else {
        printf("\nNo se encontró un equipo con ese nombre.\n");
        printf("\nPresiona Enter para continuar...");
        limpiarBuffer();
        getchar();
    }
}

void RemoverJugador(struct Liga *torneo) {
    int a, b, cont = 0;
    char nombrejugador[50];
    limpiarBuffer();

    printf("Cual es el nombre del jugador que desea remover? ");
    fgets(nombrejugador, sizeof(nombrejugador), stdin);
    minusculas(nombrejugador);
    removerEspacios(nombrejugador);

    for (int i = 0; i < torneo->numjuniors; i++){
        for (int j = 0; j < torneo->junior[i].numerojugadores; j++){
            if (strcmp(nombrejugador,torneo->junior[i].jugadores[j].nombrejugador)==0){
                cont=1;
                a=i;
                b=j;
                break;
            }
        }
    }
    
    for (int i = 0; i < torneo->numlibres; i++){
        for (int j = 0; j < torneo->libre[i].numerojugadores; j++){
            if (strcmp(nombrejugador,torneo->libre[i].jugadores[j].nombrejugador)==0){
                cont=2;
                a=i;
                b=j;
                break;
            }
        }
    }
    
    switch (cont){
        case 1:
            for (int i = b; i < torneo->junior[a].numerojugadores-1; i++){
                torneo->junior[a].jugadores[i] = torneo->junior[a].jugadores[i + 1];
            }
            torneo->junior[a].numerojugadores--;
            printf("\nJugador eliminado con éxito.\n");
            printf("\nPresiona Enter para continuar...");
            getchar();
            break;
        case 2:
            for (int i = b; i < torneo->libre[a].numerojugadores-1; i++){
                torneo->libre[a].jugadores[i] = torneo->libre[a].jugadores[i + 1];
            }
            torneo->libre[a].numerojugadores--;
            printf("\nJugador eliminado con éxito.\n");
            printf("\nPresiona Enter para continuar...");
            getchar();
            break;
        default:
            printf("\nNo se encontro un jugador con ese nombre.\n");
            printf("\nPresiona Enter para continuar...");
            getchar();
            break;
    }
}

void MenuInformacionEquipo(struct Liga *torneo) {
    int opcion = 0;
    do
    {
        printf("\nQuiere ver un equipo en especifico o la lista completa de equipos?\n\n");
        printf("1. Equipo en especifico\n");
        printf("2. Lista completa de equipos\n");
        printf("3. Regresar al menu anterior\n");
        printf("\nIngrese su opción: ");
        if (scanf("%d", &opcion) == 1) {
            switch (opcion) {
                case 1:
                    InfoEquipo(torneo);
                    break;
                case 2:
                    InfoEquipos(torneo);
                    break;
                case 3:
                    printf("\nRegresando al menú anterior!\n");
                    break;
                default:
                    printf("Opción no válida. Inténtelo de nuevo.\n");
                    limpiarBuffer();
                    printf("\nPresiona Enter para continuar...");
                    getchar();
            }
        } else {printf("Entrada no válida. Por favor, ingrese un número entero.\n");
                limpiarBuffer();
                printf("\nPresiona Enter para continuar...");
                getchar();}
    } while (opcion!=3);
}

void MenuInformacionJugador(struct Liga *torneo) {
    int opcion = 0;
    do 
    {
        printf("\nQuiere ver un jugador en especifico o la lista completa de jugadores?\n\n");
        printf("1. Jugador en especifico\n");
        printf("2. Lista completa de jugadores\n");
        printf("3. Regresar al menu anterior\n");
        printf("\nIngrese su opción: ");
        if (scanf("%d", &opcion) == 1) {
            switch (opcion) {
                case 1:
                    InfoJugador(torneo);
                    break;
                case 2:
                    InfoJugadores(torneo);
                    break;
                case 3:
                    printf("\nRegresando al menú anterior!\n");
                    break;
                default:
                    printf("Opción no válida. Inténtelo de nuevo.\n");
                    limpiarBuffer();
                    printf("\nPresiona Enter para continuar...");
                    getchar();
            }   
        } else {printf("Entrada no válida. Por favor, ingrese un número entero.\n");
                limpiarBuffer();
                printf("\nPresiona Enter para continuar...");
                getchar();}
    } while (opcion!=3);
}

int main() {

    struct Liga torneo;
    inicializarLiga(&torneo);

    int opcion=0;
    do
    {
        printf("\nSeleccione una opcion: \n\n");
        printf("1. Registrar equipo.\n");
        printf("2. Registrar jugador.\n");
        printf("3. Eliminar equipo.\n");
        printf("4. Eliminar jugador.\n");
        printf("5. Mostrar información equipo.\n");
        printf("6. Mostrar información jugador.\n");
        printf("7. Salir\n");
        printf("\nIngrese su opción: ");
        if (scanf("%d", &opcion) == 1) {
            switch (opcion) {
                case 1:
                    MenuRegistroEquipo(&torneo);
                    break;
                case 2:
                    MenuRegistroJugador(&torneo);
                    break;
                case 3:
                    RemoverEquipo(&torneo);
                    break;
                case 4:
                    RemoverJugador(&torneo);
                    break;
                case 5:
                    MenuInformacionEquipo(&torneo);
                    break;
                case 6:
                    MenuInformacionJugador(&torneo);
                    break;
                case 7:
                    printf("Saliendo del programa. Adiós!\n");
                    break;
                default:
                    printf("Opción no válida. Inténtelo de nuevo.\n");
                    limpiarBuffer();
                    printf("\nPresiona Enter para continuar...");
                    getchar();
            }
        } else {printf("Entrada no válida. Por favor, ingrese un número.\n");
                limpiarBuffer();
                printf("\nPresiona Enter para continuar...");
                getchar();}
    } while (opcion!=7);
  return 0;  
}

