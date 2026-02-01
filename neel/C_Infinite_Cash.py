import math

PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    s = input()
    d = input()
    m = input()

    ds = int(s, 2)
    dd = int(d, 2)
    dm = int(m, 2)

    xx = dm
    nee = 1

    while xx > 0:
        xx = xx// 2

        if nee == dd:
            break

        nee += 1

    slog2 = len(bin(xx+ds))-3
    mlog2 = len(bin(dm))-3

    if mlog2+1 >= dd and slog2+1 >= dd:
        print("Infinite money!")
        return
    
    crr = dm
    day = 1

    while crr > 0:
        # print(day, ":", crr, "->" ,crr//2)
        crr = crr// 2

        if day%dd == 0:
            crr += ds

        day += 1
    
    print(bin(day-1)[2::])

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()