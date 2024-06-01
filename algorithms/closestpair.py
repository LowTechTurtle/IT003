from math import *
n = int(input("Enter the number of points: "))
A = []
for i in range(0, n):
    x = input().split()
    a = int(x[0])
    b = int(x[1])
    A.append((a, b))

Px = sorted(A, key = lambda x: x[0])
Py = sorted(A, key = lambda x: x[1])

def distance(x, y):
    return sqrt(pow(x[0] - y[0], 2) + pow(x[1] - y[1], 2))

def ClosestPair(Px, Py):
#base case
    if len(Px) == 1:
        print("[debug]: Somehow Px reduced to 1 element")
        return Px[0], Px[0]

    if len(Px) == 2:
        return (Px[0], Px[1])

    if len(Px) == 3:
        x1 = distance(Px[0], Px[1])
        x2 = distance(Px[0], Px[2])
        x3 = distance(Px[1], Px[2])
        best = min(min(x1, x2), x3)
        if best == x1:
            return Px[0], Px[1]

        if best == x2:
            return Px[0], Px[2]

        if best == x3:
            return Px[1], Px[2]

#recursive case
    mid = len(Px) // 2
    Lx = sorted(Px[:mid], key = lambda x: x[0])
    Ly = sorted(Px[:mid], key = lambda x: x[1])
    Rx = sorted(Px[mid:], key = lambda x: x[0])
    Ry = sorted(Px[mid:], key = lambda x: x[1])

    l1, l2 = ClosestPair(Lx, Ly)
    r1, r2 = ClosestPair(Rx, Ry)

    x1 = distance(l1, l2)
    x2 = distance(r1, r2)

    delta = min(x1, x2)
    s = ClosestSplitPair(Px, Py, delta)
    if s:
        s1, s2 = s
        x3 = distance(s1, s2)
    
    best = min(x1, x2)
    if s:
        best = min(best, x3)
    if best == x1:
        return (l1, l2)
    if best == x2:
        return (r1, r2)
    if best == x3:
        return (s1, s2)

def ClosestSplitPair(Px, Py, delta):
    x = Px[len(Px)//2 - 1]
    Sy = []
    for point in Py:
        if point[0] < x[0] + delta and point[0] > x[0] - delta:
            Sy.append(point)
    
    best = delta
    best_pair = None
    for i in range(0, len(Sy)):
        for j in range(1, min(8, len(Sy) - i)):
            dis = distance(Sy[i], Sy[i+j])
            if dis < best:
                best = dis
                best_pair = (Sy[i], Sy[i+j])

    return best_pair

print(ClosestPair(Px, Py))