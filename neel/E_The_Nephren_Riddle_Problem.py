import sys
sys.setrecursionlimit(100005)

def lnn(n):
    return 143*(1<<n)-68

q = int(input())

foo = 'What are you doing at the end of the world? Are you busy? Will you save us?'
one = 'What are you doing while sending "'
two = '"? Are you busy? Will you send "'
tre = '"?'

def rec(n,k):
    global foo,one,two,tre

    if n == 0:
        if k > 75:
            return '.'
        return foo[k-1]

    if n > 54:
        if k < n*34:
            return one[k%34-1]
        else:
            return rec(54,k-((n-54)*34))

    lo = lnn(n-1)

    if k > 34+lo+32+lo+2:
        return '.'
    if k > 34+lo+32+lo:
        return tre[k-(34+lo+32+lo)-1]
    if k > 34+lo+32:
        return rec(n-1,k-(34+lo+32))
    if k > 34+lo:
        return two[k-(34+lo)-1]
    if k > 34:
        return rec(n-1,k-(34))
    return one[k-1]

for i in range(q):
    n,k = map(int,input().split())

    print(rec(n,k),end="")