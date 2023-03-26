N = int(input())
lists = [0 for _ in range(N+1)]
for i in range(2, N+1):
    lists[i] = lists[i-1]+1
    if i % 2 == 0:
        lists[i] = min(lists[i], lists[i//2]+1)
    if i % 3 == 0:
        lists[i] = min(lists[i], lists[i//3]+1)
print(lists[N])


