N,M = map(int, input().split())
arr = [input() for _ in range(N)]
ans = -1
for i in range(M):
    flag = True
    for j in range(N):
        if arr[j][i] == "O":
            flag = False
    if flag:
        ans = i + 1
        break
print(ans if ans != -1 else "ESCAPE FAILED")