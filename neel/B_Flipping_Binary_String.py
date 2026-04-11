PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    s = input()

    a = s.count('1')
    b = s.count('0')
    r = []

    if a % 2 == 0:
        for i in range(n):
            if s[i] == '1':
                r.append(i+1)
        print(len(r))
        if r:
            print(*r)

    elif b % 2 == 1:
        for i in range(n):
            if s[i] == '0':
                r.append(i+1)
        print(len(r))
        if r:
            print(*r)

    else:
        print(-1)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()