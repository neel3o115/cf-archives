PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    x,y = map(int,input().split())

    if (y==0) or (x>y) or (x==0 and y%2==0):
        print("NO")
        return
    
    print("YES")
    n = x+y
    
    if x==0:
        for i in range(2,y+1):
            print(1,i)
    
    elif n%2 == 1:
        for i in range(1,2*x+1):
            print(i,i+1)
    
        for i in range(2*x+2,n+1):
            print(1,i)
    
    else:
        for i in range(1,2*x):
            print(i,i+1)
        
        for i in range(2*x+1,n+1):
            print(1,i)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()