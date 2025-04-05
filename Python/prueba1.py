#[.,.,.,.,.,.,.,.,.,A,.,A,.,A,.,.,.,.] 
cad = ['.','.','.','.','.','.','.','.','.','A','.','A','.','A','.','.','.','.']
encontrar = ['.','A','.']
siu = 0

for i in range (len(cad)-1):
    if cad[i] == encontrar[siu]:
        siu += 1
    else:
        siu = 0
        continue
    if siu == len(encontrar):
        print("La cadena esta en la posicion: ",i-len(encontrar),i)
        print("El concha me la pela")