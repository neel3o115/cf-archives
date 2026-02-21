def rec(m,w,v,x,y,i):
    if x > m:
        return 
    
    return max(rec(m,w,v,x+w[i],y+v[i],i+1),rec(m,w,v,x,y,i+1))

n,m = map(int,input().split())

w = []
v = []

for i in range(n):
    a,b = map(int,input().split())
    w.append(a)
    v.append(b)

print(rec(m,w,v,0,0,0))