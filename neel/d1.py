n = int(input())
s = input()
a = [-1]*n

for i in range(n):
    if s[i] == ')':
        a[i] = 1


print(s)