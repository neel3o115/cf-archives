import math
t = int(input())

def isPrime(n):
    k = math.sqrt(n)

    for i in range(2,int(k)+1):
        if n%i == 0:
            return False

    return True

def fun(n, m):
    ans = n

    for i in range(2, int(math.sqrt(n))+1):
        if n%i == 0:
            k = n//i
            if k <= m:
                # return i
                ans = min(ans, i)
            
            if i <= m:
                ans = min(ans,k)

    return ans

for _ in range(t):
    n, k = map(int, input().split()) 

    if k == 1:
        print(n)
    elif k >= n:
        print(1)
    else:
        if isPrime(n):
            print(n)
        else:
            print(fun(n, k))