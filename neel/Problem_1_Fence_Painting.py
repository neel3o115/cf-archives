PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def main():
    fin = open("paint.in", "r")
    fout = open("paint.out", "w")

    a, b = map(int, fin.readline().split())
    c, d = map(int, fin.readline().split())

    answer = (b - a) + (d - c) - max(0, min(b, d) - max(a, c))

    fout.write(str(answer))

    fin.close()
    fout.close()

main()
