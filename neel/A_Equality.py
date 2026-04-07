n, k = map(int, input().split()) 
s = input()
fr = {}

for ch in s:
    fr[ch] = fr.get(ch, 0)+1

if len(fr) < k:
    print(0)

else:
    mn = float('inf')

    for ch in s:
        mn = min(mn, fr[ch])

    print(mn*len(fr))