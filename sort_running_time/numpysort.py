import cProfile
import numpy
for i in range(1, 11):
    with open(f"input{i}.txt", "r") as file:
        x = file.readline()
    A = list(map(float, x.split()))
    cProfile.run('numpy.sort(A)')
