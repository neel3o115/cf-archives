s = input()
if '0' not in s:
    n = s[1:]
else:
    n = s.replace('0','',1)
print(n)
