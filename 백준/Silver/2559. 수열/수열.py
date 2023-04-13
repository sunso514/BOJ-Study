import sys
input = sys.stdin.readline

N, M = map(int, input().split())
lists = list(map(int, input().split()))
ans = []
ans.append(sum(lists[:M]))
for i in range(N - M):
    ans.append(ans[i] - lists[i] + lists[M+i])
print(max(ans))


