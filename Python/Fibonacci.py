def fibonacci(n):
    a, b = 0, 1
    print(0)
    print(1)
    for i in range(n-1):
        a, b = b, a+b
        print(b)

fibonacci(50)