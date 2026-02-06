n,m = map(int,input().split())
a = list(map(int, input().split()))
a.sort()

pi = 1

for i in range(1,n):
    for j in range(i):
        pi *= (a[i]-a[j])
        pi %= m
    
    if pi == 0:
        break

print(pi)