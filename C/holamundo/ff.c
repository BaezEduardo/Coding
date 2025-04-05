caso 1:
			imprimirInfoEquipo(cont, a, categ)
		caso 2:
			imprimirInfoEquipo(cont, a, categ)
		En otro caso:
			Escribir (“El equipo no se encontró”)
	FinSegun
Fin

InfoEquipos(Entrada: Registro liga categ[2])
	Entero i
Inicio
	Escribir (“\nLista de equipos\n”)
	Escribir (“\nLiga junior\n”)
	Si (categ[0].numEquipos > 0) entonces
		Para i ← 0 Hasta i < categ[0].numEquipos Incremento 1 hacer
Escribir ("Nombre equipo: ", categ[0].equipos[i].nombreequipo);
Escribir (", número de jugadores: \n", categ[0].equipos[i].numerojugadores)
		FinPara
	Sino
		Escribir ("\nNo se encontraron equipos en la liga junior\n")
FinSi
Escribir (“\nLiga libre\n”)
Si (categ[1].numEquipos > 0) entonces
		Para i ← 0 Hasta i < categ[1].numEquipos Incremento 1 hacer
Escribir ("Nombre equipo: ", categ[1].equipos[i].nombreequipo);
Escribir (", número de jugadores: \n", categ[1].equipos[i].numerojugadores)
		FinPara
	Sino
		Escribir ("\nNo se encontraron equipos en la liga libre\n")
FinSi
Fin
ImprimirInfoJugadorNombre(Entrada: Entero n Registro liga categ[2])
Inicio
		Escribir ("\nNombre equipo: ", categ[n-1].equipo.[a].nomequipo)
		Escribir ("Nombre jugador: ", categ[n-1].equipo.[a].jugadores[b].nombre)
Escribir ("Numero de jugador: ", categ[n-1].equipo.[a].jugadores[b].numero)
Escribir ("Fecha de nacimiento: ", categ[n-1].equipo.[a].jugadores[b].fecha.dia, “/”, categ[n-1].equipo.[a].jugadores[b].fecha.mes, “/”, categ[n-1].equipo.[a].jugadores[b].fecha.año)
Fin

InfoJugador(Entrada: Entero n Registro liga categ[2])
Cadena nombrejugador
Entero a, b, num, opcion, cont, j
Inicio
	cont ← i
Escribir ("\nComo desea buscar al jugador?\n");
Escribir ("1. Nombre\n");
Escribir ("2. Número de jugador\n");
Escribir ("3. Regresar al menu anterior\n");
Escribir ("\nIngrese su opcion: ");
Leer (opcion)
if (opcion == 1) {
Segun Sea (opcion)
caso 1:
Escribir ("\nCual es el nombre del jugador que esta buscando? ")
Leer (nombrejugador)
QuitarEspacios(nombrejugador)
minusculas(nombrejugador)
Para i← 0 Hasta 7 Incremento 1 hacer
Para j←0 Hasta j<categ[0].equipos[i].numeroJugadore Incremento 1 Hacer

						Si (nombreJugador == categ[n].equipos[i].nombre)
							cont ← 1
							a ← i
							b = j
							i ← i + 1
						FinSi
					FinPara
Para j←0 Hasta j<categ[0].equipos[i].numeroJugadore Incremento 1 Hacer

						Si (nombreJugador == categ[n].equipos[i].nombre)
							cont ← 2
							a ← i
							b = j
							i ← i + 1
						FinSi
					FinPara
				FinPara
Segun sea (cont)
Caso1:
ImprimirInfoJugadorNombre(cont, categ)
Caso2:
ImprimirInfoJugadorNombre(cont, categ)
En otro caso:
Escribir("No se encontro un jugador con ese nombre") 
				FinSegun
caso 2:
Escribir ("\n¿Cual es el numero del jugador que esta buscando?");
Leer (num)
Si (num) == 1)
	Para i= 0 Hasta i < categ[0].numEquipos Incremento 1 Hacer
