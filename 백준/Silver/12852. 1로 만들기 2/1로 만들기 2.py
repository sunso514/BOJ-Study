import dataclasses
from dataclasses import dataclass


@dataclass
class Val:
    count: int = 10000007
    parent: int = -1


N = int(input())
dp = [Val() for i in range(N + 2)]
dp[1].count = 0

for i in range(1, N + 1, 1):
    if dp[i].count + 1 < dp[i + 1].count:
        dp[i + 1].count = dp[i].count + 1
        dp[i + 1].parent = i
    if (i * 2 <= N) and (dp[i].count + 1 < dp[i * 2].count):
        dp[i * 2].count = dp[i].count + 1
        dp[i * 2].parent = i
    if (i * 3 <= N) and (dp[i].count + 1 < dp[i * 3].count):
        dp[i * 3].count = dp[i].count + 1
        dp[i * 3].parent = i

print(dp[N].count)
par = N
while(1):
    if par == -1:
        break
    print(par, end=' ')
    par = dp[par].parent
