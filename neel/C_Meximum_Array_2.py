PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n, k, q = map(int, input().split())
    a = [k]*n
    o1 = [0]*n
    o2 = [0]*n

    qr = []
    for _ in range(q):
        qu = list(map(int, input().split()))
        qr.append(qu)
    
    qr.sort()
    for i in qr:
        print(*i)
    
    print()



def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()