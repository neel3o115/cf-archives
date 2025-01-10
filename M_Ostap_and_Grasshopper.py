n, k = map(int, input().split())
a = input()

srt = a.index("G")
end = a.index("T")
nee = "YES"

if srt > end:
    srt, end = end, srt

for i in range(srt, end+1, k):

    if a[i] == "#":
        nee = "NO"
        break

    if srt + k > end:
        nee = "NO"
        break

    if i == end:
        if a[i] == ".":
            nee = "NO"
            break

print(nee)