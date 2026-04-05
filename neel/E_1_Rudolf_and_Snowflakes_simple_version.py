t = int(input())

kuku = set()
ukuk = set()

for i in range(2, 1000006):
    k = 4

    while ((i**(k)-1)//(i-1) <= 1000000000000000000):

        if k%2 == 0:
            kuku.add((i**(k)-1)//(i-1))
        else:
            ukuk.add((i**(k)-1)//(i-1))
        k += 1

for _ in range(t):
    n = int(input())

    if n in kuku or n in ukuk:
        print("YES")
    else:
        ans = "NO"

        D = 4*n - 3
        if D >= 0:
            D = D ** 0.5
            if (D-1)%2 == 0 and (D-1) > 0 and (D-1) != 2:
                ans = "YES"

        print(ans)