lista = [7,8,6,1,3,2,5,4,9]

for i in range(len(lista)):
    for j in range(len(lista)-i-1):
        if lista[j] > lista[j+1]:
            temp = lista[j]
            lista[j] = lista[j+1]
            lista[j+1] = temp

print(lista)
