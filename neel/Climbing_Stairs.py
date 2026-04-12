import sys

t = int(sys.stdin.readline())
out = []

for _ in range(t):
    n, m = map(int, sys.stdin.readline().split())
    a = n % m
    b = n // m
    if a == 0:
        out.append(str(b))
    else:
        out.append(str(a + b))

sys.stdout.write("\n".join(out) + "\n")
