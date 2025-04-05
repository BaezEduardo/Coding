import random

maximo = input("Dame un numero: ")

if maximo.isdigit():
    maximo = int(maximo)

    if maximo <= 0:
        print("Ingrese un numero mayor a 0 la proxima vez.")
        quit()
else:
    print("Ingrese un numero entero la proxima vez")

numero = random.randint(0,maximo)
intentos = 0

while True:
    intentos += 1
    respuesta = input("Adivina: ")
    if respuesta.isdigit():
        respuesta = int(respuesta)
    else:
        print("Utiliza un numero la proxima vez")
        continue
    
    if respuesta == numero:
        print("Correcto, lo adivinaste")
        break
    elif respuesta < numero:
        print("El numero es mas grande!")
    else:
        print("El numero es mas pequeño!")

print("Adivinaste en",intentos,"intentos")