n = int(input())

res = n//2 + n//3 + n//5 + n//7
res -= n//6 + n//10 + n//14 + n//15 + n//21 + n//35
res += n//30 + n//42 + n//70 + n//105
res -= n//210

print(n - res)