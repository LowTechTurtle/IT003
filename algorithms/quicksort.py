import random
import cProfile
#n = int(input("Enter number of element in the array: "))
with open "input1.txt" as file:
    x = file.readline()
A = list(map(int, x.split()))

def quicksort(A, lo, hi):
    if hi - lo <= 1:
        return A[lo:hi]
    pivot = random.randint(lo, hi-1) 
    A[lo], A[pivot] = A[pivot], A[lo]

    i = lo + 1
    j = lo + 1
    while j < hi:
        if A[j] < A[lo]:
            A[i], A[j] = A[j], A[i]
            i += 1
        j += 1
    A[lo], A[i-1] = A[i-1], A[lo]
    quicksort(A, lo, i-1)
    quicksort(A, i, j)

    return A

cProfile.run('quicksort(A, 0, len(A))')
