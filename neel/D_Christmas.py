layer = [0]*51
patty = [0]*51

layer[0] = 1
patty[0] = 1

for i in range(1,51):
    layer[i] = 3+2*layer[i-1]
    patty[i] = 1+2*patty[i-1]

n,x = map(int,input().split())

def fun(l,x):
    return 
