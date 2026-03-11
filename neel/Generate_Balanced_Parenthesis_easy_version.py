import sys
sys.setrecursionlimit = 10000000

n = int(input())
ans = []
nee = 0

def fun(cr, op, rm):
    global ans
    if rm == 0:
        if op == 0:
            ans.append(cr)
        return

    if op == 0: 
        fun(cr+'(', op+1, rm-1)

    else:
        fun(cr+')', op-1, rm-1)
        fun(cr+'(', op+1, rm-1)

fun("", 0, n)
ans.sort()

for i in ans:
    print(i)
