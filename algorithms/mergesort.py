A = list(map(int, input("Enter the elements: ").split()))

def merge_sort(A):
    if len(A) <= 1:
        return A

    mid = len(A) // 2

    left = merge_sort(A[:mid])
    right = merge_sort(A[mid:])

    i = 0
    j = 0
    k = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            A[k] = left[i]
            i += 1
        else:
            A[k]= right[j]
            j += 1
        k += 1

    if i >= len(left):
        while j < len(right):
            A[k] = right[j]
            k += 1
            j += 1
    else:
        while i < len(left):
            A[k] = left[i]
            k += 1
            i += 1

    return A

print(merge_sort(A))
