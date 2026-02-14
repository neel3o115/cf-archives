PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    q = int(input())
    for i in range(q):
        s = input()
        s2i = {}
        i2s = {}

        if len(s) != n:
            print("NO")
        else:
            for j in range(n):
                if (a[j] not in i2s) and (s[j] not in s2i):
                    i2s[a[j]] = s[j]
                    s2i[s[j]] = a[j]
                elif (a[j] in i2s) and (s[j] in s2i):
                    if i2s[a[j]] == s[j] and s2i[s[j]]==a[j]:
                        continue
                    else:
                        print("NO")
                        break
                else:
                    print("NO")
                    break
            else:
                print("YES")


def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()