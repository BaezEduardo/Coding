def Primo(n):
    if n < 2:
        return False
    else:
        for i in range(2,int(n**0.5)+1):
            if n % i == 0:
                return False
        return True

n = 0
if Primo(n):
    print("El numero es primo")
else:
    print("El numero no es primo")