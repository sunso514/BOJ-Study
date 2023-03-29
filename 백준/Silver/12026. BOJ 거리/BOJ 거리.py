N = int(input())
dp = [1000000007] * N
dp[0] = 0
street = input()

for i in range(N-1):
    for j in range(i+1, N):
        if street[i] == 'B' and street[j] == 'O':
            dp[j] = min(dp[j], dp[i] + (j-i)**2)
        if street[i] == 'O' and street[j] == 'J':
            dp[j] = min(dp[j], dp[i] + (j-i)**2)
        if street[i] == 'J' and street[j] == 'B':
            dp[j] = min(dp[j], dp[i] + (j-i)**2)

if dp[N-1] == 1000000007:
    print(-1)
else:
    print(dp[N-1])
    