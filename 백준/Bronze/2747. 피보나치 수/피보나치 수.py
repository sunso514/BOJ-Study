N = int(input())

dp = [0 for i in range(46)]
dp[0] = 0
dp[1] = 1

for i in range(2, 46, 1):
    dp[i] = dp[i-1] + dp[i-2]
    
print(dp[N])