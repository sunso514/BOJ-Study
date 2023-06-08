N = int(input())
C = [1,2,3]
for _ in range(N):
    x, y = map(int, input().split())  
    xt = C.index(x)
    yt = C.index(y)
    
    C[xt], C[yt] = C[yt], C[xt]
print(C[0])