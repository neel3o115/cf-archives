n = int(input())
a = [0]*(n)
b = [i for i in range(n)]
mp = [{},{},{},{},{}]

def fun(b,par,x):
    global a, mp
    n = len(b)
    for i in range(n):
        a[b[i]] = chr(ord('a')+i%26)
        if par+chr(ord('a')+i%26) not in mp[x]:
            mp[x][par+chr(ord('a')+i%26)] = [i]
        else:
            mp[x][par+chr(ord('a')+i%26)].append(i)

fun(b,'',0)
keys = []

for key in mp[0]:
    keys.append(key)

for key in keys:
    # print(key, mp[x][key])
    if len(mp[0][key]) > 1:
        fun(mp[0][key],key,1)

for key in mp[1]:
    print(key, mp[1][key])