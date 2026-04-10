v = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']

def rec(s,i):
    global v

    if i < 0:
        return 0

    if s[i] in v: 
        return 1+rec(s,i-1)
    return rec(s,i-1)

s = input()
print(rec(s,len(s)-1))