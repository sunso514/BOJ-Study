N, M = map(int, input().split())

sixmin, onemin = 1001, 1001

for i in range(M):
    a, b = map(int, input().split())
    sixmin = min(a, sixmin)
    onemin = min(b, onemin)

goal = N
ans = 0
if sixmin >= onemin*6:
    print(onemin*N)
    exit()

while goal > 0:
    if goal > 6:
        ans += sixmin
    else:
        ans += (goal*onemin if goal*onemin <= sixmin else sixmin)
    goal -= 6

print(ans)