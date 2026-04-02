t = int(input())

for _ in range(t):
    n, k = map(int, input().split()) 
    s = bin(k)[2::]
    s = s[::-1]
    ans = 0 

    for i in range(len(s)):
        if s[i] == '1':
            ans = (ans+n**i) % 1000000007
    
    print(ans)
