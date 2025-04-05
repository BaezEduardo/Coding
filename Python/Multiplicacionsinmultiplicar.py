def multiply(a,b):
    if a == 0 or b == 0:
        return 0
    res = 0
    for i in range(b):
        res = res + a
    return res
    
print(multiply(10,351))
print(multiply(7,0))
print(multiply(0,2))
print(multiply(5,3))
