N, M = map(int, input().split())
K = int(input())
if K * 2 <= N + M :
    print((N+M)-K*2)
else :
    print(N+M)