x = int(input())
l = list(map(int, input().split()))

l.sort()

res = 0
for i in range(0, x):
    res += -(x-1-i)*l[i] + i*l[i]

print(res)
