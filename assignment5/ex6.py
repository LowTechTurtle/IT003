x = int(input())
l = list(map(int, input().split()))
s = set(l)
ll = list(s)

ll.sort()
print(len(ll))
for i in ll:
    print(i, end=' ')
