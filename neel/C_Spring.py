import math

PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    a,b,c,m = map(int,input().split())

    ab = math.lcm(a,b)
    ac = math.lcm(a,c)
    bc = math.lcm(b,c)
    abc = math.lcm(ab,c)

    A = m//a
    B = m//b
    C = m//c

    AB = m//ab
    AC = m//ac
    BC = m//bc
    ABC = m//abc

    aa = A-AB-AC+ABC
    bb = B-AB-BC+ABC
    cc = C-AC-BC+ABC

    aabb = AB-ABC
    aacc = AC-ABC
    bbcc = BC-ABC

    alice = 6*aa+3*aabb+3*aacc+2*ABC
    bob = 6*bb+3*aabb+3*bbcc+2*ABC
    carol = 6*cc+3*aacc+3*bbcc+2*ABC

    print(alice, bob, carol)
    
def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()