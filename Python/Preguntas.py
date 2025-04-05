puntaje = 0

print("Bienvenidos a preguntas random")

jugar = input("Quieres jugar? si/no  ")

if jugar.lower() != "si" and jugar != "s":
    quit()

print("Perfecto! juguemos :)")

respuesta = input("Que significa CPU? ")
if respuesta.lower() == "central processing unit" or respuesta.lower() == "unidad central de procesamiento":
    print("Correcto!")
    puntaje += 1
else:
    print("Incorrecto!")

respuesta = input("Que significa RAM? ")
if respuesta.lower() == "random access memory" or respuesta.lower() == "memoria de acceso aleatorio":
    print("Correcto!")
    puntaje += 1
else:
    print("Incorrecto!")

respuesta = input("Que significa PSU? ")
if respuesta.lower() == "power supply" or respuesta.lower() == "fuente de alimentacion":
    print("Correcto!")
    puntaje += 1
else:
    print("Incorrecto!")

print("Fin del juego")
print("Puntaje: "+ str(puntaje) +"/5")