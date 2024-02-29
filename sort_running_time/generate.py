import random
import sys

def gen():
    l = []
    for i in range(0, 1000000):
        val = random.randint(0, 10e10) + random.random()
        val = round(val, 10)
        l.append(val)
    return l

for i in range(1, 11):
    with open(f"input{i}.txt", "w") as file:
        l = gen()
        if i == 1:
            l.sort()
        if i == 2:
            l.sort(reverse = True)
        for j in l:
            file.write(f"{j} ")
