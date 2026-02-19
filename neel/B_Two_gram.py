PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    s = input()

    freq = {}
    res = ""
    mxx = 0

    for i in range(1,n):
        freq[s[i-1:i+1]] = freq.get(s[i-1:i+1], 0)+1    
    
    for key in freq:
        if freq[key] > mxx:
            mxx = freq[key]
            res = key

    print(res)

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()