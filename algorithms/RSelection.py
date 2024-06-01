import math
from random import *
A = list(map(int, input("Enter your array and desired i order element: \n").split()))
i = int(input())

def RSelect(A, i, lo, hi):
    print(A[lo:hi])
    if hi-lo == 1:
        return A[lo]
    pivot = randint(lo, hi-1)
    print(pivot)
    A[pivot], A[lo] = A[lo], A[pivot]
    j = lo + 1
    k = lo + 1
    while k < hi:
        if A[k] < A[lo]:
            A[j], A[k] = A[k], A[j]
            j += 1
        k += 1
    
    A[j-1], A[lo] = A[lo], A[j-1]
    if i == j:
        print(A)
        return A[i-1]
    elif j > i:
        print(A)
        return RSelect(A, i, lo, j-1)
    else:
        print(A)
        return RSelect(A, i, j, hi)

print(RSelect(A, i, 0, len(A)))