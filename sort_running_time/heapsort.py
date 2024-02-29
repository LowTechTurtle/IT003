import cProfile

def build_heap(A, i, n):
    inx = i
    l = 2*i+1
    r = 2*i+2

    if l < n:
        if A[inx] < A[l]:
            inx = l

    if r < n:
        if A[inx] < A[r]:
            inx = r

    if inx == l:
        A[l], A[i] = A[i], A[l]
        build_heap(A, l, n)
    if inx == r:
        A[r], A[i] = A[i], A[r]
        build_heap(A, r, n)

def heap_sort(A):
    for i in range(len(A) - 1, -1, -1):
        build_heap(A, i, len(A))
 
    for i in range(len(A)-1, 0, -1):
        A[i], A[0] = A[0], A[i] 
        build_heap(A, 0, i)

    return A

for i in range(1, 11):
    with open(f"input{i}.txt", "r") as file:
        x = file.readline()
    A = list(map(float, x.split()))
    cProfile.run('heap_sort(A)')
