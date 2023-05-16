N,M = list(map(int, input().split()))
A = [i for i in range(1,N+1)]
for _ in range(M):
    i,j,k = list(map(int, input().split()))
    A[i-1:j] = A[k-1:j] + A[i-1:k-1]

print(*A)