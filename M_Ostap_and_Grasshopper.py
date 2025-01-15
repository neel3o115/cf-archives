n , k = map(int , input().split())

li = list(input())

l = 0
r = n-1

g = -1
t = -1


for i in range(n):
    if li[i] == "G":
        g = i
        break
    elif li[i] == "T":
        t = i
        break

ans = "NO"

for i in range(max(g,t)+k,n,k):
    if li[i] in ["G","T"]:
        ans = "YES"
    elif li[i] == "#":
        break

print(ans)