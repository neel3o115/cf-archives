t = int(input())

ch = ['a','b','c','d','e','f','g','h','i','j','k','l','m',
      'n','o','p','q','r','s','t','u','v','w','x','y','z']

def rec(n,c,s):
    global ch
    if n == 1:
        if s == ch[c]:
            return 0
        return 1
    
    cnt0 = n//2-s[0:n//2].count(ch[c])
    cnt1 = n//2-s[n//2:n].count(ch[c])

    return min(cnt0+rec(n//2,c+1,s[n//2:n]),cnt1+rec(n//2,c+1,s[0:n//2]))

for _ in range(t):
    n = int(input())
    s = input()

    print(rec(n,0,s))