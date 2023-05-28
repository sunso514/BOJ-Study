N, M = map(int, input().split())

sixmin = 1001
onemin = 1001
for i in range(M):
    a, b = map(int, input().split())
    if a < sixmin:
        sixmin = a
    if b < onemin:
        onemin = b

goal = N
ans = 0
if sixmin >= onemin*6:
    print(onemin*N)
    exit()


while goal > 0:
    if goal > 6:
        ans += sixmin
    else:
        if goal*onemin <= sixmin:
            ans += goal*onemin
        else:
            ans += sixmin
    goal -= 6

print(ans)