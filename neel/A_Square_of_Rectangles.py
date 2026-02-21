PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def ver(l1, b1, l2, b2, l3, b3):
    if (l1 == l2 == l3):
        if (l1 == (b1+b2+b3)):
            return True

    if (b1 == b2 == b3):
        if (b1 == (l1+l2+l3)):
            return True
        
    return False

def seq(l1, b1, l2, b2, l3, b3):
    if (l1 == (l2+l3)):
        if (b2==b3) and ((b2+b1) == l1):
            return True
    
    return False

def solve():
    l1, b1, l2, b2, l3, b3 = map(int, input().split())

    if ver(l1, b1, l2, b2, l3, b3):
        print('YES')
        return

    if seq(l1, b1, l2, b2, l3, b3):
        print('YES')
        return
    
    if seq(l2, b2, l3, b3, l1, b1):
        print('YES')
        return
    
    if seq(l3, b3, l1, b1, l2, b2):
        print('YES')
        return
    
    if seq(b1, l1, b2, l2, b3, l3):
        print('YES')
        return
    
    if seq(b2, l2, b3, l3, b1, l1):
        print('YES')
        return
    
    if seq(b3, l3, b1, l1, b2, l2):
        print('YES')
        return

    print('NO')

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()