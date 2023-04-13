
N = int(input())
dp = [0 for i in range(N)]
lists = [0 for i in range(N)]
for i in range(N):
    lists[i] = int(input())
dp[0] = lists[0]
if N > 1:
    dp[1] = dp[0] + lists[1]
for i in range(2, N, 1):
    dp[i] = max(max(dp[i-1], dp[i - 2] + lists[i]), dp[i-3] + lists[i-1] + lists[i])

print(dp[N-1])






