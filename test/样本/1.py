import random
T = random.randint(1, 5)
print(T);
for i in range(T) :
    n = random.randint(1, 10)
    print(n)
    for j in range(n) :
        x = random.randint(100, 100000)
        print(x, end=" ")
    print()
