import sys
import math
input = sys.stdin.readline

def solve():
    s = input().strip()
    n = len(s)
    ans = float('inf')

    for i in range(n):
        l = i - 1
        r = i + 1
        temp = 0
        while True:
            if l < 0 and r >= n:
                break
            if l >= 0 and r < n:
                if s[l] != s[r]:
                    temp += 1
            else:
                temp += 1
            l -= 1
            r += 1
        ans = min(ans, temp)

    for i in range(n):
        l = i
        r = i + 1
        temp = 0
        while True:
            if l < 0 and r >= n:
                break
            if l >= 0 and r < n:
                if s[l] != s[r]:
                    temp += 1
            else:
                temp += 1
            l -= 1
            r += 1
        ans = min(ans, temp)

    for i in range(n):
        l = i - 1
        r = i
        temp = 0
        while True:
            if l < 0 and r >= n:
                break
            if l >= 0 and r < n:
                if s[l] != s[r]:
                    temp += 1
            else:
                temp += 1
            l -= 1
            r += 1
        ans = min(ans, temp)

    print(ans)
    return

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
