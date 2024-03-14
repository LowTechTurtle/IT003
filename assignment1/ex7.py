s1 = input()
s2 = input()
count = 0
x = ""
temp = ""
for i in range(len(s1)-1, -1, -1):
    x = s1[i:]
    if s2.startswith(x):
        temp = x

answer = s1 + s2[len(temp):]

print(len(answer))
print(answer)