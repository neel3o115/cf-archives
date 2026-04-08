def solve():
    n, m, l = map(int, input().split())
    a = list(map(int, input().split()))

    S = [0]*(m+1)
    B = [0]*(m+1)
    pB = [0]*(m+1)

    lt = 0

    for i in range(n+1):
        if i < n:
            ct = a[i]
        else:
            ct = l

        E = ct - lt
        lt = ct

        for k in range(1, m+1):
            B[k] += E
            S[k] += E

        pB[0] = 0
        for k in range(1, m+1):
            pB[k] = pB[k-1] + B[k]
            S[k] = min(S[k], pB[k])

        if i < n:
            nS = [0]*(m+1)

            for k in range(1, m):
                tgt = S[k+1]

                lo = 0
                hi = B[1]
                ans = tgt

                while lo <= hi:
                    mid = (lo+hi)//2

                    pL = 1
                    pH = k+1
                    p = 0

                    while pL <= pH:
                        pM = (pL+pH)//2
                        if B[pM] >= mid:
                            p = pM
                            pL = pM+1
                        else:
                            pH = pM-1

                    csum = p*mid + (pB[k+1]-pB[p])

                    if csum >= tgt:
                        ans = mid
                        hi = mid-1
                    else:
                        lo = mid+1

                nS[k] = tgt - ans

            if m > 1:
                nS[m] = nS[m-1]
            else:
                nS[1] = 0

            for k in range(1, m):
                B[k] = B[k+1]
            B[m] = 0

            pB[0] = 0
            for k in range(1, m+1):
                pB[k] = pB[k-1] + B[k]

            for k in range(1, m+1):
                S[k] = nS[k]
                S[k] = min(S[k], pB[k])

    print(S[1])


def main():
    t = int(input())
    for _ in range(t):
        solve()

main()