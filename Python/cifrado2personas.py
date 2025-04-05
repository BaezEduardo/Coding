import random

p = 47
alpha = 5

y = random.randint(2,p-2)

b = alpha**y % p

print(b)

a = 11

rB = a**y % p

print(rB)