#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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
    struct Jugador jugadores[2];
    int numerojugadores;
};

struct Liga {
    struct Equipo libre[2];
    struct Equipo junior[2];
};
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

    for (int i = 0; i < 8; ++i) {
        inicializarEquipo(&(liga->libre[i]), "Equipo Libre");
    }

    for (int i = 0; i < 8; ++i) {
        inicializarEquipo(&(liga->junior[i]), "Equipo Junior");
    }
}

int main() {

  struct Liga torneo;
  inicializarLiga(&torneo);

  for(int i = 0; i < 8; i++)
  {
    printf("%d",torneo.libre[1].jugadores[1].nombrejugador);
    printf("%d",torneo.libre[1].jugadores[1].fecha);
    printf("%d",torneo.libre[1].jugadores[1].numero);
  }
  
  

  return 0;  
}
