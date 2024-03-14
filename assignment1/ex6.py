s = input()
n = len(s)
for i in range(1, n+1):
    if n % i == 0:
        x = s[:i]
        x = x[::-1]
        y = s[i:]
        s = x + y

print(s)