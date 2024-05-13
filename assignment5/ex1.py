a, x = map(int, input().split())

res = ''
while a > 0:
    y = a % x
    res += str(y)
    a = a // x

res = res[::-1]
print(res)