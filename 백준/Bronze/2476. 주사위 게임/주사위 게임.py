N = int(input())
mxv = 0
for i in range(N):
    a, b, c = map(int,input().split())
    if (a==b and b==c):
        r = 10000 + a*1000
    elif (a==b or a==c):
        r = 1000 + a*100
    elif (b==c):
        r = 1000 + b*100
    else:
        r = max(a,b,c)*100
    mxv = max(mxv, r)
    
print(mxv)