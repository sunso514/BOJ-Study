N = int(input())
A = list(input().split())
B = list(input().split())

ans = 0
for i in range(0, N):
    if (int(A[i]) <= int(B[i])):
        ans += 1
print(ans)