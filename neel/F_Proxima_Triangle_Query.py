import sys
import random
input = sys.stdin.readline

def ask(a,b,c):
    print(f"? {a} {b} {c}")
    sys.stdout.flush()
    x = int(input())
    if x == -1:
        exit()
    return x

def answer(a,b,c):
    print(f"! {a} {b} {c}")
    sys.stdout.flush()

t = int(input())
for _ in range(t):
    n = int(input())

    a,b,c = 1,2,3

    for _ in range(75):
        res = ask(a, b, c)

        if res == 0:
            answer(a,b,c)
            break
        else:
            choice = random.randint(1, 3)
            if choice == 1:
                a = res
            elif choice == 2:
                b = res
            else:
                c = res