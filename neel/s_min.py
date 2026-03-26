n,k=map(int,input().split())
x,a,b,c=map(int,input().split())
arr=[0]*(n)
arr[0]=x
for i in range(1,n):
    arr[i]=(a*arr[i-1]+b)%c
ll=[-1]*n
s1=[]
for i in range(n):
    while s1 and arr[s1[-1]]>=arr[i]:
        s1.pop()
    if s1:
        ll[i]=s1[-1]
    else:
        ll[i]=-1
    s1.append(i)
r1=[n]*n
s2=[]
for i in range(n-1,-1,-1):
    while s2 and arr[s2[-1]]>arr[i]:
        s2.pop()
    if s2:
        r1[i]=s2[-1]
    else:
        r1[i]=n
    s2.append(i)
ans=0
for i in range(n):
    le=i-ll[i]
    ri=r1[i]-i
    # pp=max(0,min(l,k)+min(r,k)-k)
    l=max(1,k-ri+1)
    mm=max(l,k)

    pp=max(0,mm-l+1)
    if pp%2==1:
        ans=ans^arr[i]
print(ans)