Para j = 0 Hasta  j < categ[0].equipos[i].numjugadores Incremento 1 Hacer
Si (num == categ[0].equipos[i].jugadores[j].numero){
Escribir ("\nLiga Junior\n");
Escribir ("Nombre equipo: ", categ[0].equipos[i].nomequipo);
Escribir("Nombre jugador: ", categ[0].equipos[i].jugadores[j].nomjugador);
Escribir ("Numero de jugador: ", categ[0].equipos[i].jugadores[j].numero);
Escribir ("Fecha de nacimiento: ", categ[0].equipos[i].jugadores[j].fecha.dia, “/”, categ[0].equipos[i].jugadores[j].fecha.mes, “/”, categ[0].equipos[i].jugadores[j].fecha.año);
			FinSi
		FinPara
Para i= 0 Hasta i < categ[1].numEquipos Incremento 1 Hacer
Para j = 0 Hasta  j < categ[1].equipos[i].numjugadores Incremento 1 Hacer
Si (num == categ[1].equipos[i].jugadores[j].numero){
Escribir ("\nLiga Libre\n");
Escribir ("Nombre equipo: ", categ[1].equipos[i].nomequipo);
Escribir("Nombre jugador: ", categ[1].equipos[i].jugadores[j].nomjugador);
Escribir ("Numero de jugador: ", categ[1].equipos[i].jugadores[j].numero);
Escribir ("Fecha de nacimiento: ", categ[1].equipos[i].jugadores[j].fecha.dia, “/”, categ[1].equipos[i].jugadores[j].fecha.mes, “/”, categ[1].equipos[i].jugadores[j].fecha.año);
			FinSi
		FinPara
case 3:
Escribir ("\nRegresando al menú anterior!\n");
En otro caso:
Escribir ("Opción no válida. Inténtelo de nuevo.\n");
		FinSegun
Sino
Escribir ("Entrada no válida. Por favor, ingrese un número entero.\n");
	FinSi
Fin
InfoJugadores(Entrada: Registro liga categ[2])
	Entero i, j
Inicio
Escribir ("\nLista de jugadores: \n");
Escribir ("\nLiga Junior\n");  
Si (categ[0].numjuniors>0){
Para i ← 0 Hasta i < categ[0]->numjuniors Incremento 1 Hacer
Para j ← 0 Hasta j < categ[0].equiposr[i].numerojugadores Incremento 1 Hacer
Escribir ("\nNombre equipo: ", categ[0].equiposr[i].nombreEquipo, “\n”)
Escribir ("Nombre jugador: ", categ[0].equiposr[i].jugadores[j].nombre, “\n”)
Escribir ("Numero de jugador: ", categ[0].equiposr[i].jugadores[j].numero, “\n”)
Escribir ("Fecha de nacimiento: ", categ[0].equiposr[i].jugadores[j].fecha.dia, “/”,  categ[0].equiposr[i].jugadores[j].fecha.mes, “/”, categ[0].equiposr[i].jugadores[j].fecha.año, “\n”)
			FinPara
		FinPara
Sino 
Escribir ("\nNo se encontraron jugadores en la liga junior\n")
	FinSi	
    	Escribir ("\nLiga Libre\n");
Si (categ[1].numjuniors>0){
Para i ← 0 Hasta i < categ[1]->numjuniors Incremento 1 Hacer
Para j ← 0 Hasta j < categ[1].equiposr[i].numerojugadores Incremento 1 Hacer
Escribir ("\nNombre equipo: ", categ[1].equiposr[i].nombreEquipo, “\n”)
Escribir ("Nombre jugador: ", categ[1].equiposr[i].jugadores[j].nombre, “\n”)
Escribir ("Numero de jugador: ", categ[].equiposr[i].jugadores[j].numero, “\n”)
Escribir ("Fecha de nacimiento: ", categ[1].equiposr[i].jugadores[j].fecha.dia, “/”,  categ[1].equiposr[i].jugadores[j].fecha.mes, “/”, categ[1].equiposr[i].jugadores[j].fecha.año, “\n”)
			FinPara
		FinPara
Sino
Escribir ("\nNo se encontraron jugadores en la liga junior\n")
	FinSi
Fin
