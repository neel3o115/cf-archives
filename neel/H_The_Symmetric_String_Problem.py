import sys
sys.setrecursionlimit(200005)

def rec(a,b,l1,r1,l2,r2):
    n = r1 - l1

    pos = True
    for i in range(n):
        if a[l1+i] != b[l2+i]:
            pos = False
            break

    if pos:
        return True

    if n % 2 == 0:
        m1 = l1+n//2
        m2 = l2+n//2

        if (rec(a,b,l1,m1,l2,m2) and rec(a,b,m1,r1,m2,r2)) or (rec(a,b,l1,m1,m2,r2) and rec(a,b,m1,r1,l2,m2)):
            return True

    return False

a = input()
b = input()

if rec(a,b,0,len(a),0,len(b)):
    print("YES")
else:
    print("NO")