n = int(input())
s = input()
s = s.lower()
alpha = 'abcdefghijklmnopqrstuvwxyz'

for i in range(n):
    if s[i] in alpha:
        alpha = alpha.replace(s[i], '')

if alpha == '':
    print('YES')
else:
    print('NO')