board = []

for i in range(8):
    row = list(input())
    board.append(row)

row = [0]*8
col = [0]*8

d1 = {}
d2 = {}

for i in range(8):
    for j in range(8):
        d1[i+j] = 0
        d2[i-j] = 0

ans = 0
def rec(r, q):
    global ans, row, col, d1, d2
    if r == 8 and q == 8:
        ans += 1
        return

    for c in range(8):
        if (board[r][c] == "*"):
            continue
        if col[c] == 0 and d1[r+c] == 0 and d2[r-c] == 0:
            col[c] = 1
            d1[r+c] = 1
            d2[r-c] = 1

            rec(r+1, q+1)
            col[c] = 0
            d1[r+c] = 0
            d2[r-c] = 0

    return ans

print(rec(0, 0))