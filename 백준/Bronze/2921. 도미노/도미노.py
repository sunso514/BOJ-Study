N = int(input())
ans = 0
for i in range(1, N+1):
    ans += 1.5*(i+1)*i
print(int(ans))