N, M = map(int, input().split())

lists = [i+1 for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    time = (abs(b-a) +1)// 2
    if (time//2) == 0:
        time = 1
    for j in range(time):
        tmp = lists[a+j-1]
        lists[a+j-1] = lists[b-j-1]
        lists[b-j-1] = tmp
for i in range(N):
    print(lists[i], end = ' ')
