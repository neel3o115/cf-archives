PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    c = a[::]
    st = []
    right = [0 for i in range(n)]

    for i in range(n-1,-1,-1):
        while (len(st) > 0 and a[i] > st[-1][0]):
            st.pop()
        if (len(st) == 0):
            right[i] = -1
        else:
            right[i] = st[-1][1]
        st.append((a[i],i))

    for i in range(q):
        op = list(input().split())
        if op[0] == '+':
            l = int(op[1])
            x = int(op[2])
            l -= 1
            temp = []

            while (l != -1 and x > 0):
                if (c[l] >= x):
                    c[l] -= x
                    break
                else:
                    x -= c[l]
                    c[l] = 0
                temp.append(l)
                l = right[l]
            # print(c)
            for i in temp:
                right[i] = l

        else:
            l = int(op[1])
            l -= 1
            print(a[l]-c[l])
        
        # print(*c)

    # print(right)
def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()