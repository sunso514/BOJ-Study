import sys
input = sys.stdin.readline

N = int(input())
lists = []
ans = 0

if N < 3:
    for i in range(N):
        ans += int(input())
    print(ans)
    exit()
for _ in range(N):
    lists.append(int(input()))
dp = [0 for _ in range(N)]
dp[0] = lists[0]
dp[1] = lists[1] + lists[0]
dp[2] = max(lists[0] + lists[2], lists[1] + lists[2])

for i in range(3, N):
    dp[i] = max(dp[i-3]+lists[i-1]+lists[i], dp[i-2]+lists[i])
print(dp[N-1])


