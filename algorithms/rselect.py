import math
from random import *
A = list(map(int, input("Enter your array and desired i order element: \n").split()))
i = int(input())

def RSelect(A, i):
    if len(A) == 1:
        return A[0]
    pivot = randint(0, len(A)-1)
    print(pivot)
    A[pivot], A[0] = A[0], A[pivot]
    j = 1
    k = 1
    while k < len(A):
        if A[k] < A[0]:
            A[j], A[k] = A[k], A[j]
            j += 1
        k += 1
    
    A[j-1], A[0] = A[0], A[j-1]
    if i == j:
        print(A)
        return A[i-1]
    elif j > i:
        print(A)
        return RSelect(A[:j-1], i)
    else:
        print(A)
        return RSelect(A[j:], i-j)

print(RSelect(A, i